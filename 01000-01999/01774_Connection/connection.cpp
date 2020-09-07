#include	<iostream>
#include	<queue>
#include	<cmath>

using namespace	std;

#define	MAX_SIZE	(1000+1)

typedef	pair<double,double> Pos;	// first:X, second:Y
typedef	pair<int,int>		Path;	// first:planet1, second:planet2
typedef	pair<double,Path>	State;	// fisrt:-distance, second:Path

int		N,M,parent[MAX_SIZE];
Pos		p[MAX_SIZE];
double	dist[MAX_SIZE][MAX_SIZE];

priority_queue<State>	pq;

int		find_parent(int n)
{
	int&	ret = parent[n];
	
	if( ret == 0 )
	{
		return	n;
	}
	
	ret = find_parent(parent[n]);
	
	return	ret;
}

double	connect(int p1,int p2)
{
	int		p1_parent,p2_parent;
	int		big_parent,small_parent;
	double	ret;
	
	p1_parent = find_parent(p1);
	p2_parent = find_parent(p2);
	
	if( p1_parent == p2_parent )
	{
		return	0.0;
	}
	
	big_parent = max(p1_parent,p2_parent);
	small_parent = min(p1_parent,p2_parent);
	
	parent[big_parent] = small_parent;
	
	return	dist[p1][p2];
}

void	init(void)
{
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%lf %lf",&p[i].first,&p[i].second);
	}
	
	for(int i=1;i<=N-1;i++)
	{
		for(int j=i+1;j<=N;j++)
		{
			double&	x1 = p[i].first;
			double&	y1 = p[i].second;
			double&	x2 = p[j].first;
			double&	y2 = p[j].second;
			double	tmp;
			
			tmp = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
			dist[i][j] = dist[j][i] = tmp;
			pq.push(make_pair(-tmp,make_pair(i,j)));
		}
	}
	
	for(int i=1;i<=M;i++)
	{
		int	p1,p2;
		
		scanf("%d %d",&p1,&p2);
		connect(p1,p2);
	}
}

int		main(void)
{
	init();
	
	double	new_path;
	
	for(new_path=0.0;!pq.empty();)
	{
		int	planet1,planet2;
		
		planet1 = pq.top().second.first;
		planet2 = pq.top().second.second;
		
		pq.pop();
		
		new_path += connect(planet1,planet2);
	}
	
	printf("%.2f\n",new_path);
	
	return	0;
}
