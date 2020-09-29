#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	TBD			-1
#define	INF			1000000000

#define	RED			0
#define	GREEN		1
#define	BLUE		2
#define	MAX_COLOR	3

int	N,dp[MAX_SIZE][MAX_COLOR][MAX_COLOR],cost[MAX_SIZE][MAX_COLOR];

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>cost[i][RED]>>cost[i][GREEN]>>cost[i][BLUE];
		
		for(int j=RED;j<=BLUE;j++)
		{
			dp[i][RED][j] = dp[i][GREEN][j] = dp[i][BLUE][j] = TBD;
		}
	}
}

int		get_dp(int n,int c,int last_color)
{
	int&	ret = dp[n][c][last_color];
	
	if( ret != TBD )
	{
		return	ret;
	}
	
	int	min_cost;
	
	switch(c)
	{
		case	RED:
			min_cost = min(get_dp(n-1,GREEN,last_color),get_dp(n-1,BLUE,last_color));
			break;
		case	GREEN:
			min_cost = min(get_dp(n-1,RED,last_color),get_dp(n-1,BLUE,last_color));
			break;
		case	BLUE:
			min_cost = min(get_dp(n-1,RED,last_color),get_dp(n-1,GREEN,last_color));
			break;
		default:
			// do nothing
			break;
	}
	
	ret = min(INF,min_cost+cost[n][c]);
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	for(int c1=RED;c1<=BLUE;c1++)
	{
		for(int c2=RED;c2<=BLUE;c2++)
		{
			int&	d = dp[1][c1][c2];
			
			if( c1 == c2 )
			{
				d = INF;
			}
			else
			{
				d = cost[1][c1];
			}
		}
	}
	
	cout<<min(get_dp(N,RED,RED),min(get_dp(N,GREEN,GREEN),get_dp(N,BLUE,BLUE)))<<'\n';
	
	return	0;
}
