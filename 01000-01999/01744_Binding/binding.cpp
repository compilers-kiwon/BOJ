#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(10000+1)

typedef	long long int	int64;

int64	dp[2][MAX_SIZE];
int64	seq[MAX_SIZE];

void	build_dp(int& num_of_numbers)
{
	dp[0][0] = dp[1][0] = 0;
	dp[0][1] = dp[1][1] = seq[1];
	
	for(int i=2;i<=num_of_numbers;i++)
	{
		dp[0][i] = max(dp[0][i-1],dp[1][i-1])+seq[i];
		dp[1][i] = max(dp[0][i-2],dp[1][i-2])+(seq[i-1]*seq[i]);
	}
}

int		main(void)
{
	int64	result;
	int		N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>seq[i];
	}
	
	if( N == 0 )
	{
		result = 0;
	}
	else if( N == 1 )
	{
		result = seq[1];
	}
	else if( N == 2 )
	{
		result = max(seq[1]*seq[2],seq[1]+seq[2]);
	}
	else
	{
		sort(&seq[1],&seq[N+1]);
		build_dp(N);
		result = max(dp[0][N],dp[1][N]);
	}
	
	cout<<result<<endl;
	
	return	0;
}
