#include	<iostream>
#include	<stack>

using namespace std;

#define	MAX_NUM_OF_NODE	(10000+1)
#define	EMPTY			0
#define	ROOT			1

typedef	struct	_NODE_INFO	Node;
struct	_NODE_INFO
{
	int	key,left,right;
};

Node	tree[MAX_NUM_OF_NODE];

void	tree_insert(int parent,int node)
{
	if( tree[node].key < tree[parent].key )
	{
		if( tree[parent].left == EMPTY )
		{
			tree[parent].left = node;
		}
		else
		{
			tree_insert(tree[parent].left,node);
		}
	}
	else
	{
		if( tree[parent].right == EMPTY )
		{
			tree[parent].right = node;
		}
		else
		{
			tree_insert(tree[parent].right,node);
		}
	}
}

void	print_tree(int parent)
{
	if( tree[parent].left != EMPTY )
	{
		print_tree(tree[parent].left);
	}
	
	if( tree[parent].right != EMPTY )
	{
		print_tree(tree[parent].right);
	}
	
	printf("%d\n",tree[parent].key);
}

int		main(void)
{
	Node	n;
	
	scanf("%d",&tree[ROOT].key);
	tree[ROOT].left = tree[ROOT].right = EMPTY;
	
	for(int i=ROOT+1;scanf("%d",&tree[i].key)==1;i++)
	{
		tree[i].left = tree[i].right = EMPTY;
		tree_insert(1,i);
	}
	
	print_tree(ROOT);
	
	return	0;
}
