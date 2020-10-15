#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(8+1)
#define	INF			0x7FFFFFFF

int		N,skill[MAX_SIZE];
bool	selected[MAX_SIZE];

int		get_diff(void)
{
	int	s1,s2;
	
	s1 = s2 = 0;
	
	for(int i=1;i<=N;i++)
	{
		if( selected[i] == true )
		{
			s1 += skill[i];
		}
		else
		{
			s2 += skill[i];
		}
	}
	
	return	max(s1,s2)-min(s1,s2);
}

void	build_team(int team_size,int& min_diff,int prev_selected)
{
	if( team_size == N/2 )
	{
		min_diff = min(min_diff,get_diff());
		return;
	}
	
	if( ((N/2)-team_size) > N-prev_selected )
	{
		return;
	}

	for(int i=prev_selected+1;i<=N;i++)
	{
		if( selected[i] == false )
		{
			selected[i] = true;
			build_team(team_size+1,min_diff,i);
			selected[i] = false;
		}
	}
}

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>skill[i];
		selected[i] = false;
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int	min_diff;
		
		input();
		min_diff = INF;
		
		build_team(0,min_diff,0);
		cout<<"Case #"<<t<<": "<<min_diff<<'\n';
	}
	
	return	0;
}
