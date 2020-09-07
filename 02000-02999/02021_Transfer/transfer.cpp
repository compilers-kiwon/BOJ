#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(100000+1)
#define	INF			0x7FFFFFFF

int			N,L,s,d;
bool		visited_line[MAX_SIZE];
vector<int>	line_at_station[MAX_SIZE];
vector<int>	stations_in_line[MAX_SIZE];

typedef	pair<int,int>	State;	// first:-num_of_transfer,second:station

void	input(void)
{
	cin>>N>>L;
	
	for(int i=1;i<=L;i++)
	{
		for(;;)
		{
			int	station;
			
			cin>>station;
			
			if( station == -1 )
			{
				break;
			}
			
			line_at_station[station].push_back(i);
			stations_in_line[i].push_back(station);
		}
	}
	
	cin>>s>>d;
}

int		find_min_transfer(void)
{
	priority_queue<State>	pq;
	vector<int>				dp(N+1,INF);
	
	pq.push(make_pair(-(-1),s));
	
	for(;!pq.empty();)
	{
		int	current_num_of_transfer,current_station;
		
		current_num_of_transfer = -pq.top().first;
		current_station = pq.top().second;
		
		pq.pop();
		
		if( current_station == d )
		{
			break;
		}
		
		vector<int>&	accessible_line = line_at_station[current_station];
		
		for(int i=0;i<accessible_line.size();i++)
		{
			if( visited_line[accessible_line[i]] == true )
			{
				continue;
			}
			
			visited_line[accessible_line[i]] = true;
			
			vector<int>&	stations = stations_in_line[accessible_line[i]];
			
			for(int j=0;j<stations.size();j++)
			{
				int&	accessible_station = stations[j];
				
				if( current_num_of_transfer+1 < dp[accessible_station] )
				{
					dp[accessible_station] = current_num_of_transfer+1;
					pq.push(make_pair(-(current_num_of_transfer+1),accessible_station));
				}
			}
		}
	}
	
	return	((dp[d]==INF)?-1:dp[d]);
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	if( s == d )
	{
		cout<<"0\n";
		return	0;
	}
	
	cout<<find_min_transfer()<<'\n';
	
	return	0;
}
