#include	<iostream>
#include	<queue>

using namespace	std;

#define	BEGIN	0
#define	END		1

typedef	pair<int,int>	Event;	// first:-time,second:type

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N,cnt,max_cnt;
	
	cin>>N;
	cnt = max_cnt = 0;
	
	priority_queue<Event>	event_q;
	
	for(int i=1;i<=N;i++)
	{
		int	S,T;
		
		cin>>S>>T;
		
		event_q.push(make_pair(-S,BEGIN));
		event_q.push(make_pair(-T,END));
	}
	
	for(;!event_q.empty();)
	{
		if( event_q.top().second == BEGIN )
		{
			cnt++;
		}
		else
		{
			cnt--;
		}
		
		event_q.pop();
		max_cnt = max(max_cnt,cnt);
	}
	
	cout<<max_cnt<<'\n';
	
	return	0;
}	
