#include	<iostream>
#include	<queue>
#include	<string>

using namespace	std;

#define	MAX_NUM_OF_CITY		50
#define	MAX_NUM_OF_POTION	(50+1)
#define	MAX_TIME			1000000.0

#define	char2int(c)	((int)((c)-'0'))

int		N,K;
double	spent_time[MAX_NUM_OF_CITY][MAX_NUM_OF_POTION];
double	dp[MAX_NUM_OF_CITY][MAX_NUM_OF_POTION];

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO
{
	int		num_of_potion_in_hand,city;
	double	time;
};

void	init(void)
{
	cin>>N>>K;
	
	for(int i=0;i<N;i++)
	{
		string	d;
		
		cin>>d;
		
		for(int j=0;j<N;j++)
		{
			spent_time[i][j] = (double)char2int(d[j]);
		}
		
		for(int j=0;j<=K;j++)
		{
			dp[i][j] = MAX_TIME;
		}
	}
}

double	get_min_time(int from,int to)
{
	queue<State>	state_q;
	State			s;
	double			ret;
	
	s.city = from;
	s.num_of_potion_in_hand = K;
	s.time = 0.0;
	
	state_q.push(s);
	
	for(int i=0;i<=K;i++)
	{
		dp[from][i] = 0.0;
	}
	
	for(ret=MAX_TIME;!state_q.empty();)
	{
		int		current_num_of_potion,current_city;
		double	current_time;
		
		current_num_of_potion = state_q.front().num_of_potion_in_hand;
		current_city = state_q.front().city;
		current_time = state_q.front().time;
		
		state_q.pop();
		
		if( current_city == to )
		{
			ret = min(ret,current_time);
			continue;
		}
		
		for(int adj_city=0;adj_city<N;adj_city++)
		{
			if( adj_city == current_city )
			{
				continue;
			}
			
			double&	adj_time = spent_time[current_city][adj_city];
			double	time_to_be_spent;
			
			// 1. don't use potion
			time_to_be_spent = current_time+adj_time;
			
			if( time_to_be_spent < dp[adj_city][current_num_of_potion] )
			{
				s.city = adj_city;
				s.num_of_potion_in_hand = current_num_of_potion;
				s.time = time_to_be_spent;
				
				state_q.push(s);
				dp[adj_city][current_num_of_potion] = time_to_be_spent;
			}
			
			// 2. use potion
			if( current_num_of_potion > 0 )
			{
				time_to_be_spent = current_time+adj_time/2;
				
				if( time_to_be_spent < dp[adj_city][current_num_of_potion-1] )
				{
					s.city = adj_city;
					s.num_of_potion_in_hand = current_num_of_potion-1;
					s.time = time_to_be_spent;
					
					state_q.push(s);
					dp[adj_city][current_num_of_potion-1] = time_to_be_spent;
				}	
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	init();
	printf("%.9lf\n",get_min_time(0,1));

	return	0;
}
