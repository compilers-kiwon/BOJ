#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	MAX_HEIGHT	(1000+1)

typedef	pair<int,int>	Rec;

#define	low		first
#define	high	second
	
void	input(int& len,int* h)
{
	cin>>len;
	
	for(int i=1;i<=len;i++)
	{
		cin>>h[i];
	}
}

int		main(void)
{
	int				N,P[MAX_SIZE],max_inc;
	pair<int,int>	dp[MAX_SIZE];
	
	input(N,P);
	
	max_inc = 0;
	P[0] = MAX_HEIGHT;
	
	for(int i=1;i<=N;i++)
	{
		if( P[i-1]<P[i] )
		{
			dp[i].low = dp[i-1].low;
			dp[i].high = P[i];
		}
		else
		{
			dp[i].low = dp[i].high = P[i];
		}
		
		max_inc = max(max_inc,dp[i].high-dp[i].low);
	}
	
	cout<<max_inc<<'\n';
	
	return	0;
}
