#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(10000+1)
#define	MAX_MINUTE	600
#define	INF			(MAX_MINUTE+1)
#define	START_CITY	1

typedef	pair<int,int>	Path;	// fisrt:adj_city,second:minute
typedef	pair<int,int>	State;	// first:-total_minute,second:city

bool	input(int& n,bool* is_hotel,vector<Path>* connected)
{
	int	h,m;
	
	cin>>n;
	
	if( n == 0 )
	{
		return	false;
	}
	
	cin>>h;
	fill(&is_hotel[1],&is_hotel[n+1],false);
	
	for(int i=1;i<=h;i++)
	{
		int	c;
		
		cin>>c;
		is_hotel[c] = true;
	}
	
	cin>>m;
	
	for(int i=1;i<=m;i++)
	{
		int	a,b,t;
		
		cin>>a>>b>>t;
		
		connected[a].push_back(make_pair(b,t));
		connected[b].push_back(make_pair(a,t));
	}
	
	return	true;
}

int		deliver_goods(int& n,bool* is_hotel,vector<Path>* connected)
{
	queue<int>	start_q;
	int			num_of_visited_hotel;
	
	start_q.push(START_CITY);
		
	for(num_of_visited_hotel=0;!start_q.empty();num_of_visited_hotel++)
	{
		for(int i=1,size=start_q.size();i<=size;i++)
		{
			int						s;
			priority_queue<State>	pq;
			vector<int>				dp(n+1,INF);
			
			s = start_q.front();
			start_q.pop();
			
			pq.push(make_pair(0,s));
			dp[s] = 0;
			
			for(;!pq.empty();)
			{
				int	current_city,current_time;
				
				current_time = -pq.top().first;
				current_city = pq.top().second;
				
				pq.pop();
				
				if( current_city == n )
				{
					return	num_of_visited_hotel;
				}
				
				vector<Path>&	adj = connected[current_city];
				
				for(int i=0;i<adj.size();i++)
				{
					int&	adj_city = adj[i].first;
					int&	adj_minute = adj[i].second;
					
					if( current_time+adj_minute < dp[adj_city] )
					{
						dp[adj_city] = current_time+adj_minute;
						pq.push(make_pair(-(current_time+adj_minute),adj_city));
						
						if( is_hotel[adj_city] == true )
						{
							is_hotel[adj_city] = false;
							start_q.push(adj_city);
						}
					}
				}
			}
		}
	}
	
	return	-1;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int				n;
		bool			is_hotel[MAX_SIZE];
		vector<Path>	connected[MAX_SIZE];
		
		if( input(n,is_hotel,connected) == false )
		{
			break;
		}
		
		cout<<deliver_goods(n,is_hotel,connected)<<'\n';
	}
	
	return	0;
}
