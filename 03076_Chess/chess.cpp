#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(10*10+1)

const char	pattern[2] = {'X','.'};
char		board[MAX_SIZE][MAX_SIZE+1];

void	print(int s_row,int s_col,char p,
			  int row_size,int col_size)
{
	for(int row=s_row;row<s_row+row_size;row++)
	{
		for(int col=s_col;col<s_col+col_size;col++)
		{
			board[row][col] = p;
		}
	}
}

int		main(void)
{
	int		R,C,A,B;
	int		num_of_rows,num_of_cols;
	
	cin>>R>>C>>A>>B;
	
	for(int row=0;row<R;row++)
	{
		int	ptr;
		
		ptr = row%2;
		
		for(int col=0;col<C;col++)
		{
			print(row*A,col*B,pattern[ptr],A,B);
			ptr = (ptr+1)%2;	
		}	
	}
	
	for(int row=0;row<R*A;row++)
	{
		cout<<&board[row][0]<<'\n';
	}
	
	return	0;
}
