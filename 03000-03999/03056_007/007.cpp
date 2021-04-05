#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	20

int		N;
double	dp[1<<MAX_SIZE],p[MAX_SIZE][MAX_SIZE];

typedef	pair<int,int>			Assigned;	// first:jimmy,second:finished
typedef	pair<double,Assigned>	State;		// first:probability,second:Assigned

void	input(void)
{
	scanf("%d",&N);
	
	for(int row=0;row<N;row++)
	{
		for(int col=0;col<N;col++)
		{
			scanf("%lf",&p[row][col]);
		}
	}
}

void	init_dp(priority_queue<State>& q)
{
	for(int jimmy=0,job=0;job<N;job++)
	{
		q.push(make_pair(p[jimmy][job],make_pair(jimmy,1<<job)));
		dp[1<<job] = p[jimmy][job];
	}
}

void	get_dp(void)
{
	priority_queue<State>	state_q;
	
	for(init_dp(state_q);!state_q.empty();)
	{
		int		jimmy_to_finish_job,finished_job;
		double	current_probability;
		
		current_probability = state_q.top().first;
		jimmy_to_finish_job = state_q.top().second.first;
		finished_job = state_q.top().second.second;
		
		state_q.pop();
		
		if( jimmy_to_finish_job == N-1 )
		{
			continue;
		}
		
		for(int new_job=0;new_job<N;new_job++)
		{
			if( (finished_job&(1<<new_job)) != 0 )
			{
				continue;
			}
			
			int		next_jimmy = jimmy_to_finish_job+1;
			int		will_be_finished = finished_job|(1<<new_job);
			double	new_probability = current_probability*p[next_jimmy][new_job]/100.0;
			
			if( new_probability > dp[will_be_finished] )
			{
				dp[will_be_finished] = new_probability;
				state_q.push(make_pair(new_probability,make_pair(next_jimmy,will_be_finished)));
			}
		}
	}
}

int		main(void)
{
	input();
	get_dp();
	
	printf("%.12f\n",dp[(1<<N)-1]);
	
	return	0;
}
