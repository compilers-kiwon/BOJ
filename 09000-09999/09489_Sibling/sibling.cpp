#include	<iostream>
#include	<vector>

using namespace	std;

#define	NONE		0
#define	MAX_SIZE	(1000000+1)
#define	ROOT_NODE	1

typedef	vector<int>			Children;
typedef	pair<int,Children>	Node;

int	parent[MAX_SIZE],num2node[MAX_SIZE];

bool	input(int& n,int& k,vector<Node>& tree)
{
	cin>>n>>k;
	
	if( n==0 && k==0 )
	{
		return	false;
	}
	
	Node	tmp;
	int		prev_num,current_parent,node_idx;
	
	tree.push_back(tmp);
	prev_num = -1;
	current_parent = -1;

	for(int i=1;i<=n;i++)
	{
		Node	node;
		int&	num = node.first;
		
		cin>>num;
		
		if( prev_num+1 != num )
		{
			++current_parent;
		}
		
		tree.push_back(node);
		tree[current_parent].second.push_back(num);
		
		num2node[num] = i;
		parent[num] = tree[current_parent].first;
		
		prev_num = num;
	}
	
	return	true;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int				n,k;
		vector<Node>	tree;
		
		if( input(n,k,tree) == false )
		{
			break;
		}
		
		if( num2node[k]==ROOT_NODE || num2node[parent[k]]==ROOT_NODE )
		{
			cout<<"0\n";
			continue;
		}
		
		int	grand_num,grand_node,num_of_grand_children;
		
		grand_num = parent[parent[k]];
		grand_node = num2node[grand_num];
		
		Children&	my_uncle = tree[grand_node].second;
		int			cnt,my_parent,my_parent_node;
		
		cnt = 0;
		my_parent = parent[k];
		my_parent_node = num2node[my_parent];

		for(int i=0;i<my_uncle.size();i++)
		{
			int&	my_uncle_num = my_uncle[i];
			cnt += tree[num2node[my_uncle_num]].second.size();
		}
		
		cout<<cnt-tree[my_parent_node].second.size()<<'\n';
	}
	
	return	0;
}
