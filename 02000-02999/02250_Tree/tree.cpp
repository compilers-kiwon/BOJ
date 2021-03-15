#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(10000+1)
#define	NONE		-1

typedef	struct	_TREE_INFO	Tree;
struct	_TREE_INFO
{
	int		left,right;
	bool	has_parent;
};

int			N,p;
Tree		t[MAX_SIZE];
vector<int>	pos[MAX_SIZE];

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	n,l,r;
		
		cin>>n>>l>>r;
		t[l].has_parent = t[r].has_parent = true;
		
		t[n].left = l;
		t[n].right = r;
	}
}

int		find_root(void)
{
	int	ret;
	
	for(int i=1;i<=N;i++)
	{
		if( t[i].has_parent == false )
		{
			ret = i;
			break;
		}
	}
	
	return	ret;
}

void	get_pos(int level,int node)
{
	if( t[node].left != NONE )
	{
		get_pos(level+1,t[node].left);
	}
	
	pos[level].push_back(p++);

	if( t[node].right != NONE )
	{
		get_pos(level+1,t[node].right);
	}
}

int		find_max_width(int& level)
{
	int	ret = -1;
	
	for(int i=1;!pos[i].empty();i++)
	{
		sort(pos[i].begin(),pos[i].end());
		
		if( pos[i].back()-pos[i].front() > ret )
		{
			ret = pos[i].back()-pos[i].front();
			level = i;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	root;
	
	input();
	root = find_root();
	get_pos(1,root);
	
	int	max_width,max_width_level;
	
	max_width = find_max_width(max_width_level);
	cout<<max_width_level<<' '<<max_width+1<<'\n';
	
	return	0;
}
