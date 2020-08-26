#include	<iostream>
#include	<queue>
#include	<map>
#include	<string>
#include	<vector>

using namespace	std;

#define	QUALIFIED	0.05
#define	MAX_SIZE	14

typedef	pair<double,string>	Score;

int	main(void)
{
	double	X;
	int		N;
	
	vector<Score>			candidate;
	priority_queue<Score>	pq;
	map<string,int>			score_table;
	
	cin.sync_with_stdio(false);
	
	cin>>X>>N;
	
	for(int i=1;i<=N;i++)
	{
		string	name;
		double	vote;
		
		cin>>name>>vote;
		
		if( vote/X < QUALIFIED )
		{
			continue;
		}
		
		score_table[name] = 0;
		candidate.push_back(make_pair(vote,name));
	}
	
	for(int i=0;i<candidate.size();i++)
	{
		for(int j=1;j<=MAX_SIZE;j++)
		{
			pq.push(make_pair(candidate[i].first/(double)j,candidate[i].second));
		}
	}
	
	for(int i=1;i<=MAX_SIZE&&!pq.empty();i++)
	{
		score_table[pq.top().second]++;
		pq.pop();
	}
	
	map<string,int>::iterator	iter;
	
	for(iter=score_table.begin();iter!=score_table.end();iter++)
	{
		cout<<iter->first<<' '<<iter->second<<'\n';
	}
	
	return	0;
}
