#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_OUTHOUSE	(20000+1)

typedef	pair<int,int>	State;	// first:-distance, second:outhouse

vector<int>	connected[MAX_NUM_OF_OUTHOUSE];
int			distance_table[MAX_NUM_OF_OUTHOUSE];

void	check_outhouse_distance(int from)
{
	priority_queue<State>	pq;
	State					init;
	
	init = make_pair(0,1);
	pq.push(init);
	
	while( pq.size() != 0 )
	{
		int	current_outhouse,current_distance;
		
		current_outhouse = pq.top().second;
		current_distance = -pq.top().first;
		
		pq.pop();
		
		if( current_distance > distance_table[current_outhouse] )
		{
			continue;
		}
		
		distance_table[current_outhouse] = current_distance;
		
		vector<int>& to_outhouse = connected[current_outhouse];
		
		int	next_distance;
		
		next_distance = current_distance+1;
		
		for(int i=0;i<to_outhouse.size();i++)
		{
			int& next_outhouse = to_outhouse[i];
			
			if( next_distance < distance_table[next_outhouse] )
			{
				distance_table[next_outhouse] = next_distance;
				pq.push(make_pair(-next_distance,next_outhouse));
			}
		}
	}
}

int		main(void)
{
	int	N,M;
	
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=N;i++)
	{
		distance_table[i] = 0x7FFFFFFF;
	}
	
	for(int i=1;i<=M;i++)
	{
		int	A,B;
		
		scanf("%d %d",&A,&B);
		
		connected[A].push_back(B);
		connected[B].push_back(A);
	}
	
	check_outhouse_distance(1);
	
	int	max_distance_outhouse,max_distance,cnt;
	
	max_distance = -1;
	
	for(int i=1;i<=N;i++)
	{
		if( distance_table[i] > max_distance )
		{
			max_distance_outhouse = i;
			max_distance = distance_table[i];
			cnt = 1;
		}
		else if( distance_table[i] == max_distance )
		{
			cnt++;
		}
	}
	
	printf("%d %d %d\n",max_distance_outhouse,max_distance,cnt);
	
	return	0;
}
