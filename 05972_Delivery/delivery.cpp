#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(50000+1)
#define	INF			0x7FFFFFFF

typedef	pair<int,int>	Path;	// fisrt:barn,second:feed
typedef	pair<int,int>	State;	// first:-feed,second:barn

int				N,M;
vector<Path>	connected[MAX_SIZE];

void	input(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=M;i++)
	{
		int	A,B,C;
		
		cin>>A>>B>>C;
		
		connected[A].push_back(make_pair(B,C));
		connected[B].push_back(make_pair(A,C));
	}
}

int		find_best_path(void)
{
	priority_queue<State>	pq;
	vector<int>				dp(N+1,INF);
	
	dp[1] = 0;
	pq.push(make_pair(0,1));
	
	for(;!pq.empty();)
	{
		int	current_feed,current_barn;
		
		current_feed = -pq.top().first;
		current_barn = pq.top().second;
		
		pq.pop();
		
		if( current_barn == N )
		{
			break;
		}
		
		vector<Path>&	p = connected[current_barn];
		
		for(int i=0;i<p.size();i++)
		{
			int&	adj_barn = p[i].first;
			int&	adj_feed = p[i].second;
			
			if( current_feed+adj_feed < dp[adj_barn] )
			{
				dp[adj_barn] = current_feed+adj_feed;
				pq.push(make_pair(-dp[adj_barn],adj_barn));
			}
		}
	}
	
	return	dp[N];
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<find_best_path()<<'\n';
	
	return	0;
}
