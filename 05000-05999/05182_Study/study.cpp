#include	<iostream>

using namespace	std;

#define	MAX_GRADE			10
#define	MAX_COURSES			(10+1)
#define	MAX_STUDYING_TIME	(100+1)

const double	grade[MAX_GRADE+1] = {0.0,1.0,1.3,1.7,2.0,2.3,2.7,3.0,3.3,3.7,4.0};

void	input(int& num_of_courses,
			  int& available_time_for_studying,
			  int required_time[][MAX_GRADE+1])
{
	scanf("%d %d",&num_of_courses,&available_time_for_studying);
	
	for(int i=1;i<=num_of_courses;i++)
	{
		for(int j=MAX_GRADE;j>=1;j--)
		{
			scanf("%d",&required_time[i][j]);
		}
	}
}

double	get_max_grade(int num_of_courses,int available_time,int required_time[][MAX_GRADE+1])
{
	double	ret,table[MAX_COURSES][MAX_STUDYING_TIME];
	
	for(int i=1;i<=num_of_courses;i++)
	{
		fill(&table[i][0],&table[i][available_time+1],0.0);
	}
	
	for(int i=1;i<=num_of_courses;i++)
	{
		for(int g=1;g<=MAX_GRADE;g++)
		{
			int&	studying_time = required_time[i][g];
			
			table[i][studying_time] = grade[g];
		}
		
		for(int t=0;t<=available_time;t++)
		{
			double	prev_grade = table[i-1][t];
			
			if( prev_grade != 0.0 )
			{
				table[i][t] = max(table[i][t],prev_grade);
				
				for(int j=1;j<=MAX_GRADE;j++)
				{
					int	current_studying_time = required_time[i][j];
					
					if( t+current_studying_time <= available_time )
					{
						table[i][t+current_studying_time] = 
							max(table[i][t+current_studying_time],prev_grade+grade[j]);
					}
				}
			}
		}
	}
	
	ret = 0.0;
	
	for(int t=0;t<=available_time;t++)
	{
		ret = max(ret,table[num_of_courses][t]);
	}
	
	return	ret;
}

int		main(void)
{
	int	K;
	
	scanf("%d",&K);
	
	for(int k=1;k<=K;k++)
	{
		int		num_of_courses,available_time;
		int		required_time[MAX_COURSES][MAX_GRADE+1];
		double	max_grade;
		
		input(num_of_courses,available_time,required_time);
		
		max_grade = get_max_grade(num_of_courses,available_time,required_time);
		printf("Data Set %d:\n%.2f\n",k,max_grade/(double)num_of_courses);
	}
	
	return	0;
}
