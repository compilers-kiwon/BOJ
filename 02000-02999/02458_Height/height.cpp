#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_STUDENTS	(500+1)
#define	MAX_DISTANCE		1000

int		student[MAX_NUM_OF_STUDENTS][MAX_NUM_OF_STUDENTS];
int		N,M;

void	input(void)
{
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			student[i][j] = MAX_DISTANCE;
		}
		student[i][i] = 0;
	}
	
	for(int i=1;i<=M;i++)
	{
		int	a,b;
		
		scanf("%d %d",&a,&b);
		student[a][b] = 1;
	}
}

int		main(void)
{
	input();
	
	for(int k=1;k<=N;k++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if( student[i][j] > student[i][k]+student[k][j] )
				{
					student[i][j] = student[i][k]+student[k][j];
				}
			}
		}
	}
	
	int	cnt = 0;
	
	for(int i=1;i<=N;i++)
	{
		++cnt;
		
		for(int j=1;j<=N;j++)
		{
			if( student[i][j] == MAX_DISTANCE && student[j][i] == MAX_DISTANCE )
			{
				--cnt;
				break;
			}
		}
	}
	cout<<cnt<<endl;
	
	return	0;
}
