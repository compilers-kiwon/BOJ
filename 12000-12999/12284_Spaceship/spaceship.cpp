#include	<iostream>
#include	<string>
#include	<queue>
#include	<map>

using namespace	std;

#define	MAX_SIZE	(80000+1)
#define	NONE		0

typedef	pair<int,string>	State;		// first:-time,second:room
typedef	map<string,int>		Turbolift;

void	get_room_info(int& num_of_rooms,string* color,map<string,Turbolift>& connected)
{
	int	M;
	
	cin>>num_of_rooms;
	
	for(int i=1;i<=num_of_rooms;i++)
	{
		cin>>color[i];
	}
	
	cin>>M;
	
	for(int i=1;i<=M;i++)
	{
		int		a,b,t;
		
		cin>>a>>b>>t;
		
		string&		from = color[a];
		string&		to = color[b];
				
		if( connected[from][to]==0 || t<connected[from][to] )
		{
			connected[from][to] = t;
		}
	}
}

int		find_shortest_path(string& from,string& to,map<string,Turbolift>& connected)
{
	priority_queue<State>	pq;
	map<string,int>			dp;
	
	dp[from] = 1;
	pq.push(make_pair(-1,from));
	
	for(;!pq.empty();)
	{
		int		current_time;
		string	current_room;
		
		current_time = -pq.top().first;
		current_room = pq.top().second;
		
		pq.pop();
		
		if( current_room == to )
		{
			return	current_time-1;
		}
		
		Turbolift::iterator	it;
		
		for(it=connected[current_room].begin();it!=connected[current_room].end();it++)
		{
			const string&	adj_room = it->first;
			const int		adj_time = it->second;
			
			if( dp[adj_room]==NONE || current_time+adj_time<dp[adj_room] )
			{
				dp[adj_room] = current_time+adj_time;
				pq.push(make_pair(-(current_time+adj_time),adj_room));
			}
		}
	}
	return	-1;
}

void	do_query(string* color,map<string,Turbolift>& connected)
{
	int	S;
	
	cin>>S;
	
	for(int i=1;i<=S;i++)
	{
		int	p,q,t;
		
		cin>>p>>q;
		cout<<find_shortest_path(color[p],color[q],connected)<<'\n';
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
		int						N;
		string					color[MAX_SIZE];
		map<string,Turbolift>	connected;
		
		get_room_info(N,color,connected);
		
		cout<<"Case #"<<t<<":\n";
		do_query(color,connected);
	}
	
	return	0;
}
