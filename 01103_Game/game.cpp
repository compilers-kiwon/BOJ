#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(50+1)

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	char2int(c)	((int)((c)-'0'))
#define	EXIT		'H'

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const	struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int		N,M,dp[MAX_SIZE][MAX_SIZE];
char	board[MAX_SIZE][MAX_SIZE+1];
bool	visited[MAX_SIZE][MAX_SIZE];

bool	dfs(int current_row,int current_col,int current_num_of_movements,int& max_num_of_movements)
{
	if( board[current_row][current_col]==EXIT || !IN_RANGE(1,current_row,N) || !IN_RANGE(1,current_col,M) )
	{
		max_num_of_movements = max(max_num_of_movements,current_num_of_movements);
		return	false;
	}
	
	if( visited[current_row][current_col] == true )
	{
		return	true;
	}
	
	if( current_num_of_movements <= dp[current_row][current_col] )
	{
		return	false;
	}
	
	dp[current_row][current_col] = current_num_of_movements;
	visited[current_row][current_col] = true;
	
	for(int d=UP,move=char2int(board[current_row][current_col]);d<=RIGHT;d++)
	{
		int		adj_row,adj_col;
		bool	result;
		
		adj_row = current_row+adj[d].d_row*move;
		adj_col = current_col+adj[d].d_col*move;
		
		result = dfs(adj_row,adj_col,current_num_of_movements+1,max_num_of_movements);
		
		if( result == true )
		{
			return	true;
		}
	}
	
	visited[current_row][current_col] = false;
	
	return	false;
}

int		main(void)
{
	scanf("%d %d",&N,&M);
	
	for(int row=1;row<=N;row++)
	{
		scanf("%s",&board[row][1]);
	}
	
	int	max_num_of_movements = 0;
	
	dp[1][1] = -1;
	
	if( dfs(1,1,0,max_num_of_movements) == true )
	{
		puts("-1");
	}
	else
	{
		printf("%d\n",max_num_of_movements);
	}
	
	return	0;
}
