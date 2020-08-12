#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(100000+1)
#define	NONE		0

typedef	pair<int,int>	Path;
typedef	pair<int,Path>	Road;	// first:-cost, second:Path

int	N,M,parent[MAX_SIZE];
priority_queue<Road>	pq;

void	init(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=M;i++)
	{
		int	A,B,C;
		
		cin>>A>>B>>C;
		pq.push(make_pair(-C,make_pair(A,B)));
	}
}

int		find_parent(int c)
{
	int&	ret = parent[c];
	
	if( ret == NONE )
	{
		return	c;
	}
	
	ret = find_parent(ret);
	
	return	ret;
}

int		divide_village(void)
{
	int	ret;
	
	for(ret=0;!pq.empty()&&N!=2;)
	{
		int	A,B,C;
		
		C = -pq.top().first;
		A = pq.top().second.first;
		B = pq.top().second.second;
		
		pq.pop();
		
		int	p1,p2,big_parent,small_parent;
		
		p1 = find_parent(A);
		p2 = find_parent(B);
		
		if( p1 == p2 )
		{
			continue;
		}
		
		big_parent = max(p1,p2);
		small_parent = min(p1,p2);
		
		parent[big_parent] = small_parent;
		
		N--;
		ret += C;
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	init();
	cout<<divide_village()<<'\n';
	
	return	0;
}
