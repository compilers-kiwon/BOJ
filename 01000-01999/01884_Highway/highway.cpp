#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(100+1)
#define	MAX_BUDGET	10000
#define	INF			0x7FFFFFFF

typedef	struct{int to,length,cost;}	Path;
typedef	pair< int,pair<int,int> >	State;	// first:-length,<first:city,second:budget>

int				K,N,R,dp[MAX_SIZE][MAX_BUDGET+1];
vector<Path>	connected[MAX_SIZE];

void	input(void)
{
	cin>>K>>N>>R;
	
	for(int i=1;i<=R;i++)
	{
		int		from;
		Path	p;
		
		cin>>from>>p.to>>p.length>>p.cost;
		connected[from].push_back(p);
	}
	
	for(int i=2;i<=N;i++)
	{
		fill(&dp[i][0],&dp[i][K+1],INF);
	}
}

int		find_shortest_path(void)
{
	int						ret;
	priority_queue<State>	state_q;
	
	ret = INF;
	state_q.push(make_pair(0,make_pair(1,K)));
	
	for(;!state_q.empty();)
	{
		int	current_length,current_city,current_budget;
		
		current_length = -state_q.top().first;
		current_city = state_q.top().second.first;
		current_budget = state_q.top().second.second;
		
		state_q.pop();
		
		if( current_city == N )
		{
			ret = min(ret,current_length);
			continue;
		}
		
		vector<Path>&	adj = connected[current_city];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_city = adj[i].to;
			int&	adj_length = adj[i].length;
			int&	adj_cost = adj[i].cost;
			
			int		next_budget;
			int		next_length;
			
			next_budget = current_budget-adj_cost;
			next_length = current_length+adj_length;
			
			if( next_budget<0 || dp[adj_city][current_budget-adj_cost]<=next_length )
			{
				continue;
			}
			
			dp[adj_city][current_budget-adj_cost] = next_length;
			state_q.push(make_pair(-next_length,make_pair(adj_city,next_budget)));
		}
	}
	
	return	((ret==INF)?-1:ret);
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<find_shortest_path()<<'\n';
	
	return	0;
}
