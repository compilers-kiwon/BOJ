#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(500+1)
#define	MAX_TIME	24

#define	INF			0x7FFFFFFF
#define	START		1

typedef	pair<int,int>		Query;		// first:destination,second:department_time
typedef	pair<int,int>		Arrival;	// first:arrival_city,second:arrival_time	
typedef	pair<int,Arrival>	State;		// first:-cost,second:Arrival

int	N,M,K,dp[MAX_SIZE][MAX_TIME];
int	cost_table[MAX_SIZE][MAX_SIZE][MAX_TIME];

void	input(vector<int>* connected,vector<Query>& q)
{
	cin>>N>>M>>K;
	
	for(int i=1;i<=M;i++)
	{
		int	x,y;
		
		cin>>x>>y;
		
		connected[x].push_back(y);
		connected[y].push_back(x);
		
		for(int t=0;t<MAX_TIME;t++)
		{
			int c;
			
			cin>>c;
			cost_table[x][y][t] = cost_table[y][x][t] = c;
		}
	}
	
	for(int i=1;i<=K;i++)
	{
		int	D,S;
		
		cin>>D>>S;
		q.push_back(make_pair(D,S));
	}
}

void	init_dp(void)
{
	for(int d=1;d<=N;d++)
	{
		fill(&dp[d][0],&dp[d][MAX_TIME],INF);
	}

}

int		find_best_path(int destination,int department_time,vector<int>* connected)
{
	int						ret;
	priority_queue<State>	state_q;
	
	init_dp();
	dp[START][department_time] = 0;
	
	ret = INF;
	state_q.push(make_pair(0,make_pair(START,department_time)));
	
	for(;!state_q.empty();)
	{
		int	current_cost,current_city,current_time;
		
		current_cost = -state_q.top().first;
		current_city = state_q.top().second.first;
		current_time = state_q.top().second.second;
		
		state_q.pop();
		
		if( current_city == destination )
		{
			ret = current_cost;
			break;
		}
		
		for(int i=0;i<connected[current_city].size();i++)
		{
			int&	adj_city = connected[current_city][i];
			int&	adj_cost = cost_table[current_city][adj_city][current_time];
			int		adj_time;
			
			adj_time = (current_time+adj_cost)%MAX_TIME;
			
			if( current_cost+adj_cost < dp[adj_city][adj_time] )
			{
				dp[adj_city][adj_time] = current_cost+adj_cost;
				state_q.push(make_pair(-(current_cost+adj_cost),make_pair(adj_city,adj_time)));
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		vector<int>		connected[MAX_SIZE];
		vector<Query>	query;
		vector<int>		answers;
		
		input(connected,query);
		
		for(int i=0;i<query.size();i++)
		{
			int	a;
			
			a = find_best_path(query[i].first,query[i].second,connected);
			
			if( a == INF )
			{
				a = -1;
			}
			
			answers.push_back(a);
		}
		
		cout<<"Case #"<<t<<":";
		
		for(int i=0;i<answers.size();i++)
		{
			cout<<' '<<answers[i];
		}
		
		cout<<'\n';
	}
	
	return	0;
}
