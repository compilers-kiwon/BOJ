#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_NODE	50
#define	ROOT			-1

vector<int>		parent(MAX_NUM_OF_NODE);
vector<int>		node[MAX_NUM_OF_NODE];
vector<bool>	is_tree(MAX_NUM_OF_NODE,true);

void	remove_node(int n)
{
	is_tree[n] = false;
	
	int	num_of_child = node[n].size();
	
	if( num_of_child != 0 )
	{
		for(int i=0;i<num_of_child;i++)
		{
			remove_node(node[n][i]);
		}
		node[n].clear();
	}
}

int		main(void)
{
	int	N,D;
	
	cin>>N;
	
	for(int i=0;i<N;i++)
	{
		int	n;
		
		cin>>n;
		parent[i] = n;
		
		if( n != ROOT )
		{
			node[n].push_back(i);
		}
	}
	
	cin>>D;
	
	if( parent[D] == ROOT )
	{
		cout<<"0\n";
		return	0;
	}
	
	remove_node(D);
	node[parent[D]].pop_back();
	
	int	cnt = 0;
	
	for(int i=0;i<N;i++)
	{
		if( is_tree[i] == true && node[i].size() == 0 )
		{
			++cnt;
		}
	}
	cout<<cnt<<endl;
	
	return	0;
}
