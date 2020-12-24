#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(25+1)
#define	TBD			-1

int	N,t[MAX_SIZE],dp[MAX_SIZE];

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	a,b;
		
		cin>>a>>b>>t[i];
		dp[i] = TBD;
	}
}

int		get_dp(int n)
{
	if( n <= 0 )
	{
		return	0;
	}
	
	int&	ret = dp[n];
	
	if( ret != TBD )
	{
		return	ret;
	}
	
	ret = max(get_dp(n-1),get_dp(n-2)+t[n]);
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<get_dp(N)<<'\n';
	
	return	0;
}
