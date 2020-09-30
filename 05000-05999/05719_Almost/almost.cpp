#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_V	500
#define	MAX_NUM_OF_E	(10000+1)
#define	INF				0x7FFFFFFF

typedef	pair<int,int>	State;	//first:-cost, second:current_v
typedef	pair<int,int>	Path;	//first:from/to, second:edge_no

int		N,M,S,D,e[MAX_NUM_OF_E];
int		dp[MAX_NUM_OF_V];
bool	blocked[MAX_NUM_OF_E],reverse_visited[MAX_NUM_OF_V];

bool	input(vector<Path>* connected,vector<Path>* reverse)
{
	cin>>N>>M;
	
	if( N==0 && M==0 )
	{
		return	false;
	}
	
	cin>>S>>D;
	
	for(int i=1;i<=M;i++)
	{
		int		U,V;
		int&	P = e[i];
		
		cin>>U>>V>>P;
		connected[U].push_back(make_pair(V,i));
		reverse[V].push_back(make_pair(U,i));
	}
	
	return	true;
}

void	find_shortest_path(vector<Path>* connected)
{
	priority_queue<State>	pq;
	
	dp[S] = 0;
	pq.push(make_pair(0,S));
	
	for(;!pq.empty();)
	{
		int	current_cost,current_v;
		
		current_cost = -pq.top().first;
		current_v = pq.top().second;
		
		pq.pop();
		
		if( current_v == D )
		{
			continue;
		}
		
		vector<Path>&	adj = connected[current_v];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_v = adj[i].first;
			int&	adj_e = adj[i].second;

			if( blocked[adj_e]==false && current_cost+e[adj_e]<dp[adj_v] )
			{
				dp[adj_v] = current_cost+e[adj_e];
				pq.push(make_pair(-dp[adj_v],adj_v));
			}
		}
	}
}

void	remove_edge(vector<Path>* reverse)
{
	priority_queue<State>	pq;
	
	reverse_visited[D] = true;
	pq.push(make_pair(-dp[D],D));
	
	for(;!pq.empty();)
	{
		int	current_cost,current_v;
		
		current_cost = -pq.top().first;
		current_v = pq.top().second;
		
		pq.pop();

		if( current_v == S )
		{
			continue;
		}
		
		vector<Path>&	adj = reverse[current_v];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_v = adj[i].first;
			int&	adj_e = adj[i].second;
			
			if( dp[adj_v] == current_cost-e[adj_e] )
			{
				blocked[adj_e] = true;
					
				if( reverse_visited[adj_v] == false )
				{
					pq.push(make_pair(-dp[adj_v],adj_v));
					reverse_visited[adj_v] = true;
				}
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		vector<Path>	connected[MAX_NUM_OF_V];
		vector<Path>	reverse[MAX_NUM_OF_V];
		
		if( input(connected,reverse) == false )
		{
			break;
		}
		
		fill(&dp[0],&dp[N],INF);
		fill(&blocked[1],&blocked[M+1],false);
		
		find_shortest_path(connected);
		
		fill(&reverse_visited[0],&reverse_visited[N],false);
		remove_edge(reverse);
		
		fill(&dp[0],&dp[N],INF);
		find_shortest_path(connected);
		
		if( dp[D] == INF )
		{
			cout<<"-1\n";
		}
		else
		{
			cout<<dp[D]<<'\n';
		}
	}
	
	return	0;
}
