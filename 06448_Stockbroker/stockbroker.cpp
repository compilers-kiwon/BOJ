#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(100+1)
#define	INF			0x7FFFFFFF

typedef	pair<int,int>	State;	// first:-time,second:broker
typedef	pair<int,int>	Broker;	// first:adj_broker,second:time

bool	input(int& num_of_brokers,vector<Broker>* connected)
{
	cin>>num_of_brokers;
	
	if( num_of_brokers == 0 )
	{
		return	false;
	}
	
	for(int i=1;i<=num_of_brokers;i++)
	{
		int	n;
		
		cin>>n;
		
		for(int j=1;j<=n;j++)
		{
			int	to,time;
			
			cin>>to>>time;
			connected[i].push_back(make_pair(to,time));
		}
	}
	
	return	true;
}

int		find_max_transmission_time(int start_broker,int num_of_brokers,
								   vector<Broker>* connected)
{
	priority_queue<State>	pq;
	vector<bool>			visited(num_of_brokers+1,false);
	vector<int>				dp(num_of_brokers+1,INF);
	int						max_transmission_time,cnt_of_visited_brokers;
	
	pq.push(make_pair(0,start_broker));
	visited[start_broker] = true;
	cnt_of_visited_brokers = 1;
	dp[start_broker] = 0;
	max_transmission_time = 0;
	
	for(;!pq.empty();)
	{
		int	current_broker,current_time;
		
		current_time = -pq.top().first;
		current_broker = pq.top().second;
		
		pq.pop();
		
		vector<Broker>&	adj_brokers = connected[current_broker];
		
		for(int i=0;i<adj_brokers.size();i++)
		{
			int&	adj_broker = adj_brokers[i].first;
			int&	adj_time = adj_brokers[i].second;
			
			if( visited[adj_broker] == false )
			{
				visited[adj_broker] = true;
				cnt_of_visited_brokers++;
			}
			
			if( current_time+adj_time < dp[adj_broker] )
			{
				dp[adj_broker] = current_time+adj_time;
				pq.push(make_pair(-(current_time+adj_time),adj_broker));
				
				max_transmission_time = max(max_transmission_time,current_time+adj_time);
			}
		}
	}
	
	if( cnt_of_visited_brokers != num_of_brokers )
	{
		max_transmission_time = INF;
	}
	
	return	max_transmission_time;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int				N,min_time,start_broker;
		vector<Broker>	connected[MAX_SIZE];
		
		if( input(N,connected) == false )
		{
			break;
		}
		
		min_time = INF;
		
		for(int i=1;i<=N;i++)
		{
			int	t;
			
			t = find_max_transmission_time(i,N,connected);
			
			if( t < min_time )
			{
				start_broker = i;
				min_time = t;
			}
		}
		
		if( min_time == INF )
		{
			cout<<"disjoint\n";
		}
		else
		{
			cout<<start_broker<<' '<<min_time<<'\n';
		}
	}
	
	return	0;
}
