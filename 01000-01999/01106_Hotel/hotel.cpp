#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_CITY	(20+1)
#define	MAX_PROFIT		2000
#define	INF				0x7FFFFFFF

typedef	pair<int,int>	City;	// first:cost,second:profit
typedef	pair<int,int>	State;	// first:current_cost,second:current_profit

int		C,N,dp[MAX_PROFIT];
City	city[MAX_NUM_OF_CITY];

void	input(void)
{
	cin>>C>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>city[i].first>>city[i].second;
	}
	
	fill(&dp[0],&dp[MAX_PROFIT],INF);
}

int		promote(void)
{
	int				ret;
	queue<State>	state_q;
	
	dp[0] = 0;
	state_q.push(make_pair(0,0));
	
	for(ret=INF;!state_q.empty();)
	{
		int	current_cost,current_profit;
		
		current_cost = state_q.front().first;
		current_profit = state_q.front().second;
		
		state_q.pop();
		
		if( current_profit >= C )
		{
			ret = min(ret,current_cost);
			continue;
		}
		
		for(int i=1;i<=N;i++)
		{
			int	next_cost,next_profit;
			
			next_cost = current_cost+city[i].first;
			next_profit = current_profit+city[i].second;
			
			if( next_cost < dp[next_profit] )
			{
				dp[next_profit] = next_cost;
				state_q.push(make_pair(next_cost,next_profit));
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<promote()<<'\n';
	
	return	0;
}
