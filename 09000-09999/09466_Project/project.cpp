#include	<iostream>
#include	<vector>
#include	<stack>

using namespace	std;

#define	MAX_SIZE	(100000+1)

typedef	vector<int>	Node;

void	input(int& n,Node& original,vector<Node>& reversed)
{
	cin>>n;
	original.resize(n+1);
	reversed.resize(n+1);
	
	for(int i=1;i<=n;i++)
	{
		int&	s = original[i];
		
		cin>>s;
		reversed[s].push_back(i);
	}
}

void	original_dfs(int n,bool* visited,Node& original,stack<int>& st)
{
	if( visited[n] == true )
	{
		return;
	}
	
	visited[n] = true;
	original_dfs(original[n],visited,original,st);
	
	st.push(n);
}

void	reversed_dfs(int n,bool* visited,vector<Node>& reversed,int& cnt)
{
	if( visited[n] == true )
	{
		return;
	}
	
	visited[n] = true;
	cnt++;
	
	Node&	adj = reversed[n];
	
	for(int i=0;i<adj.size();i++)
	{
		reversed_dfs(adj[i],visited,reversed,cnt);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int				n,ret;
		Node			original;
		vector<Node>	reversed;
		bool			visited[MAX_SIZE];
		stack<int>		st;
		
		input(n,original,reversed);
		fill(&visited[1],&visited[n+1],false);
		
		for(int i=1;i<=n;i++)
		{
			original_dfs(i,visited,original,st);
		}
		
		ret = 0;
		fill(&visited[1],&visited[n+1],false);
		
		for(;!st.empty();st.pop())
		{
			if( visited[st.top()] == false )
			{
				int	cnt,s;
				
				cnt = 0;
				s = st.top();
								
				reversed_dfs(s,visited,reversed,cnt);
				
				if( cnt==1 && original[s]!=s ) 
				{
					ret++;
				}
			}
		}
		
		cout<<ret<<'\n';
	}
	
	return	0;
}
