#include	<iostream>
#include	<vector>
#include	<set>

using namespace	std;

#define	MAX_SIZE	(200000+1)

int			N,M,parent[MAX_SIZE];
bool		available[MAX_SIZE];
vector<int>	connected[MAX_SIZE];
vector<int>	closed,num_of_parent;

int		find_parent(int n)
{
	int&	ret = parent[n];
	
	if( ret != n )
	{
		ret = find_parent(ret);
	}
	
	return	ret;
}

void	input(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=M;i++)
	{
		int	b1,b2;
		
		cin>>b1>>b2;
		
		connected[b1].push_back(b2);
		connected[b2].push_back(b1);
	}
	
	for(int i=1;i<=N;i++)
	{
		int	b;
		
		cin>>b;
		closed.push_back(b);
	}
}

void	init(void)
{
	num_of_parent.push_back(1);
	
	available[closed.back()] = true;
	closed.pop_back();
		
	for(int i=1;i<=N;i++)
	{
		parent[i] = i;
	}
}

void	enable_barn(void)
{
	for(;!closed.empty();)
	{
		int	b,current_num_of_tree;

		b = closed.back();
		closed.pop_back();

		current_num_of_tree = num_of_parent.back()+1;
		
		for(int i=0;i<connected[b].size();i++)
		{
			int&	adj = connected[b][i];
			
			if( available[adj] == false )
			{
				continue;
			}
			
			int	p1,p2;
			
			p1 = find_parent(b);
			p2 = find_parent(adj);
			
			if( p1 == p2 )
			{
				continue;
			}
			
			if( p1 > p2 )
			{
				parent[p1] = p2;
			}
			else
			{
				parent[p2] = p1;
			}
			
			current_num_of_tree--;
		}
		
		available[b] = true;
		num_of_parent.push_back(current_num_of_tree);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	init();
	
	enable_barn();
	
	for(int i=N-1;i>=0;i--)
	{
		if( num_of_parent[i] == 1 )
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	
	return	0;
}
