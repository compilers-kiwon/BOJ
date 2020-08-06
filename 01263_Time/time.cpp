#include	<iostream>
#include	<queue>

using namespace	std;

typedef	pair<int,int>	Work;	// first:S,second:T

int	main(void)
{
	int						N,start_time;
	priority_queue<Work>	wq;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	T,S;
		
		cin>>T>>S;
		wq.push(make_pair(S,T));
	}
	
	start_time = 0x7FFFFFFF;
	
	while( start_time>=0 && !wq.empty() )
	{
		int	T,S;
		
		T = wq.top().second;
		S = wq.top().first;
		
		wq.pop();
		
		start_time = min(start_time,S)-T;
	}
	
	if( start_time < 0 )
	{
		start_time = -1;
	}
	
	cout<<start_time<<endl;
	
	return	0;
}
