#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_USER	100000
#define	NONE			-1

int	find_parent(int n,vector<int>& parent)
{
	if( parent[n] == -1 )
	{
		return	n;
	}
	
	int	p;
	
	p = find_parent(parent[n],parent);
	parent[n] = p;
	
	return	p;
}

int	main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	for(int i=1;i<=T;i++)
	{
		int			n,k,m;
		vector<int>	parent;
				
		scanf("%d %d",&n,&k);
		parent.resize(n,NONE);
		
		for(int j=1;j<=k;j++)
		{
			int	a,b,a_parent,b_parent;
			
			scanf("%d %d",&a,&b);
			
			a_parent = find_parent(a,parent);
			b_parent = find_parent(b,parent);
			
			if( a_parent != b_parent )
			{
				parent[max(a_parent,b_parent)] = min(a_parent,b_parent);
			}
		}
		
		scanf("%d",&m);
		printf("Scenario %d:\n",i);
		
		for(int j=1;j<=m;j++)
		{
			int	u,v;
			
			scanf("%d %d",&u,&v);
			printf("%d\n",(find_parent(u,parent)==find_parent(v,parent)));
		}
		puts("");
	}
	
	return	0;
}
