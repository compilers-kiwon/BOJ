#include	<iostream>
#include	<vector>
#include	<map>
#include	<set>
#include	<queue>

using namespace	std;

typedef	vector<int>	Child;

bool	bfs(int root,map<int,Child>& tree,int& cnt)
{
	queue<int>		node_q;
	map<int,bool>	visited;
	
	node_q.push(root);
	visited[root] = true;
	cnt++;
	
	while( !node_q.empty() )
	{
		for(int i=1,q_size=node_q.size();i<=q_size;i++)
		{
			int	current_node;
			
			current_node = node_q.front();
			node_q.pop();
			
			Child&	children = tree[current_node];
			
			for(int j=0;j<children.size();j++)
			{
				int&	c = children[j];
				
				if( visited[c] == true )
				{
					return	false;
				}
				
				node_q.push(c);
				visited[c] = true;
				cnt++;
			}
		}
	}
	return	true;
}

bool	is_tree(map<int,int>& parent,set<int>& nodes,map<int,Child>& tree)
{
	int					root,cnt;
	set<int>::iterator	it;
	
	// 1. find a root node
	for(root=0,it=nodes.begin();it!=nodes.end();it++)
	{
		if( parent[*it] > 1 )
		{
			return	false;
		}
		else
		{
			if( parent[*it] == 0 )
			{
				if( root == 0 )
				{
					root = *it;
				}
				else
				{
					return	false;
				}
			}
		}
	}
	
	if( root == 0 )
	{
		return	false;
	}
	
	// 2.BFS
	cnt = 0;
	
	if( bfs(root,tree,cnt)==true && cnt==nodes.size() )
	{
		return	true;
	}
	
	return	false;
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	for(int i=1;;i++)
	{
		int	u,v;
		
		cin>>u>>v;
		
		if( u==-1 && v==-1 )
		{
			break;
		}
		
		// Empty tree is a tree.
		if( u==0 && v==0 )
		{
			cout<<"Case "<<i<<" is a tree.\n";
			continue;
		}
		
		map<int,int>	parent_cnt;
		set<int>		node_set;
		map<int,Child>	tree;
		
		while( u!=0 && v!=0 )
		{
			parent_cnt[v]++;
			tree[u].push_back(v);
			
			node_set.insert(u);
			node_set.insert(v);
			
			cin>>u>>v;
		}
		
		if( is_tree(parent_cnt,node_set,tree) == true )
		{
			cout<<"Case "<<i<<" is a tree.\n";
		}
		else
		{
			cout<<"Case "<<i<<" is not a tree.\n";
		}
	}
	
	return	0;
}
