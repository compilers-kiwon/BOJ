#include	<iostream>
#include	<vector>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int			N,max_sub_sum;
		vector<int>	X,dp;
		
		cin>>N;
		
		X.resize(N+1);
		dp.resize(N+1);
		
		for(int i=1;i<=N;i++)
		{
			cin>>X[i];
		}
		
		dp[1] = X[1];
		max_sub_sum = -1001;
		
		for(int i=2;i<=N;i++)
		{
			dp[i] = max(X[i],dp[i-1]+X[i]);
			max_sub_sum = max(max_sub_sum,dp[i]);
		}
		cout<<max_sub_sum<<endl;
		
		T--;
	}
	
	return	0;
}
