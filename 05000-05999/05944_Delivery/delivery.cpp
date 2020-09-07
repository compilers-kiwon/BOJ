#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(100000+1)
#define	INF			0x7FFFFFFF

typedef	pair<int,int>	Path;	// first:to,second:time
typedef	pair<int,int>	State;	// first:-time,second:pos

int						C,P,PB,PA1,PA2;
vector<Path>			connected[MAX_SIZE];
priority_queue<State>	pq;

void	input(void)
{
	cin>>C>>P>>PB>>PA1>>PA2;
	
	for(int i=1;i<=C;i++)
	{
		int	P1,P2,D;
		
		cin>>P1>>P2>>D;
		
		connected[P1].push_back(make_pair(P2,D));
		connected[P2].push_back(make_pair(P1,D));
	}
}

int		get_shortest_time(int from,int to)
{
	priority_queue<State>	pq;
	vector<int>				dp(P+1,INF);
	
	dp[from] = 0;
	pq.push(make_pair(0,from));
	
	for(;!pq.empty();)
	{
		int	current_time,current_pos;
		
		current_time = -pq.top().first;
		current_pos = pq.top().second;
		
		pq.pop();
		
		if( current_pos == to )
		{
			break;
		}
		
		vector<Path>&	p = connected[current_pos];
		
		for(int i=0;i<p.size();i++)
		{
			int&	adj_pos = p[i].first;
			int&	travel_time = p[i].second;
			
			if( current_time+travel_time < dp[adj_pos] )
			{
				dp[adj_pos] = current_time+travel_time;
				pq.push(make_pair(-dp[adj_pos],adj_pos));
			}
		}
	}
	
	return	dp[to];
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	int	PB_PA1,PB_PA2,PA1_PA2;
	
	PB_PA1 = get_shortest_time(PB,PA1);
	PB_PA2 = get_shortest_time(PB,PA2);
	PA1_PA2 = get_shortest_time(PA1,PA2);
	
	cout<<min(PB_PA1,PB_PA2)+PA1_PA2<<'\n';
	
	return	0;
}
