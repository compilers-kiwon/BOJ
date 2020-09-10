#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1000+1)

int	maze[MAX_SIZE],dp[MAX_SIZE];

int	main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>maze[i];
		dp[i] = 1001;
	}
	
	dp[1] = 0;
	
	for(int i=1;i<N;i++)
	{
		int	next;
		
		next = i+maze[i];
		
		for(int j=i+1;j<=next;j++)
		{
			dp[j] = min(dp[j],dp[i]+1);
		}
	}
	
	if( dp[N] == 1001 )
	{
		dp[N] = -1;
	}
	cout<<dp[N]<<endl;
	
	return	0;
}
