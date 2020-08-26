#include <iostream>

using namespace std;

#define	MAX_NUM_OF_WOOD	(1000000+1)

typedef	unsigned long long	uint64;

uint64 wood[MAX_NUM_OF_WOOD];

int	main(void)
{
	int		N,M;
	uint64	lo,mid,hi,answer;
	
	ios::sync_with_stdio(false);
	
	cin>>N>>M;

	for(int i=1;i<=N;i++)
	{
		cin>>wood[i];
	}
	
	lo = 0;
	hi = 1000000000;
	answer = 0;
	
	while (lo<=hi)
	{
		mid = (lo+hi)>>1;
	
		uint64	cut_wood;
		
		cut_wood = 0;
		
		for(int i=1;i<=N;i++)
		{
			if( wood[i] > mid )
			{
				cut_wood += wood[i]-mid;
			}
		}
		
		if( cut_wood >= M)
		{
			lo = mid+1;
			
			if( answer < mid )
			{
				answer = mid;
			}
		}
		else
		{
			hi = mid-1;
		}
	}
	cout<<answer<<'\n';

	return 0;
}
