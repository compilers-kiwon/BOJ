#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_REPAIR	100

typedef	pair<int,int>	State;

int	max_distance_to_go,num_of_repair_shop;
int	distance_from_start[MAX_NUM_OF_REPAIR+2],repair_time[MAX_NUM_OF_REPAIR+2];
int	prev_repair_shop[MAX_NUM_OF_REPAIR+2];

vector<int>	connected[MAX_NUM_OF_REPAIR+1];

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>max_distance_to_go>>num_of_repair_shop;
	
	for(int i=1;i<=num_of_repair_shop+1;i++)
	{
		int	d;
		
		cin>>d;
		distance_from_start[i] = distance_from_start[i-1]+d;
	}
	
	for(int i=1;i<=num_of_repair_shop;i++)
	{
		cin>>repair_time[i];
	}
}

void	build_graph(void)
{
	for(int i=0;i<=num_of_repair_shop;i++)
	{
		for(int j=i+1;j<=num_of_repair_shop+1;j++)
		{
			if( distance_from_start[j]-distance_from_start[i] > max_distance_to_go )
			{
				break;
			}
			
			connected[i].push_back(j);
		}
	}
}

int		find_min_time_to_repair(void)
{
	priority_queue<State>	rq;
	vector<int>				dp(num_of_repair_shop+2,0x7FFFFFFF);
	
	dp[0] = 0;
	rq.push(make_pair(0,0));
	
	while( !rq.empty() )
	{
		int	current_spent_time_for_repair,current_repair_shop;
		
		current_spent_time_for_repair = -rq.top().first;
		current_repair_shop = rq.top().second;
		
		rq.pop();
		
		if( current_repair_shop == num_of_repair_shop+1 )
		{
			break; 
		}
		
		vector<int>& adj_repair_shops = connected[current_repair_shop];
		
		for(int i=0;i<adj_repair_shops.size();i++)
		{
			int	adj_repair_time;
			
			adj_repair_time = current_spent_time_for_repair+repair_time[adj_repair_shops[i]];
			
			if( adj_repair_time < dp[adj_repair_shops[i]] )
			{
				dp[adj_repair_shops[i]] = adj_repair_time;
				prev_repair_shop[adj_repair_shops[i]] = current_repair_shop;
				rq.push(make_pair(-adj_repair_time,adj_repair_shops[i]));
			}
		}
	}
	
	return	dp[num_of_repair_shop+1];
}

int		main(void)
{
	init();
	build_graph();
	
	int	min_spent_time;
	
	min_spent_time = find_min_time_to_repair();
	
	if( min_spent_time==0 || min_spent_time==0x7FFFFFFF )
	{
		cout<<"0\n0\n";
	}
	else
	{
		cout<<min_spent_time<<'\n';
		
		vector<int>	repair_path;
		
		for(int i=prev_repair_shop[num_of_repair_shop+1];i!=0;i=prev_repair_shop[i])
		{
			repair_path.push_back(i);
		}
		
		cout<<repair_path.size()<<'\n';
		
		for(int i=repair_path.size()-1;i>0;i--)
		{
			cout<<repair_path[i]<<' ';
		}
		cout<<repair_path[0]<<'\n';
	}
	
	return	0;
}
