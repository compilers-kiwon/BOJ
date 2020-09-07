#include	<iostream>
#include	<queue>
#include	<vector>
#include	<cfloat>

using namespace	std;

#define	MAX_NUM_OF_CITY		(30+1)
#define	MAX_NUM_OF_TICKET	8

#define	used_ticket(ticket_info,ticket_idx)	(((ticket_info)&(1<<(ticket_idx)))!=0)
#define	use_ticket(ticket_info,ticket_idx)	((ticket_info)|(1<<(ticket_idx)))

typedef	pair<int,double>	Path;	// first:to,second:time

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO{
	int		city,used_ticket;
	double	travel_time;
};

double	get_shortest_time(vector<Path>* connected,double* ticket_info,
						  int num_of_ticket,int start,int end,int num_of_city)
{
	State			s;
	queue<State>	state_q;
	vector<double>	dp[num_of_city+1];
	double			ret;
	
	for(int i=1;i<=num_of_city;i++)
	{
		dp[i].resize(1<<num_of_ticket,DBL_MAX);
	}
	
	s.city = start;
	s.used_ticket = 0;
	s.travel_time = 0.0;
	
	ret = DBL_MAX;
	state_q.push(s);
	fill(&dp[start][0],&dp[start][1<<num_of_ticket],0.0);
	
	for(;!state_q.empty();)
	{
		int		current_city,current_used_ticket;
		double	current_travel_time;
		
		current_city = state_q.front().city;
		current_used_ticket = state_q.front().used_ticket;
		current_travel_time = state_q.front().travel_time;
		
		state_q.pop();
		
		if( current_city == end )
		{
			ret = min(ret,current_travel_time);
			continue;
		}
		
		vector<Path>&	adj = connected[current_city];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_city = adj[i].first;
			double&	adj_dist = adj[i].second;
			
			for(int t=0;t<num_of_ticket;t++)
			{
				if( used_ticket(current_used_ticket,t) == true )
				{
					continue;
				}
				
				int		adj_used_ticket;
				double	adj_travel_time;
				
				adj_used_ticket = use_ticket(current_used_ticket,t);
				adj_travel_time = current_travel_time+(adj_dist/ticket_info[t]);
				
				if( adj_travel_time < dp[adj_city][adj_used_ticket] )
				{
					dp[adj_city][adj_used_ticket] = adj_travel_time;
					
					s.city = adj_city;
					s.used_ticket = adj_used_ticket;
					s.travel_time = adj_travel_time;
					
					state_q.push(s);
				}
			}
		}
	}
	
	return	ret;
}

bool	input(int& num_of_ticket,int& num_of_city,int& num_of_roads,
			  int& start,int& end,double* ticket_info,vector<Path>* connected)
{
	scanf("%d %d %d %d %d",&num_of_ticket,&num_of_city,&num_of_roads,&start,&end);
	
	if( num_of_ticket==0 && num_of_city==0 && num_of_roads==0 && start==0 && end==0 )
	{
		return	false;
	}
	
	for(int t=0;t<num_of_ticket;t++)
	{
		scanf("%lf",&ticket_info[t]);
	}
	
	for(int i=1;i<=num_of_roads;i++)
	{
		int		x,y;
		double	z;
		
		scanf("%d %d %lf",&x,&y,&z);
		
		connected[x].push_back(make_pair(y,z));
		connected[y].push_back(make_pair(x,z));
	}
	return	true;
}

int		main(void)
{
	for(;;)
	{
		int				n,m,p,a,b;
		double			t[MAX_NUM_OF_TICKET],min_time;
		vector<Path>	connected[MAX_NUM_OF_CITY];
		
		if( input(n,m,p,a,b,t,connected) == false )
		{
			break;
		}
		
		min_time = get_shortest_time(connected,t,n,a,b,m);
		
		if( min_time == DBL_MAX )
		{
			puts("Impossible");
		}
		else
		{
			printf("%.03f\n",min_time);
		}
	}
	
	return	0;
}
