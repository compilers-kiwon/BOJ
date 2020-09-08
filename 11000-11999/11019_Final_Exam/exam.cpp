#include	<iostream>

using namespace	std;

#define	MAX_COURSE	(10+1)
#define	MAX_GRADE	10
#define	MAX_TIME	(100+1)

const double	score[MAX_GRADE+1] = {0.0,4.0,3.7,3.3,3.0,2.7,2.3,2.0,1.7,1.3,1.0};

int		n,H;
int		required_time[MAX_COURSE][MAX_GRADE+1];
double	acquired_score[MAX_COURSE][MAX_TIME];

void	input(void)
{
	scanf("%d %d",&n,&H);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=MAX_GRADE;j++)
		{
			scanf("%d",&required_time[i][j]);
		}
		
		fill(&acquired_score[i][0],&acquired_score[i][H+1],0.0);
	}
}

void	study(void)
{
	for(int i=1;i<=n;i++)
	{
		for(int t=0;t<=H;t++)
		{
			acquired_score[i][t] = acquired_score[i-1][t];
		}
		
		for(int t=0;t<=H;t++)
		{
			for(int g=MAX_GRADE;g>=1;g--)
			{
				int&	time_to_study = required_time[i][g];
				
				if( time_to_study > H )
				{
					break;
				}
				
				acquired_score[i][time_to_study] =
					max(acquired_score[i][time_to_study],score[g]);
				
				if( t+time_to_study > H )
				{
					break;
				}
				
				if( acquired_score[i-1][t] != 0.0 )
				{
					acquired_score[i][t+time_to_study] =
						max(acquired_score[i][t+time_to_study],acquired_score[i-1][t]+score[g]);
				}
			}
		}
	}
}

double	get_max_average(void)
{
	double	max_score;
	
	max_score = 0.0;
	
	for(int t=0;t<=H;t++)
	{
		max_score = max(max_score,acquired_score[n][t]);
	}
	
	return	max_score/(double)n;
}

int		main(void)
{
	int	K;
	
	scanf("%d",&K);
	
	for(int k=1;k<=K;k++)
	{
		input();
		study();
		printf("Data Set %d:\n%.02f\n\n",k,get_max_average());
	}
	
	return	0;
}
