#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	MOD_VAL		1000000007

typedef	long long int	int64;

int64	dp[MAX_SIZE][MAX_SIZE];

int64	get_dp(int row,int col)
{
	int64&	ret = dp[row][col];
	
	if( ret != -1 )
	{
		return	ret;
	}
	
	ret = get_dp(row-1,col)+get_dp(row,col-1)+get_dp(row-1,col-1);
	ret %= MOD_VAL;
	
	return	ret;
}

int		main(void)
{
	int	n,m;
	
	cin>>n>>m;
	
	for(int row=1;row<=n;row++)
	{
		for(int col=1;col<=m;col++)
		{
			dp[row][col] = -1;
		}
	}
	
	for(int row=1;row<=n;row++)
	{
		dp[row][1] = 1;
	}
	
	for(int col=1;col<=m;col++)
	{
		dp[1][col] = 1;
	}
	
	cout<<get_dp(n,m)<<endl;
	
	return	0;
}
