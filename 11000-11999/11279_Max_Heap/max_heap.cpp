#include	<iostream>
#include	<queue>

using namespace	std;

typedef	unsigned int	uint32;

priority_queue<uint32>	pq;

int	main(void)
{
	uint32	N;
	
	cin>>N;
	
	for(uint32 i=1;i<=N;i++)
	{
		uint32	x;
		
		cin>>x;
		
		if( x == 0 )
		{
			if( pq.size() != 0 )
			{
				x = pq.top();
				pq.pop();
			}
			cout<<x<<'\n';
		}
		else
		{
			pq.push(x);
		}
	}
	return	0;
}
