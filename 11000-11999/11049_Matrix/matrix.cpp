#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(500+1)
#define	TBD			-1
#define	INF			0x7FFFFFFFFFFFFFFFL

typedef	long long int		int64;
typedef	pair<int64,int64>	Size;

int		N;
Size	m[MAX_SIZE];
int64	dp[MAX_SIZE][MAX_SIZE];

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int64&	row = m[i].first;
		int64&	col = m[i].second;
		
		cin>>row>>col;
	}
	
	for(int i=1;i<=N;i++)
	{
		fill(&dp[i][1],&dp[i][N+1],TBD);
		dp[i][i] = 0;
	}
}

int64	get_dp(int s,int e)
{
	int64&	ret = dp[s][e];
	
	if( ret != TBD )
	{
		return	ret;
	}
	
	ret = INF;
	
	for(int i=s;i<e;i++)
	{
		ret = min(ret,get_dp(s,i)+get_dp(i+1,e)+m[s].first*m[i].second*m[e].second);
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<get_dp(1,N)<<'\n';
	
	return	0;
}
