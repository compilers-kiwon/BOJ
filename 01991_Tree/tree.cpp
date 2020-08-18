#include	<iostream>
#include	<map>

using namespace std;

typedef	pair<char,char>	child;

map<char,child>	tree;

void	preorder(char node)
{
	cout<<node;
	
	char	left,right;
	
	left = tree[node].first;
	
	if( left != '.' )
	{
		preorder(left);
	}
	
	right = tree[node].second;
	
	if( right != '.' )
	{
		preorder(right);
	}
}

void	inorder(char node)
{
	char	left,right;
	
	left = tree[node].first;
	
	if( left != '.' )
	{
		inorder(left);
	}
	
	cout<<node;
	
	right = tree[node].second;
	
	if( right != '.' )
	{
		inorder(right);
	}
}

void	postorder(char node)
{
	char	left,right;
	
	left = tree[node].first;
	
	if( left != '.' )
	{
		postorder(left);
	}
	
	right = tree[node].second;
	
	if( right != '.' )
	{
		postorder(right);
	}
	
	cout<<node;
}

int		main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		char	p,l,r;
		
		cin>>p>>l>>r;
		tree[p] = make_pair(l,r);
	}
	
	preorder('A');cout<<endl;
	inorder('A');cout<<endl;
	postorder('A');cout<<endl;
	
	return	0;
}
