#include	<stdio.h>

#define	MAX_NUM_OF_TESTING_GROUNDS	(1000000+1)

typedef	unsigned int		uint32;
typedef	unsigned long long	uint64;

uint32	N,participants[MAX_NUM_OF_TESTING_GROUNDS],B,C;

int	main(void)
{
	uint32	i;
	uint64	answer;
	
	scanf("%u",&N);
	
	for(i=1;i<=N;i++)
	{
		scanf("%u",&participants[i]);
	}
	
	scanf("%u %u",&B,&C);
	
	for(answer=N,i=1;i<=N;i++)
	{
		uint32	tmp1,tmp2,tmp3,num_of_C;
		
		if( participants[i] <= B )
		{
			continue;
		}
		
		tmp1 = participants[i]-B;
		tmp2 = tmp1/C;
		tmp3 = tmp1%C;
		
		if( tmp3 == 0 )
		{
			answer = answer+tmp2;
		}
		else
		{
			answer = answer+tmp2+1;
		}
	}
	printf("%llu\n",answer);
	
	return	0;
}
