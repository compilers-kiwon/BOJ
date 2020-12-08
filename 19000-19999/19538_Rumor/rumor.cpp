#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(200000+1)
#define	NONE		0x7FFFFFFF

int			N,M,dp[MAX_SIZE];
vector<int>	connected[MAX_SIZE];

typedef	pair<int,int>	State;	// first:a person to believe rumor, second:time

void	input(queue<State>& q)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		for(;;)
		{
			int	adj;
			
			cin>>adj;
			
			if( adj == 0 )
			{
				break;
			}
			
			connected[i].push_back(adj);
		}
		
		dp[i] = NONE;
	}
	
	cin>>M;
	
	for(int i=1;i<=M;i++)
	{
		int	n;
		
		cin>>n;
		
		dp[n] = 0;
		q.push(make_pair(n,0));
	}
}

int		count_rumors(int p)
{
	int	ret;
	
	ret = 0;
	
	for(int i=0;i<connected[p].size();i++)
	{
		if( dp[connected[p][i]] != NONE )
		{
			ret++;
		}
	}
	
	return	ret;
}

void	simulate(queue<State>& rumor)
{
	for(;!rumor.empty();)
	{
		int	current_person;
		int	current_time;
		
		current_person = rumor.front().first;
		current_time = rumor.front().second;
		
		rumor.pop();
		dp[current_person] = min(dp[current_person],current_time);
		
		vector<int>&	adj = connected[current_person];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_person = adj[i];
			int		num_of_adj_rumors;
			
			if( dp[adj_person] != NONE )
			{
				continue;
			}
			
			num_of_adj_rumors = count_rumors(adj_person);
			
			if( 2*num_of_adj_rumors >= connected[adj_person].size() )
			{
				rumor.push(make_pair(adj_person,current_time+1));
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	queue<State>	rumor;
	
	input(rumor);
	simulate(rumor);
	
	for(int i=1;i<=N;i++)
	{
		if( dp[i] != NONE )
		{
			cout<<dp[i]<<' ';
		}
		else
		{
			cout<<"-1 ";
		}
	}
	
	cout<<'\n';
	
	return	0;
}
