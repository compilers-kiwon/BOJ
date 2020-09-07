#include	<iostream>

using namespace	std;

#define	NUM_OF_NUMBERS	5

int	get_max_num(int* numbers)
{
	int	max_num,i,j,k;
	
	for(max_num=0,i=1;i<=NUM_OF_NUMBERS-2;i++)
	{
		for(j=i+1;j<=NUM_OF_NUMBERS-1;j++)
		{
			for(k=j+1;k<=NUM_OF_NUMBERS;k++)
			{
				int	tmp;
				
				tmp = numbers[i]+numbers[j]+numbers[k];
				max_num = max(max_num,tmp%10);
			}
		}		
	}
	
	return	max_num;
}

int	main(void)
{
	int	N,max_num,i,numbers[NUM_OF_NUMBERS+1],winner;
	
	scanf("%d",&N);
	
	for(max_num=0,i=1;i<=N;i++)
	{
		int	tmp;
		
		scanf("%d %d %d %d %d",&numbers[1],&numbers[2],&numbers[3],&numbers[4],&numbers[5]);
		
		tmp = get_max_num(numbers);
		
		if( tmp >= max_num )
		{
			max_num = tmp;
			winner = i;
		}
	}
	
	printf("%d\n",winner);
	
	return	0;
}
