#include	<iostream>

using namespace	std;

#define	ORIGIN_SIZE		50
#define	ENLARGED_SIZE	(ORIGIN_SIZE*5)

char	origin[ORIGIN_SIZE][ORIGIN_SIZE+1];
char	scan[ENLARGED_SIZE][ENLARGED_SIZE+1];
int		R,C,ZR,ZC;

void	input(void)
{
	scanf("%d %d %d %d",&R,&C,&ZR,&ZC);
	
	for(int i=0;i<R;i++)
	{
		scanf("%s",&origin[i][0]);
	}
}

void	enlarge(int origin_row,int origin_col)
{
	int		scann_row,scan_col;
	char	c;
	
	c = origin[origin_row][origin_col];
	
	for(int row=origin_row*ZR,i=0;i<ZR;i++)
	{
		for(int col=origin_col*ZC,j=0;j<ZC;j++)
		{
			scan[row+i][col+j] = c;
		}
	}
}

int		main(void)
{
	input();
	
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			enlarge(i,j);
		}
	}
	
	for(int i=0;i<R*ZR;i++)
	{
		puts(&scan[i][0]);
	}
	
	return	0;
}
