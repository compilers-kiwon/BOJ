#include	<iostream>
#include	<vector>
#include	<cmath>

using namespace	std;

#define	MAX_LEVEL	(10+1)

vector<int>	tree[MAX_LEVEL];

void	build_tree(int level,int lo,int hi,vector<int>& n)
{
	if( lo == hi )
	{
		tree[level].push_back(n[lo]);
		return;
	}
	
	int	mid = (lo+hi)/2;
	
	build_tree(level+1,lo,mid-1,n);
	tree[level].push_back(n[mid]);
	build_tree(level+1,mid+1,hi,n);
}

int		main(void)
{
	int			K,num_of_nodes;
	vector<int>	node;
	
	cin>>K;
	num_of_nodes = pow(2,K)-1;
	
	node.resize(num_of_nodes);
	
	for(int i=0;i<num_of_nodes;i++)
	{
		cin>>node[i];
	}
	
	build_tree(1,0,num_of_nodes-1,node);
	
	for(int i=1;i<=K;i++)
	{
		for(int j=0;j<tree[i].size();j++)
		{
			cout<<tree[i][j]<<' ';
		}
		cout<<endl;
	}
	
	return	0;
}
