#include	<iostream>
#include	<queue>
#include	<string>

using namespace	std;

#define	MAX_SIZE	16
#define	MAX_DP		(1<<MAX_SIZE)
#define	INF			0x7FFFFFFF

int	N,dp[MAX_DP][MAX_SIZE];
int	cost_table[MAX_SIZE][MAX_SIZE];
int	power_state,P;

typedef	pair<int,int>	State;	// first:-cost,second:available_plants

void	input(void)
{
	cin>>N;
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>cost_table[i][j];
		}
	}
	
	string	str;
	
	cin>>str>>P;
	power_state = 0;
	
	for(int i=0;i<N;i++)
	{
		if( str[i] == 'Y' )
		{
			power_state |= 1<<i;
		}
	}
	
	for(int i=0;i<(1<<N);i++)
	{
		fill(&dp[i][0],&dp[i][N],INF);
	}
}

int		get_num_of_available_plants(int n)
{
	int	ret;
	
	ret = 0;
	
	for(int i=0;i<N;i++)
	{
		if( (n&(1<<i)) != 0 )
		{
			ret++;
		}
	}
	
	return	ret;
}

int		get_min_cost(void)
{
	int						ret;
	priority_queue<State>	pq;
	
	pq.push(make_pair(0,0));
	
	for(int i=0;i<N;i++)
	{
		if( (power_state&(1<<i)) != 0 )
		{
			dp[power_state][i] = 0;
			pq.push(make_pair(0,power_state));
		}
	}
	
	for(ret=INF;!pq.empty();)
	{
		int	current_cost,current_available_plants;
		
		current_cost = -pq.top().first;
		current_available_plants = pq.top().second;
		
		pq.pop();
		
		if( get_num_of_available_plants(current_available_plants) >= P )
		{
			ret = current_cost;
			break;
		}
		
		for(int i=0;i<N;i++)
		{
			if( (current_available_plants&(1<<i)) == 0 )
			{
				int	min_cost;
				
				min_cost = INF;
				
				for(int j=0;j<N;j++)
				{
					if( (current_available_plants&(1<<j)) != 0 )
					{
						min_cost = min(min_cost,current_cost+cost_table[j][i]);
					}
				}
				
				if( min_cost < dp[(current_available_plants|(1<<i))][i] )
				{
					dp[(current_available_plants|(1<<i))][i] = min_cost;
					pq.push(make_pair(-min_cost,(current_available_plants|(1<<i))));
				}
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	ret;
	
	input();
	
	ret = get_min_cost();
	
	if( ret == INF )
	{
		ret = -1;
	}
	
	cout<<ret<<'\n';
	
	return	0;
}
