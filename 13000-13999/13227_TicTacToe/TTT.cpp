#include	<iostream>

using namespace	std;

#define	ROW_SIZE	3
#define	COL_SIZE	3

#define	LEFT_TO_RIGHT	0
#define	RIGHT_TO_LEFT	1

char	grid[ROW_SIZE+1][COL_SIZE+1+1];

bool	equal_symbol_in_row(int row)
{
	bool	result;
	char&	h = grid[row][1];
	
	result = true;
	
	for(int col=2;col<=COL_SIZE;col++)
	{
		if( h != grid[row][col] )
		{
			result = false;
			break;
		}
	}
	
	return	result;
}

bool	equal_symbol_in_col(int col)
{
	bool	result;
	char&	h = grid[1][col];
	
	result = true;
	
	for(int row=2;row<=ROW_SIZE;row++)
	{
		if( h != grid[row][col] )
		{
			result = false;
			break;
		}
	}
	
	return	result;
}

bool	equal_symbol_in_diagonal(int direction)
{
	int		s_col,offset;
	
	if( direction == LEFT_TO_RIGHT )
	{
		s_col = 1;
		offset = 1;
	}
	else
	{
		s_col = COL_SIZE;
		offset = -1;
	}
	
	bool	result;
	char&	h = grid[1][s_col];
	
	result = true;
	
	for(int col=s_col+offset,row=2;row<=ROW_SIZE;col+=offset,row++)
	{
		if( h != grid[row][col] )
		{
			result = false;
			break;
		}
	}
	
	return	result;
}

int		main(void)
{
	for(int row=1;row<=ROW_SIZE;row++)
	{
		scanf("%s",&grid[row][1]);
	}
	
	int	num_of_O_wins,num_of_X_wins;
	
	num_of_O_wins = num_of_X_wins = 0;
	
	for(int col=1;col<=COL_SIZE;col++)
	{
		if( grid[1][col]=='O' && equal_symbol_in_col(col)==true )
		{
			num_of_O_wins++;
		}
		
		if( grid[1][col]=='X' && equal_symbol_in_col(col)==true )
		{
			num_of_X_wins++;
		}
	}
	
	for(int row=1;row<=ROW_SIZE;row++)
	{
		if( grid[row][1]=='O' && equal_symbol_in_row(row)==true )
		{
			num_of_O_wins++;
		}
		
		if( grid[row][1]=='X' && equal_symbol_in_row(row)==true )
		{
			num_of_X_wins++;
		}
	}
	
	if( grid[1][1] != '.' )
	{
		if( equal_symbol_in_diagonal(LEFT_TO_RIGHT) == true )
		{
			if( grid[1][1] == 'X' )
			{
				num_of_X_wins++;
			}
			else
			{
				num_of_O_wins++;
			}
		}
	}
	
	if( grid[1][COL_SIZE] != '.' )
	{
		if( equal_symbol_in_diagonal(RIGHT_TO_LEFT) == true )
		{
			if( grid[1][COL_SIZE] == 'X' )
			{
				num_of_X_wins++;
			}
			else
			{
				num_of_O_wins++;
			}
		}
	}
	
	if( (num_of_O_wins==0 && num_of_X_wins!=0) || (num_of_O_wins!=0 && num_of_X_wins==0) )
	{
		puts("YES");
	}
	else
	{
		puts("NO");
	}
	
	return	0;
}
