#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	20
#define	MAX_LEN		10

#define	RED				'#'
#define	WHITE			'.'
#define	NEXT_COLOR(c)	(((c)=='#')?'.':'#')

int	main(void)
{
	int		M,N,U,L,R,D;
	char	puzzle[MAX_SIZE][MAX_SIZE+1],first_color_in_row;
	
	cin>>M>>N>>U>>L>>R>>D;
	
	first_color_in_row = '#';
	
	for(int row=0;row<M+U+D;row++)
	{
		char	color;
		
		color = first_color_in_row;
		first_color_in_row = NEXT_COLOR(first_color_in_row);
		
		for(int col=0;col<N+L+R;col++)
		{
			puzzle[row][col] = color;
			color = NEXT_COLOR(color);
		}
		puzzle[row][N+L+R] = '\0';
	}
	
	for(int row=U,i=0;i<M;i++,row++)
	{
		char	buf[MAX_LEN+1];
		
		scanf("%s",buf);
		
		for(int col=L,j=0;j<N;j++,col++)
		{
			puzzle[row][col] = buf[j];
		}
	}
	
	for(int i=0;i<M+U+D;i++)
	{
		puts(&puzzle[i][0]);
	}
	
	return	0;
}
