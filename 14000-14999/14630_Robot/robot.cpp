#include	<iostream>
#include	<string>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_STATE	(1000+1)
#define	char2int(c)			((int)((c)-'0'))

typedef	pair<int,int>	State;	// first:-cost, second:current_state

int		N,initial_state,final_state,state_len;
string	state[MAX_NUM_OF_STATE];

int		get_cost(int from_state_index,int to_state_index)
{
	int		cost,i;
	string&	from = state[from_state_index];
	string&	to = state[to_state_index];
	
	for(cost=i=0;i<state_len;i++)
	{
		int	diff;
		
		diff = char2int(from[i])-char2int(to[i]);
		cost += diff*diff;
	}
	
	return	cost;
}

int		find_min_cost(void)
{
	priority_queue<State>	pq;
	vector<int>				dp(N+1,0x7FFFFFFF);
	int						min_cost;
	
	pq.push(make_pair(0,initial_state));
	dp[initial_state] = 0;
	
	while( !pq.empty() )
	{
		int	current_state,current_cost;
		
		current_state = pq.top().second;
		current_cost = -pq.top().first;
		
		pq.pop();
		
		if( current_state == final_state )
		{
			min_cost = current_cost;
			break;	
		}
		
		for(int next_state=1;next_state<current_state;next_state++)
		{
			int	cost;
			
			cost = get_cost(current_state,next_state);
			
			if( cost < dp[next_state] )
			{
				dp[next_state] = cost;
				pq.push(make_pair(-(cost+current_cost),next_state));
			}
		}
		
		for(int next_state=current_state+1;next_state<=N;next_state++)
		{
			int	cost;
			
			cost = get_cost(current_state,next_state);
			
			if( cost < dp[next_state] )
			{
				dp[next_state] = cost;
				pq.push(make_pair(-(cost+current_cost),next_state));
			}
		}
	}
	
	return	min_cost;
}

int		main(void)
{
	cin.sync_with_stdio (false);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>state[i];
	}
	
	cin>>initial_state>>final_state;
	state_len = state[initial_state].length();
	
	cout<<find_min_cost()<<'\n';
	
	return	0;
}
