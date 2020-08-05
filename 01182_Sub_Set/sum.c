#include	<stdio.h>

#define	MAX_NUM_OF_NUMBERS	(20+1)

int	N,S,answer;
int	numbers[MAX_NUM_OF_NUMBERS];

void	pick_numbers_and_sum(int picked_number_index,int sum)
{
	if( picked_number_index > N )
	{
		if( sum == S )
		{
			++answer;
		}
		return;
	}
	
	pick_numbers_and_sum(picked_number_index+1,sum+numbers[picked_number_index]);
	pick_numbers_and_sum(picked_number_index+1,sum);
}

int		main(void)
{
	int	i;
	
	scanf("%d %d",&N,&S);
	
	for(i=1;i<=N;i++)
	{
		scanf("%d",&numbers[i]);
	}
	
	for(answer=0,i=1;i<=N;i++)
	{
		pick_numbers_and_sum(i+1,numbers[i]);
	}
	printf("%d\n",answer);
	
	return	0;
}
