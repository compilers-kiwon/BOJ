#include	<iostream>

using namespace	std;

#define	MAX_N	(1000+1)

int		dp[MAX_N];

void	init_dp(void)
{
	dp[1] = 1;
	
	for(int i=2;i<MAX_N;i++)
	{
		dp[i] = (2*i-1)+dp[i-1];
	}
}

int		main(void)
{
	init_dp();
	
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	A,B;
		
		cin>>A>>B;
		cout<<dp[A/B]<<endl;
		
		T--;
	}
	
	return	0;
}
