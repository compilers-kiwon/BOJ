#include	<iostream>
#include	<cmath>

using namespace	std;

#define	MAX_SIZE	1024

int		N;
char	output_buffer[MAX_SIZE][MAX_SIZE+1];

void	print_star(int row,int col,int len,bool end_flag)
{
	if( len == 4 )
	{
		output_buffer[row][col] = output_buffer[row][col+1]
		= output_buffer[row][col+2] = output_buffer[row][col+3] = '*';
		output_buffer[row+1][col] = output_buffer[row+1][col+2] = '*';
		output_buffer[row+2][col] = output_buffer[row+2][col+1] = '*';
		output_buffer[row+3][col] = '*';
		
		if( end_flag == true )
		{
			output_buffer[row][col+4] =	output_buffer[row+1][col+3] =
			output_buffer[row+2][col+2] = output_buffer[row+3][col+1] = '\0';
		}
	}
	else
	{
		print_star(row,col,len/2,false);
		print_star(row,col+len/2,len/2,end_flag);
		print_star(row+len/2,col,len/2,end_flag);
	}
}
int		main(void)
{
	scanf("%d",&N);
	
	if( N == 0 )
	{
		puts("*");
		return	0;
	}
	
	if( N == 1 )
	{
		puts("**");
		puts("*");
		return	0;
	}
	
	int	size,current_row,current_col;
	
	size = pow(2,N);
	
	for(int row=0;row<size;row++)
	{
		for(int col=size-row-1;col>=0;col--)
		{
			output_buffer[row][col] = ' ';
		}
	}
	
	print_star(0,0,size,true);
	
	for(int i=0;i<size;i++)
	{
		puts(&output_buffer[i][0]);
	}
	
	return	0;
}
