#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_LEN				100
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>	State;	// first:position, second:distance

int		a,b,x,y;
bool	visited[MAX_LEN+1];

void	init(void)
{
	cin>>a>>b>>x>>y;
}

int		move(void)
{
	queue<State>	state_q;
	int				min_distance;
	
	visited[a] = true;
	state_q.push(make_pair(a,0));
	
	if( a == x )
	{
		visited[y] = true;
		state_q.push(make_pair(y,0));
	}
	
	if( a == y )
	{
		visited[x] = true;
		state_q.push(make_pair(x,0));
	}
	
	while( !state_q.empty() )
	{
		int	current_position,current_distance;
		int	adj_position,adj_distance;
		
		current_position = state_q.front().first;
		current_distance = state_q.front().second;
		
		state_q.pop();
		
		if( current_position == b )
		{
			min_distance = current_distance;
			break;
		}
		
		adj_distance = current_distance+1;
		
		// Left
		adj_position = current_position-1;
		
		if( IN_RANGE(0,adj_position,MAX_LEN) && visited[adj_position]==false )
		{
			visited[adj_position] = true;
			state_q.push(make_pair(adj_position,adj_distance));
			
			if( adj_position==x && visited[y]==false )
			{
				visited[y] = true;
				state_q.push(make_pair(y,adj_distance));
			}
			
			if( adj_position==y && visited[x]==false )
			{
				visited[x] = true;
				state_q.push(make_pair(x,adj_distance));
			}
		}
		
		// Right
		adj_position = current_position+1;
		
		if( IN_RANGE(0,adj_position,MAX_LEN) && visited[adj_position]==false )
		{
			visited[adj_position] = true;
			state_q.push(make_pair(adj_position,adj_distance));
			
			if( adj_position==x && visited[y]==false )
			{
				visited[y] = true;
				state_q.push(make_pair(y,adj_distance));
			}
			
			if( adj_position==y && visited[x]==false )
			{
				visited[x] = true;
				state_q.push(make_pair(x,adj_distance));
			}
		}
	}
	
	return	min_distance;
}

int		main(void)
{
	init();
	cout<<move()<<'\n';
	
	return	0;
}
