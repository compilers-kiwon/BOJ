#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_CARDS	(1000+1)
#define	MAX_NUM_OF_VILLAGE	(500+1)

typedef	pair<int,char>	Path;	// first:village, second:path color

char			card[MAX_NUM_OF_VILLAGE];
vector<Path>	connected[MAX_NUM_OF_VILLAGE];
int				N,M,K,dp[MAX_NUM_OF_VILLAGE][MAX_NUM_OF_CARDS];

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>card[i];
	}
	
	cin>>M>>K;
	
	for(int i=1;i<=K;i++)
	{
		int		v1,v2;
		char	c;
		
		cin>>v1>>v2>>c;
		
		connected[v1].push_back(make_pair(v2,c));
		connected[v2].push_back(make_pair(v1,c));
	}
	
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=N;j++)
		{
			dp[i][j] = -1;
		}
	}
}

int		get_dp(int village,int visit_number)
{
	if( visit_number > N )
	{
		return	0;
	}
	
	int&	ret = dp[village][visit_number];
	
	if( ret != -1 )
	{
		return	ret;
	}
	
	ret = 0;
	
	vector<Path>&	adj_village = connected[village];
	
	for(int i=0;i<adj_village.size();i++)
	{
		int&	next_village = adj_village[i].first;
		char&	color = adj_village[i].second;
		
		ret = max(ret,get_dp(next_village,visit_number+1)+((card[visit_number]==color)?10:0));
	}
	
	return	ret;
}

int	main(void)
{
	input();
	cout<<get_dp(1,1)<<endl;
	
	return	0;
}
