#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_POINT	100000

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

typedef	pair<int,int>	State;

#define	location	first
#define	time		second

int	get_min_time(int start,int end,vector<int>& visited_time)
{
	queue<State>	state_q;
	int				min_time;
	
	state_q.push(make_pair(start,0));
	visited_time[start] = 0;
	min_time = 0x7FFFFFFF;
	
	while( state_q.size() != 0 )
	{
		int	current_location,current_time;
		
		current_location = state_q.front().location;
		current_time = state_q.front().time;
		
		state_q.pop();
		
		if( current_location == end )
		{
			min_time = min(current_time,min_time);
			continue;
		}
		
		int	next_location,next_time;
		
		// X-1
		next_location = current_location-1;
		next_time = current_time+1;
		
		if( IN_RANGE(0,next_location,MAX_POINT) && next_time < visited_time[next_location] )
		{
			visited_time[next_location] = next_time;
			state_q.push(make_pair(next_location,next_time));
		}
		
		// X+1
		next_location = current_location+1;

		if( IN_RANGE(0,next_location,MAX_POINT) && next_time < visited_time[next_location] )
		{
			visited_time[next_location] = next_time;
			state_q.push(make_pair(next_location,next_time));
		}
		
		// X*2
		next_location = current_location*2;
		next_time = current_time;
		
		if( IN_RANGE(0,next_location,MAX_POINT) && next_time < visited_time[next_location] )
		{
			visited_time[next_location] = next_time;
			state_q.push(make_pair(next_location,next_time));
		}
	}
	
	return	min_time;
}

int	main(void)
{
	vector<int>	visited_time(MAX_POINT+1,0x7FFFFFFF);
	int			N,K;
	
	cin>>N>>K;
	cout<<get_min_time(N,K,visited_time)<<endl;
	
	return	0;
}
