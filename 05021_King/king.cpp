#include	<iostream>
#include	<string>
#include	<map>
#include	<vector>

using namespace	std;

#define	ROYAL	0x4000000000000000

typedef	pair<string,string>	Parent;
typedef	long long int		int64;

int					N,M;
map<string,int64>	dp;
map<string,Parent>	relation;
vector<string>		candidate;

void	init(void)
{
	string	king;
	
	cin>>N>>M>>king;
	
	for(int i=1;i<=N;i++)
	{
		string	child,mom,dad;
		
		cin>>child>>mom>>dad;
		dp[child] = dp[mom] = dp[dad] = -1;
		relation[child] = make_pair(mom,dad);
	}
	
	map<string,int64>::iterator	iter;
	
	for(iter=dp.begin();iter!=dp.end();iter++)
	{
		if( relation[iter->first].first=="" && relation[iter->first].second=="" )
		{
			iter->second = 0;
		}
	}
	dp[king] = ROYAL;
	
	for(int i=1;i<=M;i++)
	{
		string	c;
		
		cin>>c;
		candidate.push_back(c);
	}	
}

int64	get_dp(string me)
{
	int64&	ret = dp[me];
	
	if( ret != -1 )
	{
		return	ret;
	}
	
	ret = get_dp(relation[me].first)/2+get_dp(relation[me].second)/2;
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	init();
	
	map<string,int64>::iterator	iter;
		
	for(iter=dp.begin();iter!=dp.end();iter++)
	{
		if( iter->second == -1 )
		{
			get_dp(iter->first);
		}
	}
	
	int64	max_score;
	string	next_king;
	
	max_score = 0;
	
	for(int i=0;i<candidate.size();i++)
	{
		if( dp[candidate[i]] > max_score )
		{
			max_score = dp[candidate[i]];
			next_king = candidate[i];
		}
	}
	
	cout<<next_king<<'\n';
	
	return	0;
}
