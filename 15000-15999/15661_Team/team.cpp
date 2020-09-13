#include	<iostream>
#include	<vector>
#include	<cmath>

using namespace	std;

#define	MAX_SIZE	(20+1)

int		N,S[MAX_SIZE][MAX_SIZE];

int		get_team_ability(vector<int>& team)
{
	int	sum;
	
	sum = 0;
	
	for(int i=0;i<(int)team.size()-1;i++)
	{
		for(int j=i+1;j<(int)team.size();j++)
		{
			sum += S[team[i]][team[j]]+S[team[j]][team[i]];
		}
	}
	
	return	sum;
}

void	build_team(int worker,vector<int>& start,vector<int>& link,int& min_diff)
{
	if( worker > N )
	{
		int	team_start,team_link;
		
		team_start = get_team_ability(start);
		team_link = get_team_ability(link);
		
		min_diff = min(min_diff,abs(team_start-team_link));
		
		return;
	}
	
	start.push_back(worker);
	build_team(worker+1,start,link,min_diff);
	start.pop_back();
	
	link.push_back(worker);
	build_team(worker+1,start,link,min_diff);
	link.pop_back();
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cin>>S[i][j];
		}
	}
	
	vector<int>	start,link;
	int			min_diff;
	
	min_diff = 0x7FFFFFFF;
	build_team(1,start,link,min_diff);
	
	cout<<min_diff<<'\n';
	
	return	0;
}
