#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE			(500+1)
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
#define	MAX_DIR				4
#define	char2int(c)			((int)((c)-'0'))

#define	START_ROW	1
#define	START_COL	1

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

typedef	pair<int,int>	Pos;
typedef	pair<int,Pos>	State;

int		n,m,dp[MAX_SIZE][MAX_SIZE];
char	grid[MAX_SIZE][MAX_SIZE+1];

int		get_min_num_of_moves(void)
{
	for(int row=1;row<=n;row++)
	{
		for(int col=1;col<=m;col++)
		{
			dp[row][col] = MAX_SIZE*MAX_SIZE;
		}
	}
	
	priority_queue<State>	pq;
	
	pq.push(make_pair(0,make_pair(START_ROW,START_COL)));
	dp[START_ROW][START_COL] = 0;
	
	for(;!pq.empty();)
	{
		int	current_num_of_moves,current_row,current_col,jump;
		int	adj_row,adj_col,adj_num_of_moves;
			
		current_num_of_moves = -pq.top().first;
		current_row = pq.top().second.first;
		current_col = pq.top().second.second;
		
		pq.pop();
		
		if( current_row==n && current_col==m )
		{
			break;
		}
		
		jump = char2int(grid[current_row][current_col]);
		adj_num_of_moves = current_num_of_moves+1;
		
		for(int d=0;d<MAX_DIR;d++)
		{
			adj_row = current_row+adj[d].d_row*jump;
			adj_col = current_col+adj[d].d_col*jump;
			
			if( IN_RANGE(1,adj_row,n) && IN_RANGE(1,adj_col,m) )
			{
				if( adj_num_of_moves < dp[adj_row][adj_col] )
				{
					dp[adj_row][adj_col] = adj_num_of_moves;
					pq.push(make_pair(-adj_num_of_moves,make_pair(adj_row,adj_col)));
				}
			}
		}
	}
	
	return	dp[n][m];
}

int		main(void)
{
	scanf("%d %d",&n,&m);
	
	for(int row=1;row<=n;row++)
	{
		scanf("%s",&grid[row][1]);
	}
	
	int	result;
	
	result = get_min_num_of_moves();
	
	if( result == MAX_SIZE*MAX_SIZE )
	{
		puts("IMPOSSIBLE");
	}
	else
	{
		printf("%d\n",result);
	}
	
	return	0;
}
