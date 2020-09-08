#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_COMPUTER	(10000+1)

typedef	pair<int,int>	State;	// first:time, second:to

int	find_last_inspected_computer(vector<State>* connected,vector<int>& time_table,int first_inspected_computer,int& cnt)
{
	int						max_time;
	priority_queue<State>	pq;
	
	pq.push(make_pair(0,first_inspected_computer));
	cnt = max_time = 0;
	
	while( pq.size() != 0 )
	{
		int	current_computer,current_time;
		
		current_computer = pq.top().second;
		current_time = -pq.top().first;
		pq.pop();
		
		if( time_table[current_computer] <= current_time )
		{
			continue;
		}
		
		if( time_table[current_computer] == 0x7FFFFFFF )
		{
			cnt++;
		}
		
		time_table[current_computer] = current_time;
		max_time = max(max_time,current_time);
		
		for(int i=0;i<connected[current_computer].size();i++)
		{
			int	next_computer,next_time;
			
			next_computer = connected[current_computer][i].second;
			next_time = connected[current_computer][i].first+current_time;
			
			if( next_time < time_table[next_computer] )
			{
				pq.push(make_pair(-next_time,next_computer));
			}
		}
	}
	
	return	max_time;
}

int	main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	while(T>0)
	{
		int	n,d,c;
		
		scanf("%d %d %d",&n,&d,&c);
		
		vector<State>	connected[n+1];
		vector<int>		dp(n+1,0x7FFFFFFF);
		
		for(int i=1;i<=d;i++)
		{
			int	a,b,s;
			
			scanf("%d %d %d",&a,&b,&s);
			connected[b].push_back(make_pair(s,a));
		}
		
		int	max_inspected_time,cnt;
		
		max_inspected_time = find_last_inspected_computer(connected,dp,c,cnt);
		printf("%d %d\n",cnt,max_inspected_time);
		
		T--;
	}
	
	return	0;
}
