#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(300+1)

typedef	long long int		int64;
typedef	pair<int,int>		Pos;	// first:x,second:y
typedef	pair<int,int>		Team;
typedef	pair<int64,Team>	Pair;	// first:-distance,second:<dancer1,dancer2>

int		N;
Pos		dancer[MAX_SIZE];
bool	paired[MAX_SIZE];

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int&	x = dancer[i].first;
		int&	y = dancer[i].second;
		
		cin>>x>>y;
	}
}

void	get_distance(priority_queue<Pair>& pq)
{
	for(int i=1;i<N;i++)
	{
		for(int j=i+1;j<=N;j++)
		{
			int64	dx,dy;
			
			dx = dancer[i].first-dancer[j].first;
			dy = dancer[i].second-dancer[j].second;
			
			pq.push(make_pair(-(dx*dx+dy*dy),make_pair(i,j)));
		}
	}
}

void	get_closest_pairs(priority_queue<Pair>& pq,priority_queue<Team>& p)
{
	for(;!pq.empty();)
	{
		int64	current_distance,current_dancer1,current_dancer2;
		
		current_distance = -pq.top().first;
		current_dancer1 = pq.top().second.first;
		current_dancer2 = pq.top().second.second;
		
		pq.pop();
		
		if( paired[current_dancer1]==false && paired[current_dancer2]==false )
		{
			paired[current_dancer1] = paired[current_dancer2] = true;
			p.push(make_pair(-current_dancer1,-current_dancer2));
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	priority_queue<Team>	p;
	priority_queue<Pair>	pq;
	
	input();
	get_distance(pq);
	get_closest_pairs(pq,p);
	
	for(;!p.empty();p.pop())
	{
		Team	t;
		
		t = p.top();
		cout<<-t.first<<' '<<-t.second<<'\n';
	}
	
	return	0;
}
