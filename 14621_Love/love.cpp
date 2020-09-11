#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000+1)

#define	MAN			'M'
#define	WOMAN		'W'

#define	merge_tree(p1,p2)	(parent[(p2)]=(p1))

typedef	pair<int,int>		Connected;	// first:school_1,second:school_2
typedef	pair<int,Connected>	Path;		// first:-distance,second:Connected
	
int		N,M,parent[MAX_SIZE];
char	attribute[MAX_SIZE];

int		find_parent(int n)
{
	int&	ret = parent[n];
	
	if( ret != n )
	{
		ret = find_parent(ret);
	}
	
	return	ret;
}

priority_queue<Path>	pq;

void	input(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		cin>>attribute[i];
		parent[i] = i;
	}
	
	for(int i=1;i<=M;i++)
	{
		int	u,v,d;
		
		cin>>u>>v>>d;
		
		if( attribute[u] != attribute[v] )
		{
			pq.push(make_pair(-d,make_pair(u,v)));
		}
	}
}

int		build_path(void)
{
	int	ret;
	
	ret = 0;
	
	for(;!pq.empty();)
	{
		int	s1,s2,d,p1,p2;
		
		d = -pq.top().first;
		s1 = pq.top().second.first;
		s2 = pq.top().second.second;
		
		pq.pop();
		
		p1 = find_parent(s1);
		p2 = find_parent(s2);
		
		if( p1 == p2 )
		{
			continue;
		}
		
		merge_tree(min(p1,p2),max(p1,p2));
		ret += d;
	}
	
	for(int i=1;i<=N;i++)
	{
		if( find_parent(i) != 1 )
		{
			ret = -1;
			break;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<build_path()<<'\n';
	
	return	0;
}
