#include	<iostream>
#include	<cmath>

using namespace	std;

#define	MAX_SIZE	(2000+1)

typedef	long long int	int64;

int		n,m;
int64	dp[MAX_SIZE][MAX_SIZE];

int64	get_dp(int n,int idx)
{
	if( idx == 1 )
	{
		return	1;
	}
	
	int64&	ret = dp[n][idx];
	int		to;
	
	if( ret != -1 )
	{
		return	ret;
	}
	
	ret = 0;
	to = pow(2,idx-2);
	
	for(int i=n/2;i>=to;i--)
	{
		ret += get_dp(i,idx-1);
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(;T>0;T--)
	{
		int		n,m,to;
		int64	sum;
		
		cin>>n>>m;

		for(int row=1;row<=m;row++)
		{
			for(int col=2;col<=n;col++)
			{
				dp[row][col] = -1;
			}
		}
		
		sum = 0;
		to = pow(2,n-1);
		
		for(int i=m;i>=to;i--)
		{
			sum += get_dp(i,n);
		}
		
		cout<<sum<<'\n';
	}
	
	return	0;
}
