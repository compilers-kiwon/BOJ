#include	<iostream>

using namespace	std;

#define	MAX_ROW_SIZE	(50000+1)
#define	MAX_COL_SIZE	(10+1)

#define	APPLE		'a'
#define	EMPTY		'.'
#define	OBSTACLE	'#'

#define	NONE	0

int			R,C;
char		grid[MAX_ROW_SIZE][MAX_COL_SIZE+1];

void	input(void)
{
	scanf("%d %d",&R,&C);
	
	for(int row=1;row<=R;row++)
	{
		scanf("%s",&grid[row][1]);
	}
}

void	move_apple(int col)
{
	int	empty_row,row;
	
	for(row=R,empty_row=0;row>=1;row--)
	{
		char&	c = grid[row][col];
		
		switch(c)
		{
			case	APPLE:
				if( empty_row != NONE )
				{
					c = EMPTY;
					grid[empty_row][col] = APPLE;
					
					if( (empty_row-1)>=1 && grid[empty_row-1][col]==EMPTY )
					{
						empty_row = empty_row-1;
					}
					else
					{
						empty_row = NONE;
					}
				}
				break;
			case	OBSTACLE:
				empty_row = NONE;
				break;
			case	EMPTY:
				if( empty_row == NONE )
				{
					empty_row = row;
				}
				break;
			default:
				// do nothing
				break;
		}
	}
}

int		main(void)
{
	input();
	
	for(int col=1;col<=C;col++)
	{
		move_apple(col);
	}
	
	for(int row=1;row<=R;row++)
	{
		puts(&grid[row][1]);
	}
	
	return	0;
}
