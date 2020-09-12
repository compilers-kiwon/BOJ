#include	<iostream>

using namespace	std;

#define	MAX_SIZE		(10+1)
#define	NEXT_CHAR(c)	(((c)=='.')?'*':'.')

int	main(void)
{
	int		N,M;
	char	outbuf[MAX_SIZE][MAX_SIZE+1];
		
	cin>>N>>M;
	outbuf[0][1] = '.';
		
	for(int row=1;row<=N;row++)
	{
		outbuf[row][1] = NEXT_CHAR(outbuf[row-1][1]);
		
		for(int col=2;col<=M;col++)
		{
			outbuf[row][col] = NEXT_CHAR(outbuf[row][col-1]);
		}
		outbuf[row][M+1] = '\0';
		
		puts(&outbuf[row][1]);
	}
	
	return	0;
}
