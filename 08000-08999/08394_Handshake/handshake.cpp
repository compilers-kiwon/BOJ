#include	<iostream>

using namespace	std;

#define	SIZE	60

int	main(void)
{
	int	dp[SIZE];
	
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	
	for(int i=3;i<SIZE;i++)
	{
		dp[i] = (dp[i-2]+dp[i-1])%10;
	}
	
	dp[0] = 1;
	
	int	n;
	
	cin>>n;
	cout<<dp[n%SIZE]<<endl;
	
	return	0;
}
