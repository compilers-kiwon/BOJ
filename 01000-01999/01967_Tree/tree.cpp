#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_NODE	(10000+1)

typedef	pair<int,int>	Node;	// first:child,second:weight
	
vector<Node>	tree[MAX_NUM_OF_NODE];

void	init(int& num_of_node)
{
	cin.sync_with_stdio(false);
	
	cin>>num_of_node;
	
	for(int i=1;i<num_of_node;i++)
	{
		int	parent,child,weight;
		
		cin>>parent>>child>>weight;
		
		tree[parent].push_back(make_pair(child,weight));
	}
}

int		get_weight(int index,int& max_weight)
{
	priority_queue<int>	child_wegiht_pq;
	
	vector<Node>&	child = tree[index];
	
	for(int i=0;i<child.size();i++)
	{
		int&	current_child = child[i].first;
		int&	current_weight = child[i].second;
		
		child_wegiht_pq.push(get_weight(current_child,max_weight)+current_weight);
	}
	
	int	ret1,ret2;
	
	ret1 = ret2 = 0;
	
	if( child_wegiht_pq.size() != 0 )
	{
		if( child_wegiht_pq.size() == 1 )
		{
			ret1 = child_wegiht_pq.top();
		}
		else
		{
			ret1 = child_wegiht_pq.top();
			child_wegiht_pq.pop();
			ret2 = child_wegiht_pq.top();
		}
	}
	
	max_weight = max(max_weight,ret1+ret2);
	
	return	ret1;
}

int		main(void)
{
	int	n,max_len;
	
	init(n);
	max_len = 0;
	get_weight(1,max_len);
	
	cout<<max_len<<'\n';
	
	return	0;
}
