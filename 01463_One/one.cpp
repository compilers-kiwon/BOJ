#include	<iostream>
#include	<queue>

using namespace	std;

typedef	unsigned int		uint32;
typedef	pair<uint32,uint32>	State;

uint32			N;
queue<State>	q;	

int		main(void)
{
	uint32	X,cnt;
	bool	found;
	
	cin>>N;
	q.push(make_pair(N,0));
	found = false;
	
	while( !found )
	{
		X = q.front().first;
		cnt = q.front().second;
		
		q.pop();
		
		if( X == 1 )
		{
			found = true;
			continue;
		}
		
		if( (X%3) == 0 )
		{
			q.push(make_pair(X/3,cnt+1));
		}
		
		if( (X%2) == 0 )
		{
			q.push(make_pair(X/2,cnt+1));
		}
		
		q.push(make_pair(X-1,cnt+1));
	}
	
	cout<<cnt<<endl;
	return	0;
}
