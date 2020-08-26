#include	<iostream>
#include	<queue>
#include	<map>
#include	<cmath>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	NONE		0

#define	FORWARD		1
#define	BACKWARD	-1

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>	Move;	// first:pos, second:step
typedef	pair<int,Move>	State;	// first:-cost, second:Move

int						N,fee[MAX_SIZE];
priority_queue<State>	pq;
int						dp[MAX_SIZE][MAX_SIZE];	// dp[pos][step] = cost

void	move(int cost,int pos,int step,int d)
{
	int	adj_cost,adj_pos,adj_step;
	
	if( d == FORWARD )
	{
		adj_step = step+1;
		adj_pos = pos+adj_step;
	}
	else
	{
		adj_step = step;
		adj_pos = pos-adj_step;
	}
	if( IN_RANGE(1,adj_pos,N) == false )
	{
		return;
	}
	
	adj_cost = cost+fee[adj_pos];
	
	if( dp[adj_pos][adj_step]==NONE || adj_cost<dp[adj_pos][adj_step] )
	{
		dp[adj_pos][adj_step] = adj_cost;
		pq.push(make_pair(-adj_cost,make_pair(adj_pos,adj_step)));
	}
}

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>fee[i];
	}
}

int		jump(void)
{
	int	ret;
	
	dp[1][0] = fee[1];
	pq.push(make_pair(-fee[1],make_pair(1,0)));
	
	for(;!pq.empty();)
	{
		int	current_cost,current_pos,current_step;
		
		current_cost = -pq.top().first;
		current_pos = pq.top().second.first;
		current_step = pq.top().second.second;
		
		pq.pop();
		
		if( current_pos == N )
		{
			ret = current_cost-fee[1]; 
			break;
		}
		
		move(current_cost,current_pos,current_step,FORWARD);
		move(current_cost,current_pos,current_step,BACKWARD);
	}
	
	return	ret;
}

int		main(void)
{
	input();
	cout<<jump()<<'\n';
	
	return	0;
}
