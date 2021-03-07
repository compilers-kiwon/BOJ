#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000+1)

#define	NON_BUGGY			0
#define	ALREADY_BUGGY		1
#define	NUM_OF_BUGGY_STATE	2	

typedef	struct	_NODE_INFO	Node;
struct	_NODE_INFO
{
	vector<int>	connected,forced;
	bool		visited[NUM_OF_BUGGY_STATE];
};

int		n,m;
Node	node[MAX_SIZE];
bool	counted[MAX_SIZE];

typedef	pair<int,int>	State;	// first:node,second:buggy

void	input(void)
{
	cin>>n>>m;
	
	for(int i=1;i<=m;i++)
	{
		int	a,b;
		
		cin>>a>>b;
		
		if( a < 0 )
		{
			node[-a].forced.push_back(b);
			node[-a].connected.push_back(b);
		}
		else
		{
			node[a].connected.push_back(b);
		}
	}
}

bool	movable(vector<int>& adj,int next_bug,queue<State>& q)
{
	for(int i=0;i<adj.size();i++)
	{
		Node&	n = node[adj[i]];
		
		if( n.visited[next_bug] == false )
		{
			n.visited[next_bug] = true;
			q.push(make_pair(adj[i],next_bug));
		}
	}
	
	return	!adj.empty();
}

int		find_rest_nodes(void)
{
	int				ret;
	queue<State>	q;
	
	q.push(make_pair(1,NON_BUGGY));
	node[1].visited[NON_BUGGY] = true;
	
	for(ret=0;!q.empty();q.pop())
	{
		int		current_node,current_bug;
		bool	stopped = false;
		
		current_node = q.front().first;
		current_bug = q.front().second;
		
		switch(current_bug)
		{
			case	NON_BUGGY:
				if( movable(node[current_node].connected,ALREADY_BUGGY,q) == false )
				{
					stopped = true;
				}
			case	ALREADY_BUGGY:
				if( movable(node[current_node].forced,current_bug,q) == false )
				{
					stopped = true;
				}
			default:
				// do nothing
				break;
		}
		
		if( stopped==true && counted[current_node]==false )
		{
			ret++;
			counted[current_node] = true;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<find_rest_nodes()<<'\n';
	
	return	0;
}
