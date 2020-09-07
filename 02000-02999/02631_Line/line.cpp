#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_CHILDREN	(200+1)

void	build_dp(int data[],int dp[],int size,int& max_dp)
{
	dp[1] = 1;
	max_dp = 0;
	
	for(int i=2;i<=size;i++)
	{
		int	max_dp_prev = 0;
		
		for(int j=1;j<i;j++)
		{
			if( data[j] < data[i] )
			{
				max_dp_prev = max(max_dp_prev,dp[j]);
			}
		}
		dp[i] = max_dp_prev+1;
		max_dp = max(max_dp,dp[i]);
	}
}

int		main(void)
{
	int	dp[MAX_NUM_OF_CHILDREN],num[MAX_NUM_OF_CHILDREN],N,max_dp;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>num[i];
	}
	
	build_dp(num,dp,N,max_dp);
	
	cout<<N-max_dp<<endl;
	
	return	0;
}
