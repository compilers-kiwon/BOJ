#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<stack>

using namespace	std;

#define	MAX_SIZE	(10000+1)

int			V,E,scc_head[MAX_SIZE];
vector<int>	original[MAX_SIZE],reversed[MAX_SIZE],scc[MAX_SIZE];
stack<int>	st;
bool		visited[MAX_SIZE];

void	input(void)
{
	cin>>V>>E;
	
	for(int i=1;i<=E;i++)
	{
		int	A,B;
		
		cin>>A>>B;
		original[A].push_back(B);
		reversed[B].push_back(A);
	}
}

void	original_dfs(int v)
{
	if( visited[v] == true )
	{
		return;
	}
	
	visited[v] = true;
	
	vector<int>&	adj = original[v];
	
	for(int i=0;i<adj.size();i++)
	{
		original_dfs(adj[i]);
	}
	
	st.push(v);
}

void	reverse_dfs(int v,int scc_ptr)
{
	if( visited[v] == true )
	{
		return;
	}
	
	visited[v] = true;
	scc[scc_ptr].push_back(v);
	
	vector<int>& adj = reversed[v];
	
	for(int i=0;i<adj.size();i++)
	{
		reverse_dfs(adj[i],scc_ptr);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	for(int i=1;i<=V;i++)
	{
		original_dfs(i);
	}
	
	fill(&visited[1],&visited[V+1],false);
	
	int	scc_ptr;
	
	for(scc_ptr=0;!st.empty();st.pop())
	{
		int	v;
		
		v = st.top();
		
		if( visited[v] == false )
		{
			reverse_dfs(v,++scc_ptr);
		}
	}
	
	cout<<scc_ptr<<'\n';
	
	for(int i=1;i<=scc_ptr;i++)
	{
		vector<int>&	s = scc[i];
		
		sort(s.begin(),s.end());
		scc_head[s[0]] = i;
	}
	
	for(int i=1;i<=V;i++)
	{
		if( scc_head[i] == 0 )
		{
			continue;
		}
		
		vector<int>&	s = scc[scc_head[i]];
		
		for(int j=0;j<s.size();j++)
		{
			cout<<s[j]<<' ';
		}
		cout<<"-1\n";
	}
	
	return	0;
}
