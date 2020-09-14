#include	<iostream>
#include	<queue>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(10+1)
#define	INF			0x7FFFFFFF

int			N,population[MAX_SIZE];
vector<int>	connected[MAX_SIZE];

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>population[i];
	}
	
	for(int i=1;i<=N;i++)
	{
		int	adj;
		
		cin>>adj;
		
		for(int j=1;j<=adj;j++)
		{
			int	c;
			
			cin>>c;
			connected[i].push_back(c);
		}
	}
}

bool	is_connected(vector<int>& g,int& num_of_people)
{
	if( g.size() == 0 )
	{
		return	false;
	}
	
	queue<int>	q;
	bool		visited[MAX_SIZE];
	bool		is_group[MAX_SIZE];
	int			cnt;
	
	for(int i=1;i<=N;i++)
	{
		visited[i] = is_group[i] = false;
	}
	
	num_of_people = 0;
	
	for(int i=0;i<g.size();i++)
	{
		is_group[g[i]] = true;
		num_of_people += population[g[i]];
	}
	
	cnt = 1;
	q.push(g[0]);
	visited[g[0]] = true;
	
	for(;!q.empty();)
	{
		int	current;
		
		current = q.front();
		q.pop();
		
		vector<int>&	adj = connected[current];
		
		for(int i=0;i<adj.size();i++)
		{
			if( is_group[adj[i]]==true && visited[adj[i]]==false )
			{
				visited[adj[i]] = true;
				q.push(adj[i]);
				cnt++;
			}
		}
	}
	
	return	(cnt==g.size());
}

void	build_group(int current,vector<int>& g1,vector<int>& g2,int& min_diff)
{
	if( current > N )
	{
		int	g1_num,g2_num;
		
		if( is_connected(g1,g1_num)==true && is_connected(g2,g2_num)==true )
		{
			min_diff = min(min_diff,abs(g1_num-g2_num));
		}
		
		return;
	}
	
	g1.push_back(current);
	build_group(current+1,g1,g2,min_diff);
	g1.pop_back();
	
	g2.push_back(current);
	build_group(current+1,g1,g2,min_diff);
	g2.pop_back();
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	min_diff;
	
	input();
	min_diff = INF;
	
	vector<int>	g1,g2;
	
	g1.push_back(1);
	build_group(2,g1,g2,min_diff);
	
	if( min_diff == INF )
	{
		min_diff = -1;
	}

	cout<<min_diff<<'\n';
	
	return	0;
}
