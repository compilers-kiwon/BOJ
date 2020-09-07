#include	<iostream>
#include	<vector>
#include	<queue>
#include	<cfloat>

using namespace	std;

#define	MAX_NUM_OF_CITY	(200+1)
#define	INF				DBL_MAX

#define	FALSE	0
#define	TRUE	1

typedef	struct	_TICKET_INFO	Ticket;
struct	_TICKET_INFO
{
	double	base_cost,additional_cost,base_fine;
};

typedef	struct	_RAIL_INFO		Rail;
struct	_RAIL_INFO
{
	int		to;
	double	possiblity,distance;
};

typedef	pair< double,pair<int,int> >	State;	// fisrt:-cost,<first:city,second:base_cost_is_paid>

double	find_min_cost(int start,int end,vector<Rail>* connected,Ticket& t,int num_of_city)
{
	priority_queue<State>	pq;
	double					dp[MAX_NUM_OF_CITY][TRUE+1];
	
	for(int i=1;i<=num_of_city;i++)
	{
		dp[i][FALSE] = dp[i][TRUE] = INF;
	}
	
	dp[start][FALSE] = dp[start][TRUE] = 0.0;
	pq.push(make_pair(0.0,make_pair(start,FALSE)));
	
	for(;!pq.empty();)
	{
		int		current_city,is_paid;
		double	current_cost;
		
		current_cost = -pq.top().first;
		current_city = pq.top().second.first;
		is_paid = pq.top().second.second;
		
		pq.pop();
		
		if( current_city == end )
		{
			continue;
		}
		
		vector<Rail>&	adj_vec = connected[current_city];
		
		for(int i=0;i<adj_vec.size();i++)
		{
			int&	adj_city = adj_vec[i].to;
			double&	check_possiblity = adj_vec[i].possiblity;
			double&	travel_distance = adj_vec[i].distance;
			double	normal,fine;
			
			fine = (t.base_fine+t.additional_cost*travel_distance)*check_possiblity;
			
			if( is_paid == TRUE )
			{
				normal = t.additional_cost*travel_distance;
			}
			else
			{
				normal = t.base_cost+t.additional_cost*travel_distance;
			}
				
			// normal
			if( current_cost+normal < dp[adj_city][TRUE] )
			{
				dp[adj_city][TRUE] = current_cost+normal;
				pq.push(make_pair(-dp[adj_city][TRUE],make_pair(adj_city,TRUE)));
			}
			
			// fine
			if( current_cost+fine < dp[adj_city][FALSE] )
			{
				dp[adj_city][FALSE] = current_cost+fine;
				pq.push(make_pair(-dp[adj_city][FALSE],make_pair(adj_city,FALSE)));
			}
		}
	}
	
	return	min(dp[end][TRUE],dp[end][FALSE]);
}

int		main(void)
{
	int	T;
	
	for(scanf("%d",&T);T>0;T--)
	{
		int				n,m,start,end;
		Ticket			t;
		vector<Rail>	connected[MAX_NUM_OF_CITY];
		
		scanf("%d %d %d %d",&n,&m,&start,&end);
		scanf("%lf %lf %lf",&t.base_cost,&t.additional_cost,&t.base_fine);
		
		for(int i=1;i<=m;i++)
		{
			int		a,b;
			Rail	r;
			
			scanf("%d %d %lf %lf",&a,&b,&r.possiblity,&r.distance);
			
			r.possiblity /= 100.0;
			
			r.to = b;
			connected[a].push_back(r);
			
			r.to = a;
			connected[b].push_back(r);
		}
		printf("%.02lf\n",find_min_cost(start,end,connected,t,n));
	}
	
	return	0;
}
