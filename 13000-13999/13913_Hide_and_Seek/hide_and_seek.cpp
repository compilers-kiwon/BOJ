#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_LEN	100000

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

typedef	pair<int,int>	State;

#define	location	first
#define	time		second

int	get_min_time(int start,int end,vector<bool>& visited,vector<int>& path)
{
	queue<State>	state_q;
	int				min_time;
	
	state_q.push(make_pair(start,0));
	visited[start] = true;
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
			break;
		}
		
		int	next_location;
		
		// X-1
		next_location = current_location-1;
				
		if( IN_RANGE(0,next_location,MAX_LEN) && visited[next_location] == false )
		{
			visited[next_location] = true;
			path[next_location] = current_location;
			state_q.push(make_pair(next_location,current_time+1));
		}
		
		// X+1
		next_location = current_location+1;

		if( IN_RANGE(0,next_location,MAX_LEN) && visited[next_location] == false )
		{
			visited[next_location] = true;
			path[next_location] = current_location;
			state_q.push(make_pair(next_location,current_time+1));
		}
		
		// X*2
		next_location = current_location*2;
				
		if( IN_RANGE(0,next_location,MAX_LEN) && visited[next_location] == false )
		{
			visited[next_location] = true;
			path[next_location] = current_location;
			state_q.push(make_pair(next_location,current_time+1));
		}
	}
	
	return	min_time;
}

int	main(void)
{
	vector<bool>	visited(MAX_LEN+1,false);
	vector<int>		path(MAX_LEN+1,-1);
	vector<int>		st;
	
	int				N,K;
	
	cin>>N>>K;
	cout<<get_min_time(N,K,visited,path)<<endl;
	
	for(int i=K;i!=-1;i=path[i])
	{
		st.push_back(i);
	}
	
	for(int i=st.size()-1;i>=0;i--)
	{
		cout<<st[i]<<' ';
	}
	cout<<endl;
	
	return	0;
}
