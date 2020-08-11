#include	<iostream>
#include	<queue>
#include	<map>

using namespace	std;

#define	MAX_ROW		3
#define	MAX_COL		3
#define	MAX_SIZE	(MAX_ROW*MAX_COL)
#define	SHIFT_SIZE	4
#define	MASK_VALUE	0x000000000000000F
#define	FINAL_STATE	0x0000000123456780
#define	NONE		0

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	unsigned long long	uint64;
typedef	pair<int,uint64>	State;	// first:-num_of_moves,second:grid

uint64	get_state(uint64 grid[][MAX_COL+1])
{
	uint64	ret;
	
	ret = 0;
	
	for(int row=1;row<=MAX_ROW;row++)
	{
		for(int col=1;col<=MAX_COL;col++)
		{
			ret = (ret<<SHIFT_SIZE)
							|(grid[row][col]&MASK_VALUE);
		}
	}
	
	return	ret;
}

uint64	input(void)
{
	uint64	grid[MAX_ROW+1][MAX_COL+1];
	
	for(int row=1;row<=MAX_ROW;row++)
	{
		for(int col=1;col<=MAX_COL;col++)
		{
			cin>>grid[row][col];
		}
	}
	
	return	get_state(grid);
}

void	build_grid(uint64 state,uint64 grid[][MAX_COL+1],
				   int& empty_row,int& empty_col)
{
	for(int row=MAX_ROW;row>=1;row--)
	{
		for(int col=MAX_COL;col>=1;col--)
		{
			grid[row][col] = state&MASK_VALUE;
			state >>= SHIFT_SIZE;
			
			if( grid[row][col] == 0 )
			{
				empty_row = row;
				empty_col = col;
			}
		}
	}
}

int		get_min_num_of_operations(uint64& s)
{
	map<uint64,int>			dp;
	priority_queue<State>	pq;
	
	dp[s] = 1;
	pq.push(make_pair(-1,s));
	
	for(;!pq.empty();)
	{
		int		current_num_of_operations,e_row,e_col;
		uint64	current_state,grid[MAX_ROW+1][MAX_COL+1];
		
		current_num_of_operations = -pq.top().first;
		current_state = pq.top().second;
		
		pq.pop();
		
		if( current_state == FINAL_STATE )
		{
			return	current_num_of_operations-1;
		}
		
		build_grid(current_state,grid,e_row,e_col);
		
		for(int d=UP;d<MAX_DIR;d++)
		{
			int		adj_row,adj_col,adj_num_of_operations;
			uint64	adj_state;
			
			adj_row = e_row+adj[d].d_row;
			adj_col = e_col+adj[d].d_col;
			
			if( !IN_RANGE(1,adj_row,MAX_ROW) || !IN_RANGE(1,adj_col,MAX_COL) )
			{
				continue;
			}
			
			swap(grid[adj_row][adj_col],grid[e_row][e_col]);
			
			adj_state = get_state(grid);
			adj_num_of_operations = current_num_of_operations+1;
			
			if( dp[adj_state]==NONE || dp[adj_state]>adj_num_of_operations )
			{
				dp[adj_state] = adj_num_of_operations;
				pq.push(make_pair(-adj_num_of_operations,adj_state));
			}
			
			swap(grid[adj_row][adj_col],grid[e_row][e_col]);
		}
	}
	
	return	-1;
}

int		main(void)
{
	uint64	initial_state;
	
	initial_state = input();
	cout<<get_min_num_of_operations(initial_state)<<'\n';
	
	return	0;
}
