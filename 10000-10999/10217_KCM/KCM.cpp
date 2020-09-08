#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_AIRPORT	(100+1)
#define	MAX_COST			(10000+1)

typedef	struct	_PATH_INFO	Path;
struct	_PATH_INFO
{
	int	airport,cost,time;
};

typedef	pair<int,int>			Airport_Cost;
typedef	pair<int,Airport_Cost>	Time;

int	N,M,K;
int	visited[MAX_NUM_OF_AIRPORT][MAX_COST];

void	init(vector<Path>* connected)
{
	scanf("%d %d %d",&N,&M,&K);
	
	for(int i=1;i<=K;i++)
	{
		int		u,v,c,d;
		Path	p;
		
		scanf("%d %d %d %d",&u,&v,&c,&d);
		
		p.airport = v;
		p.cost = c;
		p.time = d;
		
		connected[u].push_back(p);
	}
}

int		get_min_time(vector<Path>* connected)
{
	int						min_time;
	priority_queue<Time>	ap_q;
	Time					t;
	
	t.first = 0;
	t.second.first = 1;
	t.second.second = 0;
	
	ap_q.push(t);
	
	min_time = 0x7FFFFFFF;
	
	while( ap_q.size() != 0 )
	{
		int	current_airport,current_cost,current_time;
		
		current_airport = ap_q.top().second.first;
		current_cost = ap_q.top().second.second;
		current_time = -(ap_q.top().first);
		
		ap_q.pop();
		
		if( current_airport == N )
		{
			min_time = min(min_time,current_time);
			continue;
		}
		
		vector<Path>&	to = connected[current_airport];
		
		for(int i=0;i<to.size();i++)
		{
			int	next_airport,next_cost,next_time;
			
			next_airport = to[i].airport;
			next_cost = current_cost+to[i].cost;
			next_time = current_time+to[i].time;
			
			if( next_cost <= M && next_time < visited[next_airport][next_cost] )
			{
				t.first = -next_time;
				t.second.first = next_airport;
				t.second.second = next_cost;
				
				ap_q.push(t);
				
				visited[next_airport][next_cost] = next_time;
			}
		}
	}
	
	return	min_time;
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		vector<Path>	connected[MAX_NUM_OF_AIRPORT];
		
		init(connected);
		
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=M;j++)
			{
				visited[i][j] = 0x7FFFFFFF;
			}
		}
		
		int	min_time;
		
		min_time = get_min_time(connected);
		
		if( min_time == 0x7FFFFFFF )
		{
			puts("Poor KCM");
		}
		else
		{
			printf("%d\n",min_time);
		}
		
		T--;
	}
	
	return	0;
}
