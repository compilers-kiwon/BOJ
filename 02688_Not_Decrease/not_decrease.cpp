#include	<iostream>

using namespace	std;

typedef	unsigned long long	uint64;

#define	MAX_DIGIT	64
#define	MAX_NUM		9

int	main(void)
{
	uint64	dp[MAX_DIGIT+1][MAX_NUM+1],sum_table[MAX_DIGIT+1];
	int		T;
	
	cin>>T;
	
	sum_table[1] = 0;
	
	for(int i=0;i<=MAX_NUM;i++)
	{
		dp[1][i] = 1;
		sum_table[1] += dp[1][i];
	}
	
	for(int digit=2;digit<=MAX_DIGIT;digit++)
	{
		sum_table[digit] = dp[digit][9] = 1;
			
		for(int j=8;j>=0;j--)
		{
			dp[digit][j] = dp[digit][j+1]+dp[digit-1][j];
			sum_table[digit] += dp[digit][j];
		}
	}
	
	while(T>0)
	{
		int		n;
				
		cin>>n;
		cout<<sum_table[n]<<endl;
		
		T--;
	}
	
	return	0;
}
