#include	<iostream>
#include	<string>
#include	<vector>
#include	<algorithm>
#include	<map>

using namespace	std;

#define	OFFSET				('a'-'A')
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
#define	get_goal_diff(t)	((t).goals_for-(t).goals_against)

typedef	struct	_TEAM_INFO	Team;
struct	_TEAM_INFO
{
	string	name,lower;
	int		games_played,wins,draws,losses,goals_for,goals_against,points;
};

void	input_current_status(map<string,int>& idx,vector<Team>& league)
{
	int	T;
	
	cin>>T;getchar();
	
	for(int i=0;i<T;i++)
	{
		Team	t;
		
		getline(cin,t.name);
		
		for(int j=0;j<t.name.length();j++)
		{
			char&	c = t.name[j];
			
			if( IN_RANGE('A',c,'Z') )
			{
				t.lower.push_back(c+OFFSET);
			}
			else
			{
				t.lower.push_back(c);
			}
		}
		
		cin>>t.games_played>>t.wins>>t.draws>>t.losses
		   >>t.goals_for>>t.goals_against>>t.points;
		getchar();
		
		league.push_back(t);
		idx[t.name] = i;
	}
}

void	update_status(Team& t,int scored,int conceded)
{
	t.games_played++;
	t.goals_for += scored;
	t.goals_against += conceded;
	
	if( scored == conceded )
	{
		t.draws++;
		t.points++;
	}
	else
	{
		if( scored > conceded )
		{
			t.wins++;
			t.points += 3;
		}
		else
		{
			t.losses++;
		}
	}
}

void	input_game_result(map<string,int>& idx,vector<Team>& league)
{
	int	G;
	
	cin>>G;getchar();
	
	for(int i=1;i<=G;i++)
	{
		string	home_team_name,away_team_name,buf;
		int		home_team_score,away_team_score;
		int		home_team_idx,away_team_idx;
		
		getline(cin,home_team_name);
		getline(cin,buf);sscanf(buf.c_str(),"%d",&home_team_score);
		
		getline(cin,away_team_name);
		getline(cin,buf);sscanf(buf.c_str(),"%d",&away_team_score);
		
		home_team_idx = idx[home_team_name];
		away_team_idx = idx[away_team_name];
		
		Team&	h = league[home_team_idx];
		Team&	a = league[away_team_idx];
		
		update_status(h,home_team_score,away_team_score);
		update_status(a,away_team_score,home_team_score);
	}
}

bool	is_higher(const Team& t1,const Team& t2)
{
	bool	ret;
	
	if( t1.points > t2.points )
	{
		ret = true;
	}
	else
	{
		if( t1.points < t2.points )
		{
			ret = false;
		}
		else
		{
			if( get_goal_diff(t1) > get_goal_diff(t2) )
			{
				ret = true;
			}
			else
			{
				if( get_goal_diff(t1) < get_goal_diff(t2) )
				{
					ret = false;
				}
				else
				{
					if( t1.goals_for > t2.goals_for )
					{
						ret = true;
					}
					else
					{
						if( t1.goals_for < t2.goals_for )
						{
							ret = false;
						}
						else
						{
							if( t1.lower < t2.lower )
							{
								ret = true;
							}
							else
							{
								ret = false;
							}
						}
					}
				}
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	vector<Team>	teams_in_league;
	map<string,int>	team_idx;
	
	input_current_status(team_idx,teams_in_league);
	input_game_result(team_idx,teams_in_league);
	
	sort(teams_in_league.begin(),teams_in_league.end(),is_higher);
	
	for(int i=0;i<teams_in_league.size();i++)
	{
		Team&	t = teams_in_league[i];
		
		cout<<t.name<<' '<<t.games_played<<' '<<t.wins<<' '<<t.draws<<' '
			<<t.losses<<' '<<t.goals_for<<' '<<t.goals_against<<' '<<t.points<<'\n';
	}
	
	return	0;
}
