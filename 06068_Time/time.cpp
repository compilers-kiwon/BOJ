#include	<iostream>
#include	<queue>

using namespace	std;

typedef	pair<int,int>	Task; // first:start, second:duration.

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int		N,max_time;
	bool	result;
	
	cin>>N;
	
	result = true;
	max_time = 0;
	
	priority_queue<Task>	pq;
	
	for(int i=1;i<=N;i++)
	{
		int	T,S;
		
		cin>>T>>S;
		pq.push(make_pair(S-T,T));
		max_time = max(max_time,S);
	}
	
	for(;!pq.empty();)
	{
		int	should_be_started,duration;
		
		should_be_started = pq.top().first;
		duration = pq.top().second;
		
		pq.pop();
		//cout<<"max_time="<<max_time<<",should_be_started="<<should_be_started<<",duration="<<duration<<'\n';
		//if( max_time-duration > should_be_started )
		//{
		//	result = false;
		//	break;
		//}
		
		max_time = min(should_be_started,max_time-duration);
	}
	
	if( max_time >= 0 )
	{
		cout<<max_time<<'\n';
	}
	else
	{
		cout<<"-1\n";
	}
	
	return	0;
}
