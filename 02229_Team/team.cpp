#include	<iostream>

using namespace	std;

#define	MAX_STUDENTS	(1000+1)

int	score[MAX_STUDENTS],dp[MAX_STUDENTS];

int	main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>score[i];
	}
	
	dp[1] = 0;
	
	for(int i=2;i<=N;i++)
	{
		for(int j=1;j<=i;j++)
		{
			int	diff;
			
			diff = max(score[i],score[j])-min(score[i],score[j]);
			dp[i] = max(dp[i],dp[j-1]+diff);
		}
	}
	cout<<dp[N]<<endl;
	
	return	0;
 } 
