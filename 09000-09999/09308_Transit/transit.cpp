#include	<iostream>
#include	<vector>
#include	<queue>
#include	<map>

using namespace	std;

#define	MAX_NUM_OF_STOPS	(99999+1)
#define	INF					0x7FFFFFFF

typedef	struct	_BUS_INFO	Bus;
struct	_BUS_INFO
{
	int	arrival_time;
	int	destination_stop;
	int	time_to_be_taken;
};

typedef	pair<int,int>	Trace;	// first:-num_of_visited_bus_stops, second:current_bus_stop 
typedef	pair<int,Trace>	State;	// first:-current_travel_time, second:Trace	
typedef	vector<Bus>		vecBus;

bool	input(priority_queue<State>& pq,vector<int>& dp,
			  map<int,vecBus>& bus_at_stop,int& destination)
{
	int	W,R;
	
	cin>>W;
	
	if( W == 0 )
	{
		return	false;
	}
	
	dp.resize(MAX_NUM_OF_STOPS,INF);
	
	for(int i=1;i<=W;i++)
	{
		int		bus_stop_id,walking_time;
		Trace	t;
		
		cin>>bus_stop_id>>walking_time;
		
		t = make_pair(-1,bus_stop_id);
		pq.push(make_pair(-walking_time,t));
		dp[bus_stop_id] = walking_time;
	}
	
	cin>>R;
	
	for(int i=1;i<=R;i++)
	{
		int	current_bus_stop;
		Bus	b;
		
		cin>>current_bus_stop>>b.arrival_time>>b.destination_stop>>b.time_to_be_taken;
		bus_at_stop[current_bus_stop].push_back(b);
	}
	
	cin>>destination;
	
	return	true;
}

int		find_optimal_path(priority_queue<State>& pq,map<int,vecBus>& bus_at_stop,
						  vector<int>& prev_stop,vector<int>& dp,int dest)
{
	int	ret;
	
	ret = INF;
	
	for(;!pq.empty();)
	{
		int	current_travel_time,num_of_visited_stops,current_stop;
		
		current_travel_time = -pq.top().first;
		num_of_visited_stops = -pq.top().second.first;
		current_stop = pq.top().second.second;
		
		pq.pop();
		
		if( current_stop == dest )
		{
			ret = current_travel_time;
			break;
		}
		
		vecBus&	bus = bus_at_stop[current_stop];
		
		for(int i=0;i<bus.size();i++)
		{
			Bus&	current_bus = bus[i];
			int		next_arrival_time;
			
			if( current_bus.arrival_time < current_travel_time )
			{
				continue;
			}
			
			next_arrival_time = current_bus.arrival_time+current_bus.time_to_be_taken;
			
			if( next_arrival_time < dp[current_bus.destination_stop] )
			{
				Trace	t;
				
				t = make_pair(-(num_of_visited_stops+1),current_bus.destination_stop);
				prev_stop[current_bus.destination_stop] = current_stop;
				
				dp[current_bus.destination_stop] = next_arrival_time;
				pq.push(make_pair(-next_arrival_time,t));
			}	
		}
	}
	
	return	ret;
}

void	print(int time,vector<int>& prev_stop,int dest)
{
	vector<int>	path;
	
	for(int stop=dest;stop!=-1;stop=prev_stop[stop])
	{
		path.push_back(stop);
	}
	
	cout<<"ETA: "<<time<<" minute(s) Take stop: ";
	
	for(int i=path.size()-1;i>0;i--)
	{
		printf("%05d ",path[i]);
	}
	printf("%05d\n",path[0]);
}

int		main(void)
{
	cin.tie(NULL);
	//cin.sync_with_stdio(false);
	
	for(;;)
	{
		priority_queue<State>	pq;
		vector<int>				dp,prev_stop;
		map<int,vecBus> 		bus_at_stop;
		int						dest_bus_stop,optimal_time;
				
		if( input(pq,dp,bus_at_stop,dest_bus_stop) == false )
		{
			break;
		}
		
		prev_stop.resize(MAX_NUM_OF_STOPS,-1);
		
		optimal_time = find_optimal_path(pq,bus_at_stop,prev_stop,dp,dest_bus_stop);
		
		if( optimal_time == INF )
		{
			cout<<"Unreachable\n";
		}
		else
		{
			print(optimal_time,prev_stop,dest_bus_stop);
		}
	}
	
	return	0;
}
