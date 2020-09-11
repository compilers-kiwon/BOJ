#include	<iostream>
#include	<map>
#include	<cmath>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_LEVEL	19

int	x,y;

map< int , map< int , vector<bool> > >	visited;

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO
{
	int	x,y,level;
};

bool	is_reachable(void)
{
	queue<State>	state_q;
	State			s;
	
	s.x = s.y = s.level = 0;
	state_q.push(s);
	
	if( visited[s.x][s.y].size() == 0 )
	{
		visited[s.x][s.y].resize(MAX_LEVEL+1,false);
	}
	visited[s.x][s.y][s.level] = true;
	
	while( !state_q.empty() )
	{
		int		current_x,current_y,current_level;
		State	next_state;
		
		s = state_q.front();
		state_q.pop();
		
		current_x = s.x;
		current_y = s.y;
		current_level = s.level;
		
		if( current_x==x && current_y==y )
		{
			return	true;
		}
		
		int	next_x,next_y;
		
		next_x = current_x+pow(3,current_level);
		
		if( next_x <= x )
		{
			if( visited[next_x][current_y].size()==0 || visited[next_x][current_y][current_level+1]==false )
			{
				if( visited[next_x][current_y].size()==0 )
				{
					visited[next_x][current_y].resize(MAX_LEVEL+1,false);
				}
				visited[next_x][current_y][current_level+1] = true;
				
				next_state.x = next_x;
				next_state.y = current_y;
				next_state.level = current_level+1;
				
				state_q.push(next_state);
			}
		}
		
		next_y = current_y+pow(3,current_level);
		
		if( next_y <= y )
		{
			if( visited[current_x][next_y].size()==0 || visited[current_x][next_y][current_level+1]==false )
			{
				if( visited[current_x][next_y].size()==0 )
				{
					visited[current_x][next_y].resize(MAX_LEVEL+1,false);
				}
				visited[current_x][next_y][current_level+1] = true;
				
				next_state.x = current_x;
				next_state.y = next_y;
				next_state.level = current_level+1;
				
				state_q.push(next_state);
			}
		}
	}
	
	return	false;
}

int		main(void)
{
	cin>>x>>y;
	cout<<is_reachable()<<'\n';
	
	return	0;
}
