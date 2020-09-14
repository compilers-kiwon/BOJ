#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(50+1)
#define	MOD(n)		((n)%1000000007)

int	dp[MAX_SIZE];

int	fibo(int n)
{
	int&	ret = dp[n];
	
	if( dp[n] != 0 )
	{
		return	ret;
	}
	
	ret = MOD(fibo(n-2)+fibo(n-1)+1);
	
	return	ret;
}

int	main(void)
{
	int	N;
	
	cin>>N;
	dp[0] = dp[1] = 1;
	
	cout<<fibo(N)<<'\n';
	
	return	0;
}
