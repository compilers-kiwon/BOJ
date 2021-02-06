#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	500000

typedef	pair<int,int>	Line;

int			n,m;
int			p[MAX_SIZE];
queue<Line>	q;

void	input(void)
{
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int	u,v;
		
		cin>>u>>v;
		q.push(make_pair(u,v));
	}
	
	for(int i=0;i<n;i++)
	{
		p[i] = i;
	}
}

int		find_parent(int n)
{
	int&	ret = p[n];
	
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
	
	int	cnt;
	
	input();
	
	for(cnt=1;!q.empty();q.pop(),cnt++)
	{
		int	u,v,pu,pv;
		
		u = q.front().first;
		v = q.front().second;
		
		pu = find_parent(u);
		pv = find_parent(v);
		
		if( pu == pv )
		{
			break;
		}
		
		p[max(pu,pv)] = min(pu,pv);
	}
	
	if( q.empty() )
	{
		cout<<"0\n";
	}
	else
	{
		cout<<cnt<<'\n';
	}
	
	return	0;
}
