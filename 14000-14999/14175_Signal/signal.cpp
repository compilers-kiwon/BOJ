#include	<iostream>

using namespace	std;

#define	MAX_SIZE	10
#define	MAX_BIGGER	10

int		M,N,K;
char	original[MAX_SIZE][MAX_SIZE+1],modified[MAX_SIZE*MAX_BIGGER][MAX_SIZE*MAX_BIGGER+1];

int		main(void)
{
	scanf("%d %d %d",&M,&N,&K);
	
	for(int i=0;i<M;i++)
	{
		scanf("%s",&original[i][0]);
	}
	
		
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			char&	o = original[i][j];
			
			for(int row=i*K;row<i*K+K;row++)
			{
				for(int col=j*K;col<j*K+K;col++)
				{
					modified[row][col] = o;
				}
			}
		}
	}
	
	for(int i=0;i<M*K;i++)
	{
		modified[i][N*K] = '\0';
		puts(&modified[i][0]);
	}
	
	return	0;
}
