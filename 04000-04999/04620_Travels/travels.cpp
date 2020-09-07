#include	<iostream>

using namespace	std;

typedef	long long int	int64;

#define	MAX_SIZE	(34+1)

int		n,grid[MAX_SIZE][MAX_SIZE];
int64	dp[MAX_SIZE][MAX_SIZE];

bool	init(void)
{
	scanf("%d",&n);
	
	if( n == -1 )
	{
		return	false;
	}
	
	for(int row=1;row<=n;row++)
	{
		for(int col=1;col<=n;col++)
		{
			scanf("%1d",&grid[row][col]);
			dp[row][col] = -1;
		}
	}
	
	dp[1][1] = 1;
	
	return	true;
}

int64	get_dp(int row,int col)
{
	int64&	ret = dp[row][col];
	
	if( ret != -1 )
	{
		return	ret;
	}
	
	ret = 0;
	
	for(int adj_row=row-1;adj_row>=1;adj_row--)
	{
		if( (row-adj_row) == grid[adj_row][col] )
		{
			ret += get_dp(adj_row,col);
		}
	}
	
	for(int adj_col=col-1;adj_col>=1;adj_col--)
	{
		if( (col-adj_col) == grid[row][adj_col] )
		{
			ret += get_dp(row,adj_col);
		}
	}
	
	return	ret;
}

int		main(void)
{
	for(;;)
	{
		if( init() == false )
		{
			break;
		}
		
		printf("%lld\n",get_dp(n,n));
	}
	
	return	0;
}
