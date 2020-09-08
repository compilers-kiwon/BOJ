#include	<iostream>

using namespace	std;

#define	MAX_SIZE	15

int	dp[MAX_SIZE][MAX_SIZE];

int	get_num_of_path(int row,int col)
{
	if( dp[row][col] != -1 )
	{
		return	dp[row][col];
	}
	
	dp[row][col] = get_num_of_path(row-1,col)+get_num_of_path(row,col-1);
	
	return	dp[row][col];
}

int	main(void)
{
	int	N,M,K;
	int	stopover_row,stopover_col;
	
	cin>>N>>M>>K;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			dp[i][j] = -1;
		}
	}
	
	if( K == 0 )
	{
		for(int i=1;i<=N;i++)
		{
			dp[i][1] = 1;
		}
	
		for(int j=1;j<=M;j++)
		{
			dp[1][j] = 1;
		}
		
		cout<<get_num_of_path(N,M)<<endl;
		
		return	0;
	}
		
	stopover_row = K/M+1;
	stopover_col = K%M;
	
	if( stopover_col == 0 )
	{
		stopover_row--;
		stopover_col = M;
	}
	
	for(int i=1;i<=stopover_row;i++)
	{
		dp[i][1] = 1;
	}
	
	for(int j=1;j<=stopover_col;j++)
	{
		dp[1][j] = 1;
	}
	
	int	num_of_path_to_stopover = get_num_of_path(stopover_row,stopover_col);
	
	for(int i=stopover_col+1;i<=M;i++)
	{
		dp[stopover_row][i] = num_of_path_to_stopover;
	}
	
	for(int j=stopover_row+1;j<=N;j++)
	{
		dp[j][stopover_col] = num_of_path_to_stopover;
	}
	
	int	num_of_path_to_final = get_num_of_path(N,M);
	
	cout<<num_of_path_to_final<<endl;
	
	return	0;
}
