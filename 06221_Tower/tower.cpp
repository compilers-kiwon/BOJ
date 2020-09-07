#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_BALE	(20+1)

typedef	pair<int,int>	Bale;

int	main(void)
{
	int		N,dp[MAX_NUM_OF_BALE];
	Bale	b[MAX_NUM_OF_BALE];
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>b[i].first>>b[i].second;
	}
	
	sort(&b[1],&b[N+1]);
	
	for(int i=1;i<=N;i++)
	{
		int	max_h;
		
		max_h = 0;
		
		for(int j=1;j<i;j++)
		{
			if( b[j].first<b[i].first && b[j].second<b[i].second )
			{
				max_h = max(max_h,dp[j]);
			}
		}
		
		dp[i] = max_h+1;
	}
	
	int	max_h;
	
	max_h = 0;
	
	for(int i=1;i<=N;i++)
	{
		max_h = max(max_h,dp[i]);
	}
	
	cout<<max_h<<'\n';
	
	return	0;
}
