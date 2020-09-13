#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_DAYS	(1500000+1)

typedef	pair<int,int>	Job;	// first:Start Date, second:P

vector<Job>	compensation[MAX_DAYS+100];
int			dp[MAX_DAYS];

int	get_dp(int day)
{
	int&	d = dp[day];
	
	if( d != -1 )
	{
		return	d;
	}
	
	d = get_dp(day-1);
	
	for(int i=0;i<compensation[day].size();i++)
	{
		int& start_day = compensation[day][i].first;
		int& reward = compensation[day][i].second;
		
		d = max(d,get_dp(start_day-1)+reward);
	}
	
	return	d;
}

int	main(void)
{
	int	N,max_compensation;
	
	scanf("%d",&N);
	max_compensation = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	T,P;
		
		scanf("%d %d",&T,&P);
		compensation[i+T-1].push_back(make_pair(i,P));
		dp[i] = -1;
	}
	
	for(int i=1;i<=N;i++)
	{
		max_compensation = max(max_compensation,get_dp(i));
		//cout<<dp[i]<<' ';
	}
	
	printf("%d\n",max_compensation);
	
	return	0;
}
