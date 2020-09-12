#include	<iostream>

using namespace	std;

#define	MAX_SIZE	26
#define	CHAR2INT(C)	((int)((C)-'A'))

#define	get_prev_index(i,size)	(((i)-1+(size))%(size))
#define	get_next_index(i,size)	(((i)+1+(size))%(size))

int	main(void)
{
	for(int N;scanf("%d",&N)==1;)
	{
		char	stands[MAX_SIZE][MAX_SIZE+1];
		int		row_color[MAX_SIZE],col_color[MAX_SIZE];
		
		for(int	row=0;row<N;row++)
		{
			scanf("%s",&stands[row][0]);
		}
		
		for(int row=0;row<N;row++)
		{
			row_color[row] = 0;
			
			for(int col=0;col<N;col++)
			{
				row_color[row] |= 1<<CHAR2INT(stands[row][col]);
			}
		}
		
		for(int col=0;col<N;col++)
		{
			col_color[col] = 0;
			
			for(int row=0;row<N;row++)
			{
				col_color[col] |= 1<<CHAR2INT(stands[row][col]);
			}
		}
		
		int	different_row,different_col;
		
		for(int row=0;row<N;row++)
		{
			if( row_color[row]!=row_color[get_prev_index(row,N)] 
				&& row_color[row]!=row_color[get_next_index(row,N)] )
			{
				different_row = row;
				break;
			}
		}
		
		for(int col=0;col<N;col++)
		{
			if( col_color[col]!=col_color[get_prev_index(col,N)] 
				&& col_color[col]!=col_color[get_next_index(col,N)] )
			{
				different_col = col;
				break;
			}
		}
		
		int	missed_color;
		
		missed_color = row_color[get_prev_index(different_row,N)];
		
		for(int col=0;col<N;col++)
		{
			if( col == different_col )
			{
				continue;
			}
			
			missed_color ^= 1<<CHAR2INT(stands[different_row][col]);
		}
		
		for(char c='A';c<='Z';c++)
		{
			if( 1<<CHAR2INT(c) == missed_color )
			{
				printf("%d %d %c\n",different_row+1,different_col+1,c);
				break;
			}
		}
	}
	
	return	0;
}
