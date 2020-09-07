#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_CRANE	(50+1)
#define	MAX_NUM_OF_BAGGAGE	(10000+1)

int	crane[MAX_NUM_OF_CRANE],baggage[MAX_NUM_OF_BAGGAGE];

int	main(void)
{
	int			N,M;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&crane[i]);
	}
	
	scanf("%d",&M);
	
	for(int i=1;i<=M;i++)
	{
		scanf("%d",&baggage[i]);
	}
	
	sort(&crane[1],&crane[N+1]);
	sort(&baggage[1],&baggage[M+1]);
	
	if( crane[N] < baggage[M] )
	{
		puts("-1");
		return	0;
	}
	
	int	num_of_loaded_baggage,time;
	
	for(num_of_loaded_baggage=time=0;num_of_loaded_baggage!=M;time++)
	{
		for(int c=N,b=M;c>=1&&b>=1;b--)
		{
			if( baggage[b] == 0 )
			{
				continue;
			}
			
			if( baggage[b] <= crane[c] )
			{
				baggage[b] = 0;
				c--;
				num_of_loaded_baggage++;
			}

		}
	}
	
	printf("%d\n",time);
	
	return	0;
}
