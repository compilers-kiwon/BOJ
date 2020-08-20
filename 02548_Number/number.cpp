#include	<iostream>
#include	<cmath>

using namespace	std;

#define	MAX_NUM_OF_NUMBERS	(20000+1)

int	get_sum_of_diff(int* numbers,int size,int n)
{
	int	sum,i;
	
	for(i=1,sum=0;i<=size;i++)
	{
		sum += abs(numbers[i]-n);
	}
	
	return	sum;
}

int	main(void)
{
	int	N,numbers[MAX_NUM_OF_NUMBERS];
	int	num_of_min_diff,min_diff;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&numbers[i]);
	}
	
	min_diff = 0x7FFFFFFF;
	
	for(int i=1;i<=N;i++)
	{
		int	tmp;
		
		tmp = get_sum_of_diff(numbers,N,numbers[i]);
		
		if( (tmp<min_diff) || (tmp==min_diff && num_of_min_diff>numbers[i]) )
		{
			min_diff = tmp;
			num_of_min_diff = numbers[i];
		}
	}
	
	printf("%d\n",num_of_min_diff);
	
	return	0;
}
