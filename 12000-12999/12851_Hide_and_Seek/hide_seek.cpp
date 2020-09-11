#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE			100000
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>	State;	// first:-time, second:X

int	find_min_time(int start,int end,int& cnt)
{
	vector<int>				dp(MAX_SIZE+1,0x7FFFFFFF);
	priority_queue<State>	pq;
	
	int	min_time;
	
	pq.push(make_pair(0,start));
	dp[start] = 0;
	min_time = 0x7FFFFFFF;
	
	while( !pq.empty() )
	{
		int	current_time,current_x;
		
		current_time = -pq.top().first;
		current_x = pq.top().second;
		
		pq.pop();
		
		if( current_x == end )
		{
			if( current_time == min_time )
			{
				cnt++;
			}
			else if( current_time < min_time )
			{
				min_time = current_time;
				cnt = 1;
			}
			else
			{
				break;
			}
			
			continue;
		}
		
		if( current_time > min_time )
		{
			continue;
		}
		
		int	next_time,next_x;
		
		next_time = current_time+1;
		
		// X-1
		next_x = current_x-1;
		
		if( IN_RANGE(0,next_x,MAX_SIZE) && next_time<=dp[next_x] )
		{
			dp[next_x] = next_time;
			pq.push(make_pair(-next_time,next_x));
		}
		
		// X+1
		next_x = current_x+1;
		
		if( IN_RANGE(0,next_x,MAX_SIZE) && next_time<=dp[next_x] )
		{
			dp[next_x] = next_time;
			pq.push(make_pair(-next_time,next_x));
		}
		
		// X*2
		next_x = 2*current_x;
		
		if( IN_RANGE(0,next_x,MAX_SIZE) && next_time<=dp[next_x] )
		{
			dp[next_x] = next_time;
			pq.push(make_pair(-next_time,next_x));
		}
	}
	
	return	min_time;
}

int	main(void)
{
	int	N,K,min_time,cnt;
	
	cin>>N>>K;
	min_time = find_min_time(N,K,cnt);
	
	cout<<min_time<<'\n'<<cnt<<'\n';
	
	return	0;
}
