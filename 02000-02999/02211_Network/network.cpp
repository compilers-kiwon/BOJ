#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	INF			0x7FFFFFFF

typedef	pair<int,int>	Circuit;	// first:adj_computer,second:time
typedef	pair<int,int>	Repair;		// first:computer1,second:computer2
typedef	pair<int,int>	State;		// first:-time,second:computer

int				N,M,dp[MAX_SIZE];
vector<Circuit>	connected[MAX_SIZE];

void	input(void)
{
	cin>>N>>M;
	
	fill(&dp[1],&dp[N+1],INF);

	for(int i=1;i<=M;i++)
	{
		int	A,B,C;
		
		cin>>A>>B>>C;
		
		connected[A].push_back(make_pair(B,C));
		connected[B].push_back(make_pair(A,C));
	}
}

void	find_best_network(void)
{
	priority_queue<State>	pq;
	bool					visited[MAX_SIZE];
	
	dp[1] = 0;
	pq.push(make_pair(0,1));
	
	fill(&visited[1],&visited[N+1],false);
	
	for(;!pq.empty();)
	{
		int	current_time,current_computer;
		
		current_time = -pq.top().first;
		current_computer = pq.top().second;
		
		pq.pop();
		
		if( visited[current_computer] == true )
		{
			continue;
		}
		
		visited[current_computer] = true;
		
		vector<Circuit>&	adj_circuit = connected[current_computer];
		
		for(int i=0;i<adj_circuit.size();i++)
		{
			int&	adj_computer = adj_circuit[i].first;
			int&	adj_time = adj_circuit[i].second;
			
			if( current_time+adj_time < dp[adj_computer] )
			{
				dp[adj_computer] = current_time+adj_time;
				pq.push(make_pair(-(current_time+adj_time),adj_computer));
			}
		}
	}
}

void	get_repaired_circuit(vector<Repair>& r)
{
	for(int current_computer=1;current_computer<=N;current_computer++)
	{
		vector<Circuit>&	adj_circuit = connected[current_computer];
		
		for(int i=0;i<adj_circuit.size();i++)
		{
			int&	adj_computer = adj_circuit[i].first;
			int&	adj_time = adj_circuit[i].second;
			
			if( dp[current_computer]-adj_time == dp[adj_computer] )
			{
				r.push_back(make_pair(current_computer,adj_computer));
				break;
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	vector<Repair>	repaired;
	
	input();
	find_best_network();
	get_repaired_circuit(repaired);
	
	cout<<repaired.size()<<'\n';
	
	for(int i=0;i<repaired.size();i++)
	{
		cout<<repaired[i].first<<' '<<repaired[i].second<<'\n';
	}
	
	return	0;
}
