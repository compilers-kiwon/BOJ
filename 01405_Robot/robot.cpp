#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_MOVE	14

#define	EAST	0
#define	WEST	1
#define	SOUTH	2
#define	NORTH	3
#define	MAX_DIR	4

bool	visited[MAX_NUM_OF_MOVE*2+1][MAX_NUM_OF_MOVE*2+1];	
double	probability[MAX_DIR];
int		N;

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{0,1},{0,-1},{1,0},{-1,0}};

double	dfs(int current_row,int current_col,int num_of_move)
{
	if( num_of_move == 0 )
	{
		return 1.0;
	}
	
	visited[current_row][current_col] = true;
	
	double	result;
	
	result = 0.0;
	
	for(int i=EAST;i<=NORTH;i++)
	{
		if( probability[i] == 0.0 )
		{
			continue;
		}
		
		int	adj_row,adj_col;
		
		adj_row = current_row+adj[i].d_row;
		adj_col = current_col+adj[i].d_col;
		
		if( visited[adj_row][adj_col] == false )
		{
			result += dfs(adj_row,adj_col,num_of_move-1)*probability[i];
		}
	}
	
	visited[current_row][current_col] = false;

	return	result;
}

int		main(void)
{
	cin>>N;
	
	for(int i=EAST;i<=NORTH;i++)
	{
		cin>>probability[i];
		probability[i] /= 100.0;
	}
	
	double	sum;
	
	sum = dfs(MAX_NUM_OF_MOVE,MAX_NUM_OF_MOVE,N);

	cout<<sum<<'\n';
	
	return	0;
}
