#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

typedef	pair< int,pair<int,int> >	State;

#define	MAX_NUM_OF_COMPUTER	(1000+1)

int	N,P,K;
int	cost_table[MAX_NUM_OF_COMPUTER][MAX_NUM_OF_COMPUTER];

vector< pair<int,int> >	connected[MAX_NUM_OF_COMPUTER];

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N>>P>>K;
	
	for(int i=2;i<=N;i++)
	{
		for(int j=0;j<=K;j++)
		{
			cost_table[i][j] = 0x7FFFFFFF;
		}
	}
	
	for(int i=1;i<=P;i++)
	{
		int	a,b,c;
		
		cin>>a>>b>>c;
		
		connected[a].push_back(make_pair(b,c));
		connected[b].push_back(make_pair(a,c));
	}
}

int		find_min_cost(void)
{
	priority_queue<State>	state_q;
	int						min_cost;
	
	state_q.push(make_pair(0,make_pair(1,0)));
	min_cost = 0x7FFFFFFF;
	
	while( !state_q.empty() )
	{
		int	current_cost,current_computer,current_num_of_free_connection;
		
		current_cost = -state_q.top().first;
		current_computer = state_q.top().second.first;
		current_num_of_free_connection = state_q.top().second.second;
		
		state_q.pop();
		
		if( current_computer == N )
		{
			min_cost = min(min_cost,current_cost);
			continue;
		}
		
		vector< pair<int,int> >&	adj_computers = connected[current_computer];
		
		for(int i=0;i<adj_computers.size();i++)
		{
			int&	adj_computer = adj_computers[i].first;
			int&	adj_cost = adj_computers[i].second;
			
			// not_free
			if( max(current_cost,adj_cost) < cost_table[adj_computer][current_num_of_free_connection] )
			{
				cost_table[adj_computer][current_num_of_free_connection] = max(current_cost,adj_cost);
				state_q.push(make_pair(-max(current_cost,adj_cost),make_pair(adj_computer,current_num_of_free_connection)));
				//cout<<current_computer<<"=>"<<adj_computer<<",max:"<<max(current_cost,adj_cost)<<",remain:"<<K-current_num_of_free_connection<<'\n';
			}
			
			// free
			if( current_num_of_free_connection < K )
			{
				if( current_cost < cost_table[adj_computer][current_num_of_free_connection+1] )
				{
					cost_table[adj_computer][current_num_of_free_connection+1] = current_cost;
					state_q.push(make_pair(-current_cost,make_pair(adj_computer,current_num_of_free_connection+1)));
					//cout<<current_computer<<"=>"<<adj_computer<<",max:"<<current_cost<<",remain:"<<K-current_num_of_free_connection-1<<'\n';
				}
			}
		}
	}
	
	if( min_cost == 0x7FFFFFFF )
	{
		min_cost = -1;
	}
	
	return	min_cost;
}

int		main(void)
{
	init();
	cout<<find_min_cost()<<'\n';
	
	return	0;	
}
