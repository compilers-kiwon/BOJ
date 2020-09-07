#include	<iostream>
#include	<vector>
#include	<queue>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(2000+1)
#define	INF			0x7FFFFFFF

typedef	pair<int,int>	State;		// first:-length,second:node
typedef	pair<int,int>	Path;		// first:to,second:length

void	input(int& n,vector<Path>* connected,
			  int& s,int& g,int& h,vector<int>& dest)
{
	int	m,t;
	
	cin>>n>>m>>t>>s>>g>>h;
	
	for(int i=1;i<=m;i++)
	{
		int	a,b,d;
		
		cin>>a>>b>>d;
		
		connected[a].push_back(make_pair(b,d));
		connected[b].push_back(make_pair(a,d));
	}
	
	for(int i=1;i<=t;i++)
	{
		int	x;
		
		cin>>x;
		dest.push_back(x);
	}
}

void	find_shortest_path(int n,int s,int g,int h,
						   vector<Path>* connected,
						   vector<int>& dest)
{
	priority_queue<State>	pq;
	vector<int>				dp(n+1,INF);
	vector<bool>			is_destination(n+1,false);
	vector<bool>			visited(n+1,false);
		
	dp[s] = 0;
	pq.push(make_pair(0,s));
		
	for(int i=0;i<dest.size();i++)
	{
		is_destination[dest[i]] = true;
	}
	
	for(;!pq.empty();)
	{
		int		current_length,current_node;
		bool	current_visited;
		
		current_length = -pq.top().first;
		current_node = pq.top().second;
		current_visited = visited[current_node];

		pq.pop();
		
		vector<Path>&	adj = connected[current_node];
	
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_node = adj[i].first;
			int&	adj_len = adj[i].second;
			bool	adj_visited;
			
			adj_visited = false;
			
			if( current_visited == true )
			{
				adj_visited = true;
			}
			else
			{
				if( (current_node==g&&adj_node==h) || (current_node==h&&adj_node==g) )
				{
					adj_visited = true;
				}
			}
			
			if( adj_len+current_length == dp[adj_node] )
			{
				visited[adj_node] = visited[adj_node]|adj_visited;
				continue;
			}
			
			if( adj_len+current_length < dp[adj_node] )
			{
				dp[adj_node] = adj_len+current_length;
				visited[adj_node] = adj_visited;
				pq.push(make_pair(-(adj_len+current_length),adj_node));
			}
		}
	}

	vector<int>	tmp;
	
	for(int i=0;i<dest.size();i++)
	{
		int&	d = dest[i];

		if( dp[d]!=INF && visited[d]==true )
		{
			tmp.push_back(d);
		}
	}
	
	for(int i=0;i<tmp.size()-1;i++)
	{
		cout<<tmp[i]<<' ';
	}
	cout<<tmp.back()<<'\n';
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int				n,s,g,h;
		vector<Path>	connected[MAX_SIZE];
		vector<int>		dest;
		
		input(n,connected,s,g,h,dest);
		sort(dest.begin(),dest.end());
		
		find_shortest_path(n,s,g,h,connected,dest);
	}
	
	return	0;
}
