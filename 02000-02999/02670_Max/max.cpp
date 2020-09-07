#include	<iostream>

using namespace	std;

#define	MAX_LEN	(10000+1)

double	n[MAX_LEN],dp[MAX_LEN];
int		N;

int		main(void)
{
	double	max_num = 0.0;
	
	cin>>N;
	
	dp[0] = 1.0;
	
	for(int i=1;i<=N;i++)
	{
		cin>>n[i];
		dp[i] = max(n[i],dp[i-1]*n[i]);
		max_num = max(max_num,dp[i]);
	}
	printf("%.03f\n",max_num);
	
	return	0;
}
