#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

typedef	pair<int,int>	Ice;

#define	MAX_LEN	(300+1)

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	WATER	0

const	struct
{
	int	row,col;
} adj_dir[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int	ice_map[MAX_LEN][MAX_LEN];
int	cnt_of_adj_water[MAX_LEN][MAX_LEN];
int	visited[MAX_LEN][MAX_LEN];

void	mark_visited(int row,int col)
{
	visited[row][col] = true;
	
	for(int i=UP;i<=RIGHT;i++)
	{
		int	adj_row,adj_col;
		
		adj_row = row+adj_dir[i].row;
		adj_col = col+adj_dir[i].col;
		
		if( ice_map[adj_row][adj_col] != WATER && visited[adj_row][adj_col] != true )
		{
			mark_visited(adj_row,adj_col);
		} 
	}
}

int		count_ice_mass(int row_len,int col_len,queue<Ice>& ice_q)
{
	int	current_num_of_ice,num_of_mass;
	
	for(int row=1;row<=row_len;row++)
	{
		for(int col=1;col<=col_len;col++)
		{
			visited[row][col] = false;
		}
	}
	
	current_num_of_ice = ice_q.size();
	num_of_mass = 0;
	
	for(int i=1;i<=current_num_of_ice;i++)
	{
		Ice	current_ice;
		
		current_ice = ice_q.front();
		ice_q.pop();
		ice_q.push(current_ice);
		
		if( visited[current_ice.first][current_ice.second] == false )
		{
			num_of_mass++;
			mark_visited(current_ice.first,current_ice.second);
		}
	}
	
	return	num_of_mass;
}

int		count_adj_water(int row,int col)
{
	int	num_of_water,i;
	
	for(num_of_water=0,i=UP;i<=RIGHT;i++)
	{
		int	adj_row,adj_col;
		
		adj_row = row+adj_dir[i].row;
		adj_col = col+adj_dir[i].col;
		
		if( ice_map[adj_row][adj_col] == WATER )
		{
			num_of_water++;
		}
	}
	
	return	num_of_water;
}

int		find_min_year(int row_len,int col_len,queue<Ice>& ice_q)
{
	int	current_year,current_num_of_ice;
	
	for(current_year=0;(current_num_of_ice=ice_q.size())!=0;current_year++)
	{
		if( count_ice_mass(row_len,col_len,ice_q) >= 2 )
		{
			return	current_year;
		}
		
		vector<Ice>	will_melt;
		
		for(int i=1;i<=current_num_of_ice;i++)
		{
			int	current_ice_row,current_ice_col;
			
			current_ice_row = ice_q.front().first;
			current_ice_col = ice_q.front().second;
			ice_q.pop();
			
			int	num_of_adj_water;
			
			num_of_adj_water = count_adj_water(current_ice_row,current_ice_col);
			
			if( num_of_adj_water > 0 )
			{
				will_melt.push_back(make_pair(current_ice_row,current_ice_col));
				cnt_of_adj_water[current_ice_row][current_ice_col] = num_of_adj_water;
			}
			else
			{
				ice_q.push(make_pair(current_ice_row,current_ice_col));
			}
		}
		
		for(int i=0;i<will_melt.size();i++)
		{
			int&	row = will_melt[i].first;
			int&	col = will_melt[i].second;
			
			ice_map[row][col] = max(ice_map[row][col]-cnt_of_adj_water[row][col],0);
			
			if( ice_map[row][col] > 0 )
			{
				ice_q.push(make_pair(row,col));
			}
		}
	}
	return	0;
}

int		main(void)
{
	int			N,M;
	queue<Ice>	ice_q;
	
	cin>>N>>M;

	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			cin>>ice_map[row][col];
			
			if( ice_map[row][col] != WATER )
			{
				ice_q.push(make_pair(row,col));
			}
		}
	}
	
	cout<<find_min_year(N,M,ice_q)<<endl;
	
	return	0;	
}
