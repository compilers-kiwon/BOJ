#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

typedef	long long int	int64;
typedef	pair<int,int64>	Bus;	// first:to,second:time

#define	MAX_SIZE	(500+1)
#define	MAX_BUS		(6000+1)
#define	INF			0x7FFFFFFFFFFFFFFF

vector<Bus>	bus[MAX_BUS];

void	init(int& num_of_city,int& num_of_bus)
{
	int64	bus_time[MAX_SIZE][MAX_SIZE];
	
	cin>>num_of_city>>num_of_bus;
	
	for(int i=1;i<=num_of_city;i++)
	{
		fill(&bus_time[i][1],&bus_time[i][num_of_city+1],INF);
	}
	
	for(int i=1;i<=num_of_bus;i++)
	{
		int		A,B;
		int64	C;
		
		cin>>A>>B>>C;
		bus_time[A][B] = min(bus_time[A][B],C);
	}
	
	for(int from=1;from<=num_of_city;from++)
	{
		for(int to=1;to<=num_of_city;to++)
		{
			if( bus_time[from][to] != INF )
			{
				bus[from].push_back(make_pair(to,bus_time[from][to]));
			}
		}
	}
}

bool	find_cycle(int num_of_city,int num_of_bus,vector<int64>& time_table)
{
	queue<int>		city_q;
	vector<bool>	in_q(num_of_city+1,false);
	int				cnt_of_update;
		
	city_q.push(1);
	in_q[1] = true;
	
	time_table[1] = 0;
	cnt_of_update = 0;
	
	while( city_q.size() != 0 )
	{
		if( cnt_of_update > num_of_city*num_of_bus )
		{
			return	true;
		}
		cnt_of_update++;
		
		int		current_city;
		int64	current_time;
		
		current_city = city_q.front();
		current_time = time_table[current_city];
		
		city_q.pop();
		in_q[current_city] = false;
		
		vector<Bus>&	adj_bus = bus[current_city];
		
		for(int i=0;i<adj_bus.size();i++)
		{
			int&	to_city = adj_bus[i].first;
			int64&	to_time = adj_bus[i].second;
			
			if( current_time+to_time < time_table[to_city] )
			{
				time_table[to_city] = current_time+to_time;
				
				if( in_q[to_city] == false )
				{
					city_q.push(to_city);
					in_q[to_city] = true;
				}
			}
		}
	}
	
	return	false;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int		N,M,t;
		
	init(N,M);
	
	vector<int64>		time_table(N+1,INF);
	
	if( find_cycle(N,M,time_table) == true )
	{
		cout<<"-1\n";
	}
	else
	{
		for(int i=2;i<=N;i++)
		{
			if( time_table[i] == INF )
			{
				time_table[i] = -1;
			}
			cout<<time_table[i]<<'\n';
		}
	}
	
	return	0;
}
