#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100+1)

#define	GOOD		0
#define	BAD			1
#define	MAX_FEELING	2

int	main(void)
{
	int		N,F,good,bad;
	double	dp[MAX_SIZE][MAX_FEELING];
	double	g2g,g2b,b2g,b2b;
	
	cin>>N>>F>>g2g>>g2b>>b2g>>b2b;
	
	for(int day=0;day<=N;day++)
	{
		dp[day][GOOD] = dp[day][BAD] = 0.0;
	}
	
	dp[0][F] = 1.0;
	
	for(int day=1;day<=N;day++)
	{
		dp[day][GOOD] = dp[day-1][GOOD]*g2g+dp[day-1][BAD]*b2g;
		dp[day][BAD] = dp[day-1][GOOD]*g2b+dp[day-1][BAD]*b2b;
	}
	
	good = ((int)(dp[N][GOOD]*10000.0)+5)/10;
	bad = ((int)(dp[N][BAD]*10000.0)+5)/10;
	
	cout<<good<<'\n'<<bad<<'\n';
	
	return	0;
}
