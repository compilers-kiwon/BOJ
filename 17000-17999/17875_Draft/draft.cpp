#include	<iostream>
#include	<string>
#include	<queue>
#include	<map>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_TEAMS	(60+1)

int					n,k,p;
queue<string>		preferred[MAX_NUM_OF_TEAMS];
queue<string>		player;
map<string,bool>	available;
vector<string>		team[MAX_NUM_OF_TEAMS];

void	input(void)
{
	cin>>n>>k;
	
	for(int t=1;t<=n;t++)
	{
		int	q;
		
		cin>>q;
		
		for(int j=1;j<=q;j++)
		{
			string	str;
			
			cin>>str;
			preferred[t].push(str);
		}
	}
	
	cin>>p;
	
	for(int i=1;i<=p;i++)
	{
		string	str;
		
		cin>>str;
		
		player.push(str);
		available[str] = true;
	}
}

void	get_preferred_player(string& name,int t)
{
	for(bool found=false;!preferred[t].empty()&&found==false;preferred[t].pop())
	{
		if( available[preferred[t].front()] == true )
		{
			name = preferred[t].front();
			found = true;
		}
	}
}

void	get_player_from_list(string& name)
{
	for(bool found=false;found==false;player.pop())
	{
		if( available[player.front()] == true )
		{
			name = player.front();
			found = true;
		}
	}
}

void	simulate(void)
{
	for(int r=1;r<=k;r++)
	{
		for(int t=1;t<=n;t++)
		{
			string	drafted;
			
			get_preferred_player(drafted,t);
			
			if( drafted.empty() )
			{
				get_player_from_list(drafted);
			}
			
			available[drafted] = false;
			team[t].push_back(drafted);
		}
	}
}

void	print_team(void)
{
	for(int t=1;t<=n;t++)
	{
		for(int i=0;i<k;i++)
		{
			cout<<team[t][i]<<' ';
		}
		cout<<'\n';
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	simulate();
	print_team();
	
	return	0;
}
