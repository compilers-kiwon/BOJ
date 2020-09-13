#include	<iostream>
#include	<queue>
 
using namespace	std;
 
#define	MAX_SIZE			(2000+1)
#define	MAX_CIVILIZATION	(100000+1)
#define	NONE				0
 
#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4
 
const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};
 
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
 
typedef	pair<int,int>	Pos;	// first:row, second:col
 
int	N,K,grid[MAX_SIZE][MAX_SIZE];
int	parent[MAX_CIVILIZATION];
 
int		find_parent_civilization(int c)
{
	int&	ret = parent[c];
	
	if( ret != c )
	{
		ret = find_parent_civilization(ret);
	}
	
	return	ret;
}

bool	get_adj_pos(const int& current_row,const int& current_col,
					int& adj_row,int& adj_col,const int& direction)
{
	adj_row = current_row+adj[direction].d_row;
	adj_col = current_col+adj[direction].d_col;
	
	if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,N) )
	{
		return	false;
	}
	
	return	true;
}

bool	merge_civilization(int current_row,int current_col,int adj_row,int adj_col)
{
	int	current_civilization,adj_civilization;
	
	current_civilization = find_parent_civilization(grid[current_row][current_col]);
	adj_civilization = find_parent_civilization(grid[adj_row][adj_col]);
	
	if( adj_civilization==NONE || current_civilization==adj_civilization )
	{
		return	false;
	}
	
	int	big,small;
				
	big = max(current_civilization,adj_civilization);
	small = min(current_civilization,adj_civilization);
	parent[big] = small;
	
	return	true;
}

int		simulate(queue<Pos>& pos_q)
{
	int	t;
	
	for(t=0;K!=1;t++)
	{
		queue<Pos>	spread;
		
		for(int i=1,size=pos_q.size();i<=size;i++)
		{
			int	current_row,current_col;
			
			current_row = pos_q.front().first;
			current_col = pos_q.front().second;
						
			pos_q.pop();
			
			for(int d=UP;d<=RIGHT;d++)
			{
				int	adj_row,adj_col;
				int	current_civilization;
				 
				if( get_adj_pos(current_row,current_col,adj_row,adj_col,d) == false )
				{
					continue;
				}
				
				current_civilization = find_parent_civilization(grid[current_row][current_col]);
				
				if( grid[adj_row][adj_col] == NONE )
				{
					grid[adj_row][adj_col] = current_civilization;
					spread.push(make_pair(adj_row,adj_col));
					pos_q.push(make_pair(adj_row,adj_col));
				}
			}
		}
		
		for(;!spread.empty();)
		{
			int	current_row,current_col;
			
			current_row = spread.front().first;
			current_col = spread.front().second;
			
			spread.pop();
			
			for(int d=UP;d<=RIGHT;d++)
			{
				int	adj_row,adj_col;
				
				if( get_adj_pos(current_row,current_col,adj_row,adj_col,d) == false )
				{
					continue;
				}
				
				if( merge_civilization(current_row,current_col,adj_row,adj_col) == true )
				{
					K--;
				}
			}
		}
	}
	
	return	t;	
}
 
void	input(queue<Pos>& pos_q)
{
	cin>>N>>K;
	
	for(int i=1;i<=K;i++)
	{
		int	row,col;
 
		cin>>col>>row;
		pos_q.push(make_pair(row,col));
		grid[row][col] = parent[i] = i;
	}
	
	for(int i=1,size=pos_q.size();i<=size;i++)
	{
		int	current_row,current_col;
		
		current_row = pos_q.front().first;
		current_col = pos_q.front().second;
		
		pos_q.pop();
		pos_q.push(make_pair(current_row,current_col));
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			if( get_adj_pos(current_row,current_col,adj_row,adj_col,d) == false )
			{
				continue;
			}
			
			if( merge_civilization(current_row,current_col,adj_row,adj_col) == true )
			{
				K--;
			}
		}
	}
}
 
int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	queue<Pos>	pos_q;
	
	input(pos_q);
	cout<<simulate(pos_q)<<'\n';
	
	return	0;
}
