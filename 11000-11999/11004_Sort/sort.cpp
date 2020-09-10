#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_NUMBERS	(5000000+1)

int	numbers[MAX_NUM_OF_NUMBERS];

int	main(void)
{
	int	N,K,i,j,a,b;
	
	scanf("%d %d",&N,&K);
	
	a = N/10;
	b = N%10;
	
	for(i=1,j=1;j<=a;j++,i+=10)
	{
		scanf("%d %d %d %d %d %d %d %d %d %d",&numbers[i],&numbers[i+1],&numbers[i+2],&numbers[i+3],
			 &numbers[i+4],&numbers[i+5],&numbers[i+6],&numbers[i+7],&numbers[i+8],&numbers[i+9]);
	}
	
	for(j=1;j<=b;j++,i++)
	{
		scanf("%d",&numbers[i]);
	}
	
	sort(&numbers[1],&numbers[N+1]);
	
	printf("%d\n",numbers[K]);
	
	return	0;
}
