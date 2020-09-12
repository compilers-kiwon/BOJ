#include	<iostream>

using namespace	std;

#define	MAX_SIZE	1000

char	buf[MAX_SIZE][MAX_SIZE];

int	main(void)
{
	int	N,c1,c2,c3,c4,row;
	
	scanf("%d",&N);
	
	c1 = 1;
	c2 = N;
	c3 = c2+2*N-3+1;
	c4 = c3+N-1;
	row = 1;
	
	for(int col=c1;col<=c2;col++)
	{
		buf[row][col] = '*';
	}
	
	for(int col=c2+1;col<c3;col++)
	{
		buf[row][col] = ' ';
	}
	
	for(int col=c3;col<=c4;col++)
	{
		buf[row][col] = '*';
	}
	
	row++;
	c1++;c2++;c3--;c4--;
	
	for(;c2!=c3;row++)
	{
		for(int col=1;col<=c4;col++)
		{
			buf[row][col] = ' ';
		}
		buf[row][c1] = buf[row][c2] = buf[row][c3] = buf[row][c4] = '*';
		c1++;c2++;c3--;c4--;
	}
	
	for(int col=1;col<=c4;col++)
	{
		buf[row][col] = ' ';
	}
	
	buf[row][c1] = buf[row][c2] = buf[row][c4] = '*';
	
	row++;
	c1--;c2--;c3++;c4++;
	
	for(;c1!=1;row++)
	{
		for(int col=1;col<=c4;col++)
		{
			buf[row][col] = ' ';
		}
		buf[row][c1] = buf[row][c2] = buf[row][c3] = buf[row][c4] = '*';
		c1--;c2--;c3++;c4++;
	}
	
	for(int col=c1;col<=c2;col++)
	{
		buf[row][col] = '*';
	}
	
	for(int col=c2+1;col<c3;col++)
	{
		buf[row][col] = ' ';
	}
	
	for(int col=c3;col<=c4;col++)
	{
		buf[row][col] = '*';
	}
	
	for(int i=1;i<=row;i++)
	{
		puts(&buf[i][1]);
	}
	
	return	0;
}
