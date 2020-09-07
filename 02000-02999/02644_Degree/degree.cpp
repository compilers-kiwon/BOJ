#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_PEOPLE	(100+1)

int	parent[MAX_NUM_OF_PEOPLE];

int	find_parent(int a,vector<int>& p)
{
	p.insert(p.begin(),a);
	
	if( parent[a] == 0 )
	{
		return	a;
	}
	
	return	find_parent(parent[a],p);
}

int	find_distance(vector<int>& p1,vector<int>& p2)
{
	int	min_degree;
	
	min_degree = min(p1.size(),p2.size());
	
	int	degree,same_parent_degree;
	
	for(degree=1,same_parent_degree=0;degree<min_degree;degree++)
	{
		if( p1[degree] == p2[degree] )
		{
			same_parent_degree = degree;
		}
	}
	
	return (p1.size()-1-same_parent_degree)+(p2.size()-1-same_parent_degree);
}

int	main(void)
{
	int	n,q1,q2,m;
	
	cin>>n>>q1>>q2>>m;
	
	for(int i=1;i<=m;i++)
	{
		int	x,y;
		
		cin>>x>>y;
		parent[y] = x;
	}
	
	vector<int>	q1_parent;
	vector<int>	q2_parent;
	
	if( find_parent(q1,q1_parent) != find_parent(q2,q2_parent) )
	{
		cout<<"-1\n";
	}
	else
	{
		cout<<find_distance(q1_parent,q2_parent)<<endl;
	}
	return	0;
}
