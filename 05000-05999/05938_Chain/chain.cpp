#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(250+1)

void	input(int& num_of_cows,vector<int>* connected)
{
	int	num_of_ropes;
	
	cin>>num_of_cows>>num_of_ropes;
	
	for(int i=1;i<=num_of_ropes;i++)
	{
		int	c1,c2;
		
		cin>>c1>>c2;
		
		connected[c1].push_back(c2);
		connected[c2].push_back(c1);
	}
}

int		visit_chain(vector<int>* connected,bool* visited)
{
	int			ret;
	queue<int>	cow_q;
	
	ret = 1;
	cow_q.push(1);
	visited[1] = true;
	
	for(;!cow_q.empty();)
	{
		int	current_cow;
		
		current_cow = cow_q.front();
		cow_q.pop();
		
		vector<int>&	adj = connected[current_cow];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_cow = adj[i];
			
			if( visited[adj_cow] == false )
			{
				ret++;
				cow_q.push(adj_cow);
				visited[adj_cow] = true;
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int			N;
	bool		visited[MAX_SIZE];
	vector<int>	connected[MAX_SIZE];
	
	input(N,connected);
	fill(&visited[1],&visited[N+1],false);
	
	if( visit_chain(connected,visited) == N )
	{
		cout<<"0\n";
	}
	else
	{
		for(int i=1;i<=N;i++)
		{
			if( visited[i] == false )
			{
				cout<<i<<'\n';
			}
		}
	}
	
	return	0;
}
