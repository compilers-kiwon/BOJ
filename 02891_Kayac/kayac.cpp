#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_TEAM	(10+1)

typedef	pair<bool,bool>	Team;	// first:extra, second:available

int		N,S,R;
Team	team[MAX_NUM_OF_TEAM];

void	play_game(int team_index,int& min_num)
{
	if( team_index > N )
	{
		int	cnt,i;
		
		for(cnt=0,i=1;i<=N;i++)
		{
			if( team[i].second == false )
			{
				cnt++;
			}
		}
		
		min_num = min(min_num,cnt);
		
		return;
	}
	
	if( team[team_index].second == true )
	{
		play_game(team_index+1,min_num);
	}
	else
	{
		if( team[team_index].first == true )
		{
			team[team_index].first = false;
			team[team_index].second = true;
			
			play_game(team_index+1,min_num);
			
			team[team_index].second = false;
			team[team_index].first = true;
		}
		else
		{
			int	adj_team_index;
		
			// left
			adj_team_index = team_index-1;
			
			if( adj_team_index >= 1 && team[adj_team_index].first == true )
			{
				team[adj_team_index].first = false;
				team[team_index].second = true;
				
				play_game(team_index+1,min_num);
				
				team[team_index].second = false;
				team[adj_team_index].first = true;
			}
			
			// right
			adj_team_index = team_index+1;
			
			if( adj_team_index <= N && team[adj_team_index].first == true )
			{
				team[adj_team_index].first = false;
				team[team_index].second = true;
				
				play_game(team_index+1,min_num);
				
				team[team_index].second = false;
				team[adj_team_index].first = true;
			}
			
			// no rent
			play_game(team_index+1,min_num);
		}
	}
}

int		main(void)
{
	cin>>N>>S>>R;
	
	for(int i=1;i<=N;i++)
	{
		team[i].first = false;
		team[i].second = true;
	}
	
	for(int i=1;i<=S;i++)
	{
		int	s;
		
		cin>>s;
		team[s].second = false;
	}
	
	for(int i=1;i<=R;i++)
	{
		int	r;
		
		cin>>r;
		team[r].first = true;
	}
	
	int	min_num = 0x7FFFFFFF;
	
	play_game(1,min_num);
	
	cout<<min_num<<'\n';
	
	return	0;
}
