#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	INF			0x7FFFFFFF

#define	in_range(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int				N,M,A,B,K,G;
int				path[MAX_SIZE][MAX_SIZE];
pair<int,int>	disabled[MAX_SIZE][MAX_SIZE];	// first:from,second:to
vector<int>		connected[MAX_SIZE];

typedef	pair<int,int>	State;	// first:-time,second:intersection

void	input(vector<int>& path_of_king)
{
	cin>>N>>M>>A>>B>>K>>G;
	
	for(int i=1;i<=G;i++)
	{
		int	p;
		
		cin>>p;
		path_of_king.push_back(p);
	}
	
	for(int i=1;i<=M;i++)
	{
		int	u,v,l;
		
		cin>>u>>v>>l;
		
		path[u][v] = path[v][u] = l;
		connected[u].push_back(v);
		connected[v].push_back(u);
	}
}

void	update_path_of_king(vector<int>& path_of_king)
{
	for(int i=0,t=0;i<path_of_king.size()-1;i++)
	{
		int&	u = path_of_king[i];
		int&	v = path_of_king[i+1];
		
		disabled[u][v] = disabled[v][u] = make_pair(t,t+path[u][v]-1);
		t += path[u][v];
	}
}

int		find_shortest_path(void)
{
	priority_queue<State>	pq;
	vector<int>				dp(N+1,INF);
	
	dp[A] = K;
	pq.push(make_pair(-K,A));
	
	for(;!pq.empty();)
	{
		int	current_time,current_intersection;
		
		current_time = -pq.top().first;
		current_intersection = pq.top().second;
		
		pq.pop();
		
		if( current_intersection == B )
		{
			break;
		}
		
		for(int i=0;i<connected[current_intersection].size();i++)
		{
			int&	adj = connected[current_intersection][i];
			int&	disabled_start_time = disabled[current_intersection][adj].first;
			int&	disabled_end_time = disabled[current_intersection][adj].second;
			int		t;
			
			if( (disabled_start_time!=0||disabled_end_time!=0) &&
				in_range(disabled_start_time,current_time,disabled_end_time) )
			{
				t = disabled_end_time+1;
			}
			else
			{
				t = current_time;
			}
			
			if( t+path[current_intersection][adj] < dp[adj] )
			{
				dp[adj] = t+path[current_intersection][adj];
				pq.push(make_pair(-dp[adj],adj));
			}
		}
	}
	
	return	dp[B];
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	vector<int>	k;
	
	input(k);
	update_path_of_king(k);
	
	cout<<find_shortest_path()-K<<'\n';
	
	return	0;
}
