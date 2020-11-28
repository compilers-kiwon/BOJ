#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(5000+1)

int	N,hungry[MAX_SIZE],dp[MAX_SIZE];

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>hungry[i];
	}
}

int		get_max_dp(int current)
{
	int	ret;
	
	ret = 0;
	
	for(int i=1;i<current;i++)
	{
		if( hungry[i] < hungry[current] )
		{
			ret = max(ret,dp[i]);
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	answer;
	
	input();
	answer = 0;
	
	for(int i=1;i<=N;i++)
	{
		dp[i] = get_max_dp(i)+1;
		answer = max(answer,dp[i]);
	}
	
	cout<<answer<<'\n';
	
	return	0;
}
