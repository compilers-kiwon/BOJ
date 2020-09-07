#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(500+1)
#define	INF			0x7FFFFFFF

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
typedef	pair<int,Pos>	State;	// first:distnace_from_tree, second:Pos

int	R,C,dp[MAX_SIZE][MAX_SIZE];
int	grid[MAX_SIZE][MAX_SIZE];
Pos	wolf,shelter;

void	input(queue<Pos>& tree)
{
	cin>>R>>C;
	
	for(int row=1;row<=R;row++)
	{
		char	buf[MAX_SIZE+1];
		
		cin>>&buf[1];
		
		for(int col=1;col<=C;col++)
		{
			char&	c = buf[col];
						
			switch(c)
			{
				case	'V':
					wolf = make_pair(row,col);
					grid[row][col] = INF;
					break;
				case	'J':
					shelter = make_pair(row,col);
					grid[row][col] = INF;
					break;
				case	'+':
					tree.push(make_pair(row,col));
					grid[row][col] = 0;
					break;
				default:
					grid[row][col] = INF;
					break;
			}
			
			dp[row][col] = -1;
		}
	}
}

void	get_distance_from_tree(queue<Pos>& tree)
{
	for(;!tree.empty();)
	{
		int	current_row,current_col,current_distance;
		
		current_row = tree.front().first;
		current_col = tree.front().second;
		current_distance = grid[current_row][current_col];
		
		tree.pop();
		
		for(int d=UP;d<MAX_DIR;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( IN_RANGE(1,adj_row,R) && IN_RANGE(1,adj_col,C) )
			{
				if( grid[adj_row][adj_col] == INF )
				{
					grid[adj_row][adj_col] = current_distance+1;
					tree.push(make_pair(adj_row,adj_col));
				}
			}
		}
	}
}

int		get_safe_path(void)
{
	priority_queue<State>	pq;
	
	dp[wolf.first][wolf.second] = grid[wolf.first][wolf.second];
	pq.push(make_pair(grid[wolf.first][wolf.second],wolf));
	
	for(;!pq.empty();)
	{
		int	current_row,current_col,current_min_distance;
		
		current_min_distance = pq.top().first;
		current_row = pq.top().second.first;
		current_col = pq.top().second.second;
		
		pq.pop();
		
		if( current_row==shelter.first && current_col==shelter.second )
		{
			break;
		}
		
		for(int d=UP;d<MAX_DIR;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( IN_RANGE(1,adj_row,R) && IN_RANGE(1,adj_col,C) )
			{
				if( dp[adj_row][adj_col] == -1 )
				{
					dp[adj_row][adj_col] = min(current_min_distance,grid[adj_row][adj_col]);
					pq.push(make_pair(dp[adj_row][adj_col],make_pair(adj_row,adj_col)));
				}
			}
		}
	}
	
	return	dp[shelter.first][shelter.second];
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	queue<Pos>	tree;
	
	input(tree);
	get_distance_from_tree(tree);
	
	cout<<get_safe_path()<<'\n';
	
	return	0;
}
