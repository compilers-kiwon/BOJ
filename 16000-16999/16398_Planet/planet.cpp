#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	NONE		0

typedef	long long int		int64;
typedef	pair<int,int>		Planet;
typedef	pair<int64,Planet>	Flow;	// first:-cost, second:<planet1,planet2>

int		N;
int64	cost_table[MAX_SIZE][MAX_SIZE];
int		parent[MAX_SIZE];

priority_queue<Flow>	flow_pq;

int		find_parent(int planet)
{
	if( parent[planet] == NONE )
	{
		return	planet;
	}
	
	int	p;
	
	p = find_parent(parent[planet]);
	parent[planet] = p;
	
	return	p;
}

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cin>>cost_table[i][j];
		}
	}
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<i;j++)
		{
			flow_pq.push(make_pair(-cost_table[i][j],make_pair(j,i)));
		}
	}
}

int64	get_min_cost(void)
{
	int64	total_cost;
	
	for(total_cost=0;!flow_pq.empty();flow_pq.pop())
	{
		int64	c;
		int		p1,p2,p1_parent,p2_parent;
		
		c = -flow_pq.top().first;
		p1 = flow_pq.top().second.first;
		p2 = flow_pq.top().second.second;
		
		p1_parent = find_parent(p1);
		p2_parent = find_parent(p2);
		
		if( p1_parent != p2_parent )
		{
			parent[p2_parent] = p1_parent;
			total_cost += c;
		}		
	}
	
	return	total_cost;
}

int		main(void)
{
	init();
	cout<<get_min_cost()<<'\n';
	
	return	0;
}
