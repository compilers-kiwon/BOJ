#include	<iostream>
#include	<string>
#include	<vector>
#include	<algorithm>

using namespace	std;

typedef	struct	_NODE	Node;
struct	_NODE
{
	string			name;
	vector<Node>	child;
};

vector<Node>	first_floor;

bool	is_less(const Node& n1,const Node& n2)
{
	if( n1.name < n2.name )
	{
		return	true;
	}
	
	return	false;
}

Node*	find_node(string& food,vector<Node>* tree)
{
	for(int i=0;i<tree->size();i++)
	{
		Node&	n = (*tree)[i];
		
		if( n.name == food )
		{
			return	&((*tree)[i]);	
		}
	}
	
	return	NULL;
}

void	init(void)
{
	cin.sync_with_stdio(false);
	
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int				K;
		vector<Node>*	current_tree;
		
		cin>>K;
		current_tree = &first_floor;
		
		for(int j=1;j<=K;j++)
		{
			string	str;
			Node*	tmp;
			
			cin>>str;
			
			tmp = find_node(str,current_tree);
			
			if( tmp == NULL )
			{
				Node	n;
				
				n.name = str;
				current_tree->push_back(n);
				current_tree = &((*current_tree)[current_tree->size()-1].child);
			}
			else
			{
				current_tree = &(tmp->child);
			}
		}
	}
}

void	print_tree(vector<Node>& child,string head)
{
	sort(child.begin(),child.end(),is_less);
	
	for(int i=0;i<child.size();i++)
	{
		cout<<head<<child[i].name<<'\n';
		print_tree(child[i].child,head+"--");
	}
}

int		main(void)
{
	init();
	print_tree(first_floor,"");
	
	return	0;
}
