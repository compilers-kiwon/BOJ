#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(10000+1)

typedef	pair<int,int>	City;
typedef	pair<int,City>	Path;

void	input(int& num_of_cities,priority_queue<Path>& pq,int& p,int& q)
{
	int	M;
	
	cin>>num_of_cities>>M>>p>>q;
	
	for(int i=1;i<=M;i++)
	{
		int	u,v,w;
		
		cin>>u>>v>>w;
		pq.push(make_pair(-w,make_pair(u,v)));
	}
}

int		find_parent(int n,int* parent)
{
	int&	ret = parent[n];
	
	if( ret != n )
	{
		ret = find_parent(ret,parent);
	}
	
	return	ret;
}

bool	is_constructed(Path& p,int* parent)
{
	int	p1,p2,big,small;
	
	p1 = find_parent(p.second.first,parent);
	p2 = find_parent(p.second.second,parent);
	
	if( p1 == p2 )
	{
		return	false;
	}
	
	big = max(p1,p2);
	small = min(p1,p2);
	parent[big] = small;
	
	return	true;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(;T>0;T--)
	{
		int						N,p,q;
		int						parent[MAX_SIZE];
		bool					used;
		priority_queue<Path>	pq;
		
		input(N,pq,p,q);
		
		for(int i=1;i<=N;i++)
		{
			parent[i] = i;
		}
		
		for(used=false;used!=true&&!pq.empty();)
		{
			Path	n;
			
			n = pq.top();
			pq.pop();
			
			if( is_constructed(n,parent) == true )
			{
				if( (n.second.first==p&&n.second.second==q)
					|| (n.second.first==q&&n.second.second==p) )
				{
					used = true;
				}
			}
		}
		
		if( used == true )
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
