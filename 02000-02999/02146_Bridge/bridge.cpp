#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(100+1)

#define	LAND	1
#define	SEA		0

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,N,MAX)	((MIN)<=(N)&&(N)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

typedef	struct	_BRIDGE_INFO	Bridge;
struct	_BRIDGE_INFO
{
	int	row,col,from;
};

typedef	pair<int,int>	Land;

int	map[MAX_SIZE][MAX_SIZE],expanded[MAX_SIZE][MAX_SIZE];

void	mark_land(int s_row,int s_col,int mark,int map_size)
{
	queue<Land>	land_q;
	
	map[s_row][s_col] = mark;
	land_q.push(make_pair(s_row,s_col));
	
	while( !land_q.empty() )
	{
		int	current_row,current_col;
		
		current_row = land_q.front().first;
		current_col = land_q.front().second;
		
		land_q.pop();
		
		for(int i=UP;i<=RIGHT;i++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[i].d_row;
			adj_col = current_col+adj[i].d_col;
			
			if( IN_RANGE(1,adj_row,map_size) && IN_RANGE(1,adj_col,map_size) && map[adj_row][adj_col] == LAND )
			{
				map[adj_row][adj_col] = mark;
				land_q.push(make_pair(adj_row,adj_col));
			}
		}
	}
}

void	count_land(int map_size)
{
	int	land_cnt;
	
	land_cnt = 2;
	
	for(int i=1;i<=map_size;i++)
	{
		for(int j=1;j<=map_size;j++)
		{
			if( map[i][j] == LAND )
			{
				mark_land(i,j,land_cnt++,map_size);
			}
		}
	}
}

void	init(int& map_size)
{
	cin.sync_with_stdio(false);
	
	cin>>map_size;
	
	for(int row=1;row<=map_size;row++)
	{
		for(int col=1;col<=map_size;col++)
		{
			cin>>map[row][col];
		}
	}
}

void	find_bridge_candidate(queue<Bridge>& b,int map_size)
{
	for(int row=1;row<=map_size;row++)
	{
		for(int col=1;col<=map_size;col++)
		{
			if( map[row][col] != SEA )
			{
				for(int k=UP;k<=RIGHT;k++)
				{
					int	adj_row,adj_col;
			
					adj_row = row+adj[k].d_row;
					adj_col = col+adj[k].d_col;
					
					if( IN_RANGE(1,adj_row,map_size) && IN_RANGE(1,adj_col,map_size) && map[adj_row][adj_col] == SEA )
					{
						Bridge	tmp;
						
						tmp.row = row;
						tmp.col = col;
						tmp.from = map[row][col];
						
						b.push(tmp);
						
						break;
					}
				}
			}
		}
	}
}

int		build_bridge(queue<Bridge>& b,int map_size)
{
	int	min_bridge_len;
	
	min_bridge_len = 0x7FFFFFFF;
	
	while( !b.empty() )
	{
		int	current_bridge_row,current_bridge_col,current_bridge_length,current_bridge_land;
		
		current_bridge_row = b.front().row;
		current_bridge_col = b.front().col;
		current_bridge_length = expanded[current_bridge_row][current_bridge_col];
		current_bridge_land = b.front().from;
		
		b.pop();
		
		for(int i=UP;i<=RIGHT;i++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_bridge_row+adj[i].d_row;
			adj_col = current_bridge_col+adj[i].d_col;
			
			if( IN_RANGE(1,adj_row,map_size) && IN_RANGE(1,adj_col,map_size) )
			{
				if( map[adj_row][adj_col] == SEA )
				{
					Bridge	tmp;
						
					tmp.row = adj_row;
					tmp.col = adj_col;
					tmp.from = current_bridge_land;
					
					b.push(tmp);
					
					expanded[adj_row][adj_col] = current_bridge_length+1;
					map[adj_row][adj_col] = current_bridge_land;
				}
				else
				{
					if( map[adj_row][adj_col] != current_bridge_land )
					{
						min_bridge_len = min(min_bridge_len,current_bridge_length+expanded[adj_row][adj_col]);
					}
				}
			}
		}
	}
	
	return	min_bridge_len;
}

int		main(void)
{
	int	N;
	
	init(N);
	count_land(N);
	
	queue<Bridge>	bridge_queue;
	
	find_bridge_candidate(bridge_queue,N);
	cout<<build_bridge(bridge_queue,N)<<'\n';

	return	0;
}
