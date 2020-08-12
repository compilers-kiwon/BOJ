#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_V	(100+1)
#define	INF				-2000000000

typedef	pair<int,int>	Path;		// first:to, second:profit

bool	find_optimal_path(int s,int e,int num_of_v,vector<Path>* connected,
						  int* path,vector<bool>& is_candidate)
{
	int		dp[MAX_NUM_OF_V];
	
	for(int i=1;i<MAX_NUM_OF_V;i++)
	{
		dp[i] = INF;
	}
	
	path[s] = -1;
	dp[s] = 0;
	
	for(int i=1;i<=num_of_v;i++)
	{
		bool	updated;
		
		updated = false;
		
		for(int v=1;v<=num_of_v;v++)
		{
			if( is_candidate[v] == false )
			{
				continue;
			}
			
			vector<Path>&	adj = connected[v];
					
			for(int e=0;e<adj.size();e++)
			{
				int&	adj_v = adj[e].first;
				int&	adj_p = adj[e].second;
				
				if( is_candidate[adj_v]==true && dp[v]!=INF && dp[v]+adj_p>dp[adj_v] )
				{
					dp[adj_v] = dp[v]+adj_p;
					path[adj_v] = v;
					updated = true;
				}
			}
		}
		
		if( i==num_of_v && updated==true )
		{
			return	false;
		}
	}
	
	return	(dp[e]!=INF);
}

void	get_candidates(vector<int>* r,vector<bool>& t,int e)
{
	queue<int>		vq;
	
	vq.push(e);
	t[e] = true;
	
	for(;!vq.empty();)
	{
		int	v;
		
		v = vq.front();
		vq.pop();
		
		vector<int>& adj = r[v];
		
		for(int i=0;i<adj.size();i++)
		{
			if( t[adj[i]] == false )
			{
				t[adj[i]] = true;
				vq.push(adj[i]);
			}
		}
	}
}

void	input(int& num_of_v,int& num_of_e,
			  vector<Path>* connected,vector<int>* reverse)
{
	cin>>num_of_v>>num_of_e;
	
	for(int i=1;i<=num_of_e;i++)
	{
		int	u,v,w;
		
		cin>>u>>v>>w;
		connected[u].push_back(make_pair(v,w));
		reverse[v].push_back(u);
	}
}

int		main(void)
{
	//cin.tie(NULL);
	//cin.sync_with_stdio(false);
	
	int				n,m,path[MAX_NUM_OF_V];
	vector<Path>	connected[MAX_NUM_OF_V];
	vector<int>		reverse[MAX_NUM_OF_V];
	vector<bool>	is_candidate;
	
	input(n,m,connected,reverse);
	
	is_candidate.resize(n+1,false);
	get_candidates(reverse,is_candidate,n);
	
	if( is_candidate[1]==false || 
		find_optimal_path(1,n,n,connected,path,is_candidate)==false )
	{
		cout<<"-1\n";
	}
	else
	{
		vector<int>	p;
		
		for(int i=n;i!=-1;i=path[i])
		{
			p.push_back(i);
		}
		
		for(int i=p.size()-1;i>=0;i--)
		{
			cout<<p[i]<<' ';
		}
		cout<<'\n';
	}
	
	return	0;
}
