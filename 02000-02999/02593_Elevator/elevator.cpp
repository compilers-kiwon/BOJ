#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_FLOOR	(100000+1)
#define	MAX_NUM_OF_ELEVATOR	(100+1)

#define	is_accessible_elevator(f,base,offset) ((f)>=(base)&&((f)-(base))%(offset)==0)

typedef	pair<int,int>	State;		// first:-num_of_movement, second:elevator_no
typedef	State			Elevator;	// first:X, second:Y

vector<int>			floor_to_elevator[MAX_NUM_OF_FLOOR];
vector<int>			elevator_to_floor[MAX_NUM_OF_ELEVATOR];
vector<int>			dp(MAX_NUM_OF_ELEVATOR,0x7FFFFFFF);
vector<Elevator>	elevator(MAX_NUM_OF_ELEVATOR);

int		N,M,A,B;
int		where_is_from[MAX_NUM_OF_ELEVATOR];

void	input(void)
{
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=M;i++)
	{
		int	X,Y;
		
		scanf("%d %d",&X,&Y);
		
		elevator[i].first = X;
		elevator[i].second = Y;
		
		for(int f=X;f<=N;f+=Y)
		{
			elevator_to_floor[i].push_back(f);
			floor_to_elevator[f].push_back(i);
		}
	}
	
	scanf("%d %d",&A,&B);
}

void	move_floor(void)
{
	priority_queue<State>	pq;
	State					s;
	
	s.first = 0;
	
	for(int i=0;i<floor_to_elevator[A].size();i++)
	{
		s.second = floor_to_elevator[A][i];
		pq.push(s);
		dp[floor_to_elevator[A][i]] = 0;
	}
	
	while( !pq.empty() )
	{
		int	current_elevator,current_num_of_movement,next_num_of_movement;
		
		current_elevator = pq.top().second;
		current_num_of_movement = -pq.top().first;
		next_num_of_movement = current_num_of_movement+1;
		
		pq.pop();
		
		for(int i=0;i<elevator_to_floor[current_elevator].size();i++)
		{
			int&	current_floor = elevator_to_floor[current_elevator][i];
			
			for(int j=0;j<floor_to_elevator[current_floor].size();j++)
			{
				int&	next_elevator = floor_to_elevator[current_floor][j];
				
				if( dp[next_elevator] > next_num_of_movement )
				{
					dp[next_elevator] = next_num_of_movement;
					where_is_from[next_elevator] = current_elevator;
					pq.push(make_pair(-next_num_of_movement,next_elevator));
				}
			}
		}
	}
}

int		main(void)
{
	input();
	move_floor();
	
	int	min_num_of_movement,last_elevator;
	
	min_num_of_movement = 0x7FFFFFFF;
	
	for(int i=1;i<=M;i++)
	{
		if( is_accessible_elevator(B,elevator[i].first,elevator[i].second) && dp[i]<min_num_of_movement )
		{
			min_num_of_movement = dp[i];
			last_elevator = i;
		}
	}
	
	if( min_num_of_movement == 0x7FFFFFFF )
	{
		puts("-1");
	}
	else
	{
		vector<int>	path;
		
		printf("%d\n",min_num_of_movement+1);
		
		for(int i=last_elevator;i!=0;i=where_is_from[i])
		{
			path.push_back(i);
		}
		
		for(int i=path.size()-1;i>=0;i--)
		{
			printf("%d\n",path[i]);
		}
	}
	
	return	0;
}
