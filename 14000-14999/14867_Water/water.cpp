#include	<iostream>
#include	<queue>
#include	<map>

using namespace	std;

#define	MAX_VOLUME	100000

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO
{
	int	A,B,cnt;
};

vector< map<int,bool> >	visited(MAX_VOLUME);

bool	is_visited(int a,int b)
{
	bool	result;
	
	result = visited[a][b];
		
	if( result == false )
	{
		visited[a][b] = true;
	}
	
	return	result;
}

int		main(void)
{
	State			init,final;
	queue<State>	state_q;
	int				A_volume,B_volume,answer;
	
	cin>>A_volume>>B_volume>>final.A>>final.B;
	
	init.A = init.B = init.cnt = 0;
	visited[0][0] = true;
	state_q.push(init);
	answer = -1;
	
	while( state_q.size() != 0 )
	{
		State	current,next;
		
		current = state_q.front();
		state_q.pop();
		
		if( current.A == final.A && current.B == final.B )
		{
			answer = current.cnt;
			break;
		}
		
		next.cnt = current.cnt+1;
		
		// Fill
		next.A = A_volume;
		next.B = current.B;
		
		if( is_visited(next.A,next.B) == false )
		{
			state_q.push(next);
		}
		
		next.A = current.A;
		next.B = B_volume;
		
		if( is_visited(next.A,next.B) == false )
		{
			state_q.push(next);
		}
		
		// Empty
		next.A = 0;
		next.B = current.B;
		
		if( is_visited(next.A,next.B) == false )
		{
			state_q.push(next);
		}
		
		next.A = current.A;
		next.B = 0;
		
		if( is_visited(next.A,next.B) == false )
		{
			state_q.push(next);
		}
		
		// Move
		if( current.A > 0 )
		{
			if( current.A <= B_volume-current.B )
			{
				next.A = 0;
				next.B = current.B+current.A;
			}
			else
			{
				next.A = current.A-(B_volume-current.B);
				next.B = B_volume;
			}
			
			if( is_visited(next.A,next.B) == false )
			{
				state_q.push(next);
			}
		}
		
		if( current.B > 0 )
		{
			if( current.B <= A_volume-current.A )
			{
				next.A = current.A+current.B;
				next.B = 0;
			}
			else
			{
				next.A = A_volume;
				next.B = current.B-(A_volume-current.A);
			}
			
			if( is_visited(next.A,next.B) == false )
			{
				state_q.push(next);
			}
		}
	}
	cout<<answer<<endl;
	
	return	0;
}
