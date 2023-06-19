#include	<iostream>
#include	<vector>
#include	<cstring>

using namespace	std;

#define	MAX_NUM_OF_AIRPORTS	(100+1)
#define	MAX_COST			(10000+1)

static int	N,M,K;
static int	dp[MAX_NUM_OF_AIRPORTS][MAX_COST];

typedef	struct{int from,cost,time;}	Path;

static vector<Path>	connected[MAX_NUM_OF_AIRPORTS];

#define	TBD	-1
#define	INF	0x10000000

int	input(void)
{
	cin>>N>>M>>K;

	for(int i=1;i<=K;i++)
	{
		int	u,v,c,d;

		cin>>u>>v>>c>>d;
		connected[v].push_back({u,c,d});
	}

	return	0;
}

int	get_dp(int cur_airport,int available_buget)
{
	if( cur_airport == 1 )
	{
		return	0;
	}

	int&	ret = dp[cur_airport][available_buget];

	if( ret != TBD )
	{
		return	ret;
	}

	ret = INF;

	for(int i=0;i<connected[cur_airport].size();i++)
	{
		Path&	p = connected[cur_airport][i];

		if( p.cost <= available_buget )
		{
			ret = min(ret,get_dp(p.from,available_buget-p.cost)+p.time);
		}
	}

	return	ret;
}

int	init(void)
{
	memset(dp,TBD,sizeof(dp));
	for(int i=1;i<=MAX_NUM_OF_AIRPORTS;i++) connected[i].clear();
	return	0;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int	T;

	cin>>T;

	for(int t=1;t<=T;t++)
	{
		init();
		input();

		int	min_time = INF;

		for(int buget=0;buget<=M;buget++)
		{
			min_time = min(min_time,get_dp(N,buget));
		}

		if( min_time == INF )
		{
			cout<<"Poor KCM\n";
		}
		else
		{
			cout<<min_time<<'\n';
		}
	}

	return	0;
}