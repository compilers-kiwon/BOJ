#include	<iostream>
#include	<algorithm>
#include	<vector>
#include	<cmath>

using namespace	std;

#define	MAX_SIZE	(100000+1)

typedef	long long int		int64;
typedef	pair<int,int>		Planet;	// first:pos, second:planet_idx
typedef	pair<int,int>		Vertex;
typedef	pair<int,Vertex>	Edge;

int				N,parent[MAX_SIZE];
Planet			x_pos[MAX_SIZE],y_pos[MAX_SIZE],z_pos[MAX_SIZE];
vector<Edge>	e;

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	x,y,z;
		
		cin>>x>>y>>z;
		
		x_pos[i] = make_pair(x,i);
		y_pos[i] = make_pair(y,i);
		z_pos[i] = make_pair(z,i);
		
		parent[i] = i;
	}
}

void	build_edge(Planet* p)
{
	sort(&p[1],&p[N+1]);
	
	for(int i=2;i<=N;i++)
	{
		int	d;
		
		d = p[i].first-p[i-1].first;
		e.push_back(make_pair(d,make_pair(p[i].second,p[i-1].second)));
	}	
}

int		find_parent(int n)
{
	int&	ret = parent[n];
	
	if( ret != n )
	{
		ret = find_parent(ret);
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	build_edge(x_pos);
	build_edge(y_pos);
	build_edge(z_pos);
	
	sort(e.begin(),e.end());
	
	int64	sum;
	int		cnt,i;
	
	for(i=cnt=sum=0;cnt!=N-1;i++)
	{
		int&	d = e[i].first;
		int&	a = e[i].second.first;
		int&	b = e[i].second.second;
		int		p1,p2,big_parent,small_parent;
		
		p1 = find_parent(a);
		p2 = find_parent(b);
		
		if( p1 == p2 )
		{
			continue;
		}
		
		big_parent = max(p1,p2);
		small_parent = min(p1,p2);
		
		parent[big_parent] = small_parent;
		sum += (int64)d;
		cnt++;
	}
	
	cout<<sum<<'\n';
	
	return	0;
}
