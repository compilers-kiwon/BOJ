#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_BUILDING	(100+1)
#define	MAX_COST			(10000+1)

int	dp_time[MAX_NUM_OF_BUILDING][MAX_COST];

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO
{
	int	building,money,time;
};

vector<State>	connected[MAX_NUM_OF_BUILDING];

int	find_min_cost(int num_of_building,int time,int money)
{
	for(int building_no=2;building_no<=num_of_building;building_no++)
	{
		for(int my_money=0;my_money<=money;my_money++)
		{
			dp_time[building_no][my_money] = 0x7FFFFFFF;
		}
	}
	
	for(int my_money=0;my_money<=money;my_money++)
	{
		dp_time[1][my_money] = 0;
	}
	
	queue<State>	state_queue;
	int				min_spent_money;
	State			s_tmp;
	
	s_tmp.building = 1;
	s_tmp.time = 0;
	s_tmp.money = 0;
	
	state_queue.push(s_tmp);
	min_spent_money = 0x7FFFFFFF;
	
	while( !state_queue.empty() )
	{
		int	current_building,current_time,current_spent_money;
		
		current_building = state_queue.front().building;
		current_time = state_queue.front().time;
		current_spent_money = state_queue.front().money;
		
		state_queue.pop();
		
		if( current_building == num_of_building )
		{
			min_spent_money = min(min_spent_money,current_spent_money);
			continue;
		}
		
		vector<State>&	adj_building_list = connected[current_building];
		
		for(int i=0;i<adj_building_list.size();i++)
		{
			State&	adj = adj_building_list[i];
			State	next_building_to_move;
			
			next_building_to_move.building = adj.building;
			next_building_to_move.money = current_spent_money+adj.money;
			next_building_to_move.time = current_time+adj.time;
			
			if( next_building_to_move.money<=money && next_building_to_move.time<=time )
			{
				if( next_building_to_move.time < dp_time[next_building_to_move.building][next_building_to_move.money] )
				{
					dp_time[next_building_to_move.building][next_building_to_move.money] = next_building_to_move.time;
					state_queue.push(next_building_to_move);
				}
			}
		}
	}
	
	return	min_spent_money;
}

int	main(void)
{
	int	N,T,M,L;
	
	cin.sync_with_stdio(false);
	
	cin>>N>>T>>M>>L;
	
	for(int i=1;i<=L;i++)
	{
		int		b1,b2,t,c;
		State	s;
		
		cin>>b1>>b2>>t>>c;
		
		s.building = b1;
		s.money = c;
		s.time = t;
		
		connected[b2].push_back(s);
		
		s.building = b2;
		connected[b1].push_back(s);
	}
	
	int	answer;
	
	answer = find_min_cost(N,T,M);
	
	if( answer == 0x7FFFFFFF )
	{
		answer = -1;
	}
	
	cout<<answer<<'\n';
	
	return	0;
}
