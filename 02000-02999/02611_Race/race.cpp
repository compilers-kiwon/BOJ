#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_POINTS	(1000+1)

typedef	pair<int,int>	Path;	// first:from, second:score

int				N,M,dp[MAX_NUM_OF_POINTS];
vector<Path>	connected[MAX_NUM_OF_POINTS];

void	input(void)
{
	cin>>N>>M;
	
	dp[1] = 0;
	for(int i=2;i<=N;i++)
	{
		dp[i] = -1;
	}
	
	for(int i=1;i<=M;i++)
	{
		int	p,q,r;
		
		cin>>p>>q>>r;
		connected[q].push_back(make_pair(p,r));
	}
}

int		get_dp(int index,vector<int>& path)
{
	if( dp[index] != -1 )
	{
		return	dp[index];
	}
	
	int	max_score_index;
	
	for(int i=0;i<connected[index].size();i++)
	{
		int	tmp;
		
		if( dp[index] < (tmp=get_dp(connected[index][i].first,path)+connected[index][i].second) )
		{
			dp[index] = tmp;
			max_score_index = connected[index][i].first;
		}
	}
	path[index] = max_score_index;
	
	return	dp[index];
}

int		main(void)
{
	input();
	
	int			max_score,i,max_score_index;
	vector<int>	path(MAX_NUM_OF_POINTS,0),answer;
		
	for(i=max_score=0;i<connected[1].size();i++)
	{
		int	tmp;
		
		if( max_score < (tmp=get_dp(connected[1][i].first,path)+connected[1][i].second) )
		{
			max_score = tmp;
			max_score_index = connected[1][i].first;
		}
	}
	
	cout<<max_score<<endl;
	
	answer.push_back(1);
	answer.push_back(max_score_index);
	
	for(i=max_score_index;path[i]!=0;i=path[i])
	{
		answer.push_back(path[i]);
	}
	
	for(i=answer.size()-1;i>=0;i--)
	{
		cout<<answer[i]<<' ';
	}
	cout<<endl;
	
	return	0;
}
