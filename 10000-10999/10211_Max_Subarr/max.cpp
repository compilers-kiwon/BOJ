#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1000+1)

int	X[MAX_SIZE],dp[MAX_SIZE];

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int			N,max_sub_sum;

		cin>>N;

		for(int i=1;i<=N;i++)
		{
			cin>>X[i];
		}
		
		dp[0] = 0;
		dp[1] = X[1];
		max_sub_sum = -1001;
		
		for(int i=1;i<=N;i++)
		{
			dp[i] = max(X[i],dp[i-1]+X[i]);
			max_sub_sum = max(max_sub_sum,dp[i]);
		}
		
		cout<<max_sub_sum<<'\n';
		
		T--;
	}
	
	return	0;
}
