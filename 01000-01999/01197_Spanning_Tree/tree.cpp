#include	<cstdio>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_V	(10000+1)

typedef	long long		int64;
typedef	pair<int,int>	Edge;	
typedef	pair<int,Edge>	PQ;

vector<int>	parent(MAX_NUM_OF_V,-1);

priority_queue<PQ>	pq;

int	find_root(int v)
{
	if( parent[v] == -1 )
	{
		return	v;
	}
	
	int p =	find_root(parent[v]);
	parent[v] = p;
	
	return	p;		
}

int	main(void)
{
	int		V,E;
	int64	W;
	
	scanf("%d %d",&V,&E);
	
	for(int i=1;i<=E;i++)
	{
		int		A,B,C;
		Edge	t1;
		PQ		t2;
		
		scanf("%d %d %d",&A,&B,&C);
		t1 = make_pair(A,B);
		t2 = make_pair(-C,t1);
		pq.push(t2);
	}
	
	W = 0;
	
	while( pq.size() != 0 )
	{
		int	A,B,C;
		
		C = -pq.top().first;
		A = pq.top().second.first;
		B = pq.top().second.second;
		pq.pop();
		
		int	root_A,root_B;
		
		root_A = find_root(A);
		root_B = find_root(B);
		
		if( root_A != root_B )
		{
			parent[root_B] = root_A;
			W += (int64)C;
		}
	}
	printf("%lld\n",W);
	
	return	0;
}
