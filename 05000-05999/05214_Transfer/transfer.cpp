#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_STATION	(100000+1)
#define	MAX_NUM_OF_TUBE		(1000+1)

typedef	pair<int,int>	State;

#define	station					first
#define	num_of_visited_station	second

vector<int>		my_tube[MAX_NUM_OF_STATION];
vector<int>		tube[MAX_NUM_OF_TUBE];
vector<bool>	visited_station(MAX_NUM_OF_STATION,false);
vector<bool>	visited_tube(MAX_NUM_OF_TUBE,false);

int	N,K,M;

void	init(void)
{
	scanf("%d %d %d",&N,&K,&M);
	
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=K;j++)
		{
			int	st;
			
			scanf("%d",&st);
			
			my_tube[st].push_back(i);
			tube[i].push_back(st);
		}
	}
}

int		find_path(void)
{
	queue<State>	state_q;
	int				min_num_of_visited_station;
	
	state_q.push(make_pair(1,1));
	visited_station[1] = true;
	min_num_of_visited_station = -1;
	
	while( state_q.size() != 0 )
	{
		int	current_station,current_num_of_visited_station;
		
		current_station = state_q.front().station;
		current_num_of_visited_station = state_q.front().num_of_visited_station;
		
		state_q.pop();
		
		if( current_station == N )
		{
			min_num_of_visited_station = current_num_of_visited_station;
			break;
		}
		
		for(int i=0;i<my_tube[current_station].size();i++)
		{
			int&			tube_of_current_station = my_tube[current_station][i];
			
			if( visited_tube[tube_of_current_station] == false )
			{
				visited_tube[tube_of_current_station] = true;
			
				vector<int>&	current_tube = tube[tube_of_current_station];
				
				for(int j=0;j<current_tube.size();j++)
				{
					int&	next_station = current_tube[j];
					
					if( visited_station[next_station] == false )
					{
						visited_station[next_station] = true;
						state_q.push(make_pair(next_station,current_num_of_visited_station+1));
					}
				}
			}
		}
	}
	
	return	min_num_of_visited_station;
}

int		main(void)
{
	init();
	printf("%d\n",find_path());
	
	return	0;
}
