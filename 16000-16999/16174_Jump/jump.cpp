#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE			(64+1)
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>	State;

int		N,map[MAX_SIZE][MAX_SIZE];
bool	visited[MAX_SIZE][MAX_SIZE];

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			cin>>map[row][col];
		}
	}
}

bool	is_reachable(void)
{
	queue<State>	state_q;
	
	state_q.push(make_pair(1,1));
	visited[1][1] = true;
	
	while( !state_q.empty() )
	{
		int		current_row,current_col;
		
		current_row = state_q.front().first;
		current_col = state_q.front().second;
		state_q.pop();
		
		int&	move = map[current_row][current_col];
		int		next_row,next_col;
		
		if( move == -1 )
		{
			return	true;
		}
		
		next_row = current_row+move;
		next_col = current_col+move;
		
		if( IN_RANGE(1,next_row,N) && visited[next_row][current_col]==false )
		{
			visited[next_row][current_col] = true;
			state_q.push(make_pair(next_row,current_col));
		}
		
		if( IN_RANGE(1,next_col,N) && visited[current_row][next_col]==false )
		{
			visited[current_row][next_col] = true;
			state_q.push(make_pair(current_row,next_col));
		}
	}
	
	return	false;
}

int		main(void)
{
	init();
	
	if( is_reachable() == true )
	{
		cout<<"HaruHaru\n";
	}
	else
	{
		cout<<"Hing\n";
	}
	
	return	0;
}
