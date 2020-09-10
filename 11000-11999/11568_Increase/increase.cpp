#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_NUMBERS	(1000+1)

int	main(void)
{
	int	N,number[MAX_NUM_OF_NUMBERS],dp[MAX_NUM_OF_NUMBERS],max_len;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>number[i];
	}
	
	dp[1] = 1;
	max_len = 1;
	
	for(int i=2;i<=N;i++)
	{
		int	prev_max_len;
		
		prev_max_len = 0;
		
		for(int j=1;j<i;j++)
		{
			if( number[j] < number[i] )
			{
				prev_max_len = max(prev_max_len,dp[j]);
			}
		}
		dp[i] = prev_max_len+1;
		
		max_len = max(max_len,dp[i]);
	}
	cout<<max_len<<endl;
	
	return	0;	
}
