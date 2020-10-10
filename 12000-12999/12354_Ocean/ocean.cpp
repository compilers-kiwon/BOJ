#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1000+1)

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int	N,max_dp;
		int	h[MAX_SIZE];
		int	dp[MAX_SIZE];

		cin>>N;
		max_dp = 0;
		
		for(int i=1;i<=N;i++)
		{
			cin>>h[i];
		}
		
		for(int i=1;i<=N;i++)
		{
			int	prev_max;
			
			prev_max = 0;
			
			for(int j=1;j<i;j++)
			{
				if( h[j] < h[i] )
				{
					prev_max = max(prev_max,dp[j]);
				}
			}
			
			dp[i] = prev_max+1;
			max_dp = max(max_dp,dp[i]);
		}
		
		cout<<"Case #"<<t<<": "<<N-max_dp<<'\n';
	}
	
	return	0;
}
