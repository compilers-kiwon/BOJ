#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_INTERSECTIONS	(1000+1)
#define	MAX_NUM_OF_SCENARIOS		(1000+1)

#define	CRIME_POS	0
#define	INF			1000000.0

typedef	pair<int,double>	Road;	// first:to,second:time
typedef	pair<double,int>	State;	// first:-time,second:intersection

int	num_of_intersections;
int	num_of_roads;
int	num_of_scenarios;

vector<Road>	road[MAX_NUM_OF_INTERSECTIONS];
vector<int>		scenario[MAX_NUM_OF_SCENARIOS];

void	input(void)
{
	scanf("%d %d %d",&num_of_intersections,&num_of_roads,&num_of_scenarios);
	
	for(int i=1;i<=num_of_roads;i++)
	{
		int		from,to;
		double	time;
		
		scanf("%d %d %lf",&from,&to,&time);
		road[from].push_back(make_pair(to,time));
	}
	
	for(int i=1;i<=num_of_scenarios;i++)
	{
		int	crime_intersection,num_of_cars;
		
		scanf("%d %d",&crime_intersection,&num_of_cars);
		scenario[i].push_back(crime_intersection);
		
		for(int j=1;j<=num_of_cars;j++)
		{
			int	car_starting_intersection;
			
			scanf("%d",&car_starting_intersection);
			scenario[i].push_back(car_starting_intersection);
		}
	}
}

double	get_earliest_arrival_time(int scenario_idx)
{
	priority_queue<State>	pq;
	vector<double>			dp(num_of_intersections+1,INF);
	
	int&	crime_intersection = scenario[scenario_idx][CRIME_POS];
	
	for(int i=1;i<scenario[scenario_idx].size();i++)
	{
		int&	starting_intersection = scenario[scenario_idx][i];
		
		dp[starting_intersection] = 0.0;
		pq.push(make_pair(0.0,starting_intersection));
	}
	
	for(;!pq.empty();)
	{
		double	current_time;
		int		current_intersection;
		
		current_time = -pq.top().first;
		current_intersection = pq.top().second;
		
		pq.pop();
		
		if( current_intersection == crime_intersection )
		{
			break;
		}
		
		vector<Road>&	adj = road[current_intersection];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_intersection = adj[i].first;
			double&	adj_time = adj[i].second;
			
			if( current_time+adj_time < dp[adj_intersection] )
			{
				dp[adj_intersection] = current_time+adj_time;
				pq.push(make_pair(-dp[adj_intersection],adj_intersection));
			}
		}
	}
	
	return	dp[crime_intersection];
}

int		main(void)
{
	input();
	
	for(int i=1;i<=num_of_scenarios;i++)
	{
		double	time;
		
		printf("Scenario %d:\n",i);
		time = get_earliest_arrival_time(i);
				
		if( time == INF )
		{
			puts("Impossible.\n");
		}
		else
		{
			printf("%.2f\n\n",time);
		}
	}
	
	return	0;
}
