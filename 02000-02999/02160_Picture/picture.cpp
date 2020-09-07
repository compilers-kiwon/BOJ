#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_PICTURES	(50+1)

#define	MAX_ROW				5
#define	MAX_COL				7

char	picture[MAX_NUM_OF_PICTURES][MAX_ROW][MAX_COL+1];

int	compare_picture(int p1,int p2)
{
	int	cnt,i,j;
	
	for(cnt=0,i=0;i<MAX_ROW;i++)
	{
		for(j=0;j<MAX_COL;j++)
		{
			if( picture[p1][i][j] != picture[p2][i][j] )
			{
				++cnt;
			}
		}
	}
	return	cnt;
}

int	main(void)
{
	int	N,p1,p2,min_diff;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<MAX_ROW;j++)
		{
			scanf("%s",&picture[i][j][0]);
		}
	}
	
	min_diff = 0x7FFFFFFF;
	
	for(int i=1;i<N;i++)
	{
		for(int j=i+1;j<=N;j++)
		{
			int	tmp_diff;
			
			tmp_diff = compare_picture(i,j);
			
			if( tmp_diff < min_diff )
			{
				min_diff = tmp_diff;
				p1 = i;
				p2 = j;
			}
		}
	}
	printf("%d %d\n",p1,p2);
	
	return	0;
}
