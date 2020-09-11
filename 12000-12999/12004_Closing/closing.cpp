#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_BARNS	(3000+1)

int			N,M,num_of_closed_barns;
vector<int>	connected[MAX_NUM_OF_BARNS];
vector<int>	closing_order;
bool		already_closed[MAX_NUM_OF_BARNS];

void	init(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=M;i++)
	{
		int	b1,b2;
		
		cin>>b1>>b2;
		connected[b1].push_back(b2);
		connected[b2].push_back(b1);
	}
	
	for(int i=1;i<=N;i++)
	{
		int	c;
		
		cin>>c;
		closing_order.push_back(c);
	}
}

bool	close(int s_barn)
{
	queue<int>		closed;
	int				cnt;
	vector<bool>	visited(N+1,false);
	
	visited[s_barn] = true;
	cnt = 1;
	closed.push(s_barn);
	
	while( !closed.empty() )
	{
		int	current_closed_barn;
		
		current_closed_barn = closed.front();
		closed.pop();
		
		vector<int>&	adj_barns = connected[current_closed_barn];
		
		for(int i=0;i<adj_barns.size();i++)
		{
			int&	adj_barn = adj_barns[i];
			
			if( already_closed[adj_barn]==false && visited[adj_barn]==false )
			{
				visited[adj_barn] = true;
				cnt++;
				closed.push(adj_barn);
			}
		}
	}
	
	bool	result;
	
	if( cnt == N-num_of_closed_barns )
	{
		result = true;
	}
	else
	{
		result = false;
	}
	
	already_closed[s_barn] = true;
	num_of_closed_barns++;

	return	result;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	init();
	
	for(int i=0;i<closing_order.size();i++)
	{
		if( close(closing_order[i]) == true )
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	
	return	0;
}
