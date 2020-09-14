#include	<iostream>
#include	<set>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(100000+1)

#define	TRUE	1
#define	FALSE	0

int			N,input_order[MAX_SIZE];
int			my_order[MAX_SIZE];
bool		visited[MAX_SIZE];
vector<int>	connected[MAX_SIZE];
set<int>	tree[MAX_SIZE];

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N-1;i++)
	{
		int	A,B;
		
		cin>>A>>B;
		
		connected[A].push_back(B);
		connected[B].push_back(A);
	}
	
	for(int i=1;i<=N;i++)
	{
		cin>>input_order[i];
	}
}

void	build_tree(void)
{
	queue<int>	q;
	
	visited[1] = true;
	q.push(1);
	
	for(;!q.empty();)
	{
		for(int i=1,size=q.size();i<=size;i++)
		{
			int	n;
			
			n = q.front();
			q.pop();
			
			vector<int>&	adj = connected[n];
			
			for(int j=0;j<adj.size();j++)
			{
				if( visited[adj[j]] == false )
				{
					visited[adj[j]] = true;
					tree[n].insert(adj[j]);
					q.push(adj[j]);
				}
			}
		}
	}
}

int		compare_order(int p_ptr,int c_ptr)
{
	if( p_ptr > N )
	{
		return	TRUE;
	}
	
	int&	p1 = input_order[p_ptr];
	int&	p2 = my_order[p_ptr];
	
	if( p1 != p2 )
	{
		return	FALSE;
	}
	
	set<int>&			children = tree[p1];
    
	for(int i=0;i<children.size();i++,c_ptr++)
	{
		int&	child = input_order[c_ptr];
		
		if( children.find(child) == children.end() )
		{
			return	FALSE;
		}
		
		my_order[c_ptr] = child;
	}
	
	return	compare_order(p_ptr+1,c_ptr);
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	build_tree();
	
	my_order[1] = 1;
	cout<<compare_order(1,2)<<'\n';
	
	return	0;
}
