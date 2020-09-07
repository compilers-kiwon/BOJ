#include	<iostream>
#include	<queue>

using namespace	std;

typedef	long long	int64;

priority_queue<int64>	pq;

int	main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int64	x;
		
		cin>>x;
		
		if( x == 0 )
		{
			if( pq.size() == 0 )
			{
				cout<<0<<endl;
			}
			else
			{
				cout<<-pq.top()<<endl;
				pq.pop();
			}
		}
		else
		{
			pq.push(-x);
		}
	}
	return	0;
}
