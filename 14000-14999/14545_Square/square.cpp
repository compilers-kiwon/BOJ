#include	<iostream>

using namespace	std;

#define	MAX_LEN	1000000

typedef	long long int	int64;

int64	dp[MAX_LEN+1];

int64	get_dp(int l)
{
	int64&	ret = dp[l];
	
	if( ret != 0 )
	{
		return	ret;
	}
	
	ret = get_dp(l-1)+l*l;
	
	return	ret;
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	int	P;
	
	cin>>P;
	dp[1] = 1;
	
	for(int i=1;i<=P;i++)
	{
		int	l;
		
		cin>>l;
		cout<<get_dp(l)<<'\n';
	}
	
	return	0;
}
