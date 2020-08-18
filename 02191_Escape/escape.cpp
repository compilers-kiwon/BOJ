#include	<iostream>
#include	<vector>
#include	<cmath>

using namespace	std;

#define	MAX_NUM_OF_MOUSE	(100+1)
#define	MAX_NUM_OF_SHELTER	(100+1)

#define	NONE	0

typedef	pair<double,double>	Mouse;
typedef	Mouse				Shelter;

int			N,M;
double		S,V;
Mouse		mouse[MAX_NUM_OF_MOUSE];
Shelter		shelter[MAX_NUM_OF_SHELTER];
vector<int>	accessible_shelter[MAX_NUM_OF_MOUSE];

int			visited[MAX_NUM_OF_MOUSE];
int			mouse_in_shelter[MAX_NUM_OF_SHELTER];

inline double	get_distance(Mouse& m,Shelter& s)
{
	double	dx,dy;
	
	dx = m.first-s.first;
	dy = m.second-s.second;
	
	return	sqrt(dx*dx+dy*dy);	
}

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N>>M>>S>>V;
	
	for(int i=1;i<=N;i++)
	{
		cin>>mouse[i].first>>mouse[i].second;
	}
	
	for(int i=1;i<=M;i++)
	{
		cin>>shelter[i].first>>shelter[i].second;
	}
	
	double	max_escape_distance;
	
	max_escape_distance = S*V;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if( get_distance(mouse[i],shelter[j]) <= max_escape_distance )
			{
				accessible_shelter[i].push_back(j);
			}
		}
	}
}	

bool	dfs(int current_mouse,int level)
{
	if( visited[current_mouse] == level )
	{
		return	false;
	}
	
	visited[current_mouse] = level;
	
	vector<int>&	candidate_shelter = accessible_shelter[current_mouse];
	
	for(int i=0;i<candidate_shelter.size();i++)
	{
		int&	shelter = candidate_shelter[i];
		
		if( mouse_in_shelter[shelter]==NONE || dfs(mouse_in_shelter[shelter],level)==true )
		{
			mouse_in_shelter[shelter] = current_mouse;
			
			return	true;
		}
	}
	
	return	false;
}

int		main(void)
{
	init();
	
	int	cnt,i;
	
	for(cnt=0,i=1;i<=N;i++)
	{
		if( dfs(i,i) == false )
		{
			cnt++;
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
