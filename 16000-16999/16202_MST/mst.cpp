#include	<iostream>
#include	<vector>

using namespace	std;

#define	TRUE	1
#define	FALSE	0
#define	NONE	0

#define	MAX_SIZE	(10000+1)

typedef	struct	_EDGE_INFO	Edge;
struct	_EDGE_INFO
{
	int	x,y,available;
};

int		N,M,K;
Edge	e[MAX_SIZE];

void	input(void)
{
	cin>>N>>M>>K;
	
	for(int i=1;i<=M;i++)
	{
		cin>>e[i].x>>e[i].y;
		e[i].available = TRUE;
	}
}

int		find_parent(int n,vector<int>& parent)
{
	int&	ret = parent[n];
	
	if( ret != n )
	{
		ret = find_parent(ret,parent);
	}
	
	return	ret;
}

int		build_MST(void)
{
	int			tree_weight,used_min_edge,ret;
	vector<int>	num_of_nodes(N+1,1);
	vector<int>	parent(N+1);
	
	tree_weight = used_min_edge = NONE;
	
	for(int i=1;i<=N;i++)
	{
		parent[i] = i;
	}
	
	for(int i=1;i<=M;i++)
	{
		if( e[i].available == FALSE )
		{
			continue;
		}
		
		int	x_parent,y_parent;
		
		x_parent = find_parent(e[i].x,parent);
		y_parent = find_parent(e[i].y,parent);
		
		if( x_parent == y_parent )
		{
			continue;
		}
		
		tree_weight += i;
		
		if( used_min_edge == NONE )
		{
			used_min_edge = i;
		}
		
		int	big_parent,small_parent;
		
		big_parent = max(x_parent,y_parent);
		small_parent = min(x_parent,y_parent);
		
		parent[big_parent] = small_parent;
		num_of_nodes[small_parent] += num_of_nodes[big_parent];
	}
	
	if( num_of_nodes[1] == N )
	{
		ret = tree_weight;
		e[used_min_edge].available = FALSE;
	}
	else
	{
		ret = 0;
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	int prev_weight;
	
	prev_weight = -1;
	
	for(int i=1;i<=K;i++)
	{
		if( prev_weight == 0 )
		{
			cout<<"0 ";
			continue;
		}
		
		prev_weight = build_MST();
		cout<<prev_weight<<' ';
	}
	
	return	0;
}
