#include	<iostream>
#include	<queue>
#include	<cmath>

using namespace	std;

typedef	pair<int,int>	Landmark;	// first:-(distance from 0), second:location
int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T,N,time,prev_location,cnt;
	
	cin>>T>>N;
	
	priority_queue<Landmark>	pq;
	
	for(int i=1;i<=N;i++)
	{
		int	x;
		
		cin>>x;
		pq.push(make_pair(-abs(x),x));	
	}
	
	for(time=prev_location=cnt=0;!pq.empty();cnt++)
	{
		int	current_location;
		
		current_location = pq.top().second;
		pq.pop();
		
		time += abs(prev_location-current_location);
		
		if( time > T )
		{
			break;
		}
		
		prev_location = current_location;	
	}
	
	cout<<cnt<<'\n';
	
	return	0;	
}
