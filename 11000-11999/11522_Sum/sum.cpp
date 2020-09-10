#include	<iostream>

using namespace	std;

#define	MAX_LEN	(10000+1)

int	odd_dp[MAX_LEN],even_dp[MAX_LEN];

int	get_sum_of_positive_integers(int N)
{
	return	N*(N+1)/2;
}

int	get_sum_of_odd_integers(int N)
{
	int&	ret = odd_dp[N];
	
	if( ret != 0 )
	{
		return	ret;
	}
	
	ret = get_sum_of_odd_integers(N-1)+(2*N-1);
	
	return	ret;
}

int	get_sum_of_even_integers(int N)
{
	int&	ret = even_dp[N];
	
	if( ret != 0 )
	{
		return	ret;
	}
	
	ret = get_sum_of_even_integers(N-1)+(2*N);
	
	return	ret;
}

int	main(void)
{
	int	P,N,K;
	
	cin.sync_with_stdio(false);
	
	cin>>P;
	
	odd_dp[1] = 1;
	even_dp[1] = 2;
	
	for(int i=1;i<=P;i++)
	{
		cin>>K>>N;
		cout<<K<<' '<<get_sum_of_positive_integers(N)<<' '<<get_sum_of_odd_integers(N)<<' '<<get_sum_of_even_integers(N)<<'\n';
	}
	
	return	0;
}
