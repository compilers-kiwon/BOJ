#include	<cstdio>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_V	(1000+1)

typedef	pair<int,int>		FromTo;
typedef	pair<int,FromTo>	Edge;

vector<int>				parent(MAX_NUM_OF_V,-1);
priority_queue<Edge>	pq;

int	find_parent(int v)
{
	if( parent[v] == -1 )
	{
		return	v;
	}
	
	int	p = find_parent(parent[v]);
	parent[v] = p;
	
	return	p;
}

int	main(void)
{
	int	N,M;
	
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=M;i++)
	{
		int		a,b,c;
		FromTo	ft;
		Edge	e;
		
		scanf("%d %d %d",&a,&b,&c);
		
		ft = make_pair(a,b);
		e = make_pair(-c,ft);
		pq.push(e);
	}
	
	int	cost = 0;
	
	while( pq.size() != 0 )
	{
		int	a,b,c;
		
		c = -pq.top().first;
		a = pq.top().second.first;
		b = pq.top().second.second;
		pq.pop();
		
		int	parent_a = find_parent(a);
		int	parent_b = find_parent(b);
		
		if( parent_a != parent_b )
		{
			cost += c;
			parent[parent_b] = parent_a;
		}
	}
	printf("%d\n",cost);
	
	return	0;
}
