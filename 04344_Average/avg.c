#include	<stdio.h>

#define	MAX_NUM_OF_STUDENTS	(1000+1)

int	exam_result[MAX_NUM_OF_STUDENTS];

int	count_higher_score(int num_of_students,int score)
{
	int	result,i;
	
	for(result=0,i=1;i<=num_of_students;i++)
	{
		if( exam_result[i] > score )
		{
			++result;
		}
	}
	return	result;
}

int	main(void)
{
	int	C;
	
	scanf("%d",&C);
	
	while(C>0)
	{
		int		N,i,total,avg;
		int		num_of_students_higher_avg;
				
		scanf("%d",&N);
		
		for(i=1,total=0;i<=N;i++)
		{
			scanf("%d",&exam_result[i]);
			total = total+exam_result[i];
		}
		avg = total/N;
		
		num_of_students_higher_avg = count_higher_score(N,avg);
		
		printf("%.03f%%\n",(double)num_of_students_higher_avg/(double)N*100.0);
		
		C--;
	}
	return	0;
}
