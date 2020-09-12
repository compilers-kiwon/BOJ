#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

#define	MAX_NUM_OF_NODES	(1000+1)
#define	MAX_NUM_OF_EDGES	(1000000+1)
#define	ROOT_NODE			1

typedef	pair<int,int>	Edge;

int		parent[MAX_NUM_OF_NODES];
Edge	edge[MAX_NUM_OF_EDGES];

const	string	answer[2] = {"graph\n","tree\n"};

#define	TRUE	1
#define	FALSE	0

void	init(int& num_of_nodes,int& num_of_edges)
{
	cin>>num_of_nodes>>num_of_edges;
	
	for(int i=1;i<=num_of_nodes;i++)
	{
		parent[i] = i;
	}
	
	for(int i=1;i<=num_of_edges;i++)
	{
		cin>>edge[i].first>>edge[i].second;
	}
}

int		find_parent(int n)
{
	int	ret;
	
	if( parent[n] == n )
	{
		ret = n;
	}
	else
	{
		ret = find_parent(parent[n]);
	}
	
	parent[n] = ret;
	
	return	ret;
}

int		is_tree(int num_of_nodes,int num_of_edges)
{
	int	ret,i;
	
	for(ret=TRUE,i=1;i<=num_of_edges;i++)
	{
		int&	n1 = edge[i].first;
		int&	n2 = edge[i].second;
		
		int		n1_parent,n2_parent;
		
		n1_parent = find_parent(n1);
		n2_parent = find_parent(n2);
		
		if( n1_parent == n2_parent )
		{
			ret = FALSE;
			break;
		}
		
		if( n1_parent < n2_parent )
		{
			parent[n2_parent] = n1_parent;
		}
		else
		{
			parent[n1_parent] = n2_parent;
		}
	}
	
	if( ret == TRUE )
	{
		for(int i=1;i<=num_of_nodes;i++)
		{
			if( parent[i]!=ROOT_NODE && find_parent(i)!=ROOT_NODE )
			{
				ret = FALSE;
				break;
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(;T>0;T--)
	{
		int	N,M;
		
		init(N,M);
		cout<<answer[is_tree(N,M)];
	}
	
	return	0;
}
