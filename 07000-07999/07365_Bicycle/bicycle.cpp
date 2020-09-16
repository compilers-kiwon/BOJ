#include	<iostream>
#include	<queue>

#define	NUM_OF_FRONT_RING	3
#define	NUM_OF_BACK_RING	7

using namespace	std;

typedef	pair<int,int>		Ring;
typedef	pair<double,Ring>	Comb;

int	main(void)
{
	priority_queue<Comb>	pq;
	double					f[NUM_OF_FRONT_RING+1],b[NUM_OF_BACK_RING+1];
	
	for(int i=1;i<=NUM_OF_FRONT_RING;i++)
	{
		scanf("%lf",&f[i]);
	}
	
	for(int j=1;j<=NUM_OF_BACK_RING;j++)
	{
		scanf("%lf",&b[j]);
	}
	
	for(int i=1;i<=NUM_OF_FRONT_RING;i++)
	{
		for(int j=1;j<=NUM_OF_BACK_RING;j++)
		{
			pq.push(make_pair(-(f[i]/b[j]),make_pair(-i,-j)));
		}
	}
	
	for(;!pq.empty();pq.pop())
	{
		printf("%.2f %d %d\n",-pq.top().first,-pq.top().second.first,-pq.top().second.second);
	}
	
	return	0;
}
