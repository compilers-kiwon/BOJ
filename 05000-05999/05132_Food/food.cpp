#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_FOODS	(50000+1)

int	n,v[MAX_NUM_OF_FOODS],dp[MAX_NUM_OF_FOODS];

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int	max_value;
		
		cin>>n;
		
		for(int i=1;i<=n;i++)
		{
			cin>>v[i];
		}
		
		dp[1] = v[1];
		
		for(int i=2;i<=n;i++)
		{
			dp[i] = max(dp[i-1],dp[i-2]+v[i]);
		}
		
		cout<<"Data Set "<<k<<":\n"<<max(dp[n],dp[n-1])<<"\n\n";
	}
	
	return	0;
}
