#include	<iostream>

using namespace	std;

#define	MAX_SIZE	9
#define	char2int(c)	((int)((c)-'0'))

bool	row_used_table[MAX_SIZE+1][MAX_SIZE+1],col_used_table[MAX_SIZE+1][MAX_SIZE+1];
bool	part_used_table[MAX_SIZE/3+1][MAX_SIZE/3+1][MAX_SIZE+1];
char	sdoku[MAX_SIZE+1][MAX_SIZE+2];

void	init_table(void)
{
	for(int i=1;i<=MAX_SIZE;i++)
	{
		scanf("%s",&sdoku[i][1]);
	}
	
	for(int row=1;row<=MAX_SIZE;row++)
	{
		for(int col=1;col<=MAX_SIZE;col++)
		{
			if( sdoku[row][col] != '0' )
			{
				int	n;
				
				n = char2int(sdoku[row][col]);
				row_used_table[row][n] = col_used_table[col][n] = true;
				part_used_table[(row-1)/3+1][(col-1)/3+1][n] = true;
			}
		}
	}
}

bool	fill_sdoku(int index)
{
	if( index == MAX_SIZE*MAX_SIZE )
	{
		return	true;
	}
	
	int	row,col;
	
	row = index/MAX_SIZE+1;
	col = index%MAX_SIZE+1;
	
	if( sdoku[row][col] == '0' )
	{
		for(char c='1';c<='9';c++)
		{
			int	n;
			
			n = char2int(c);
			
			if( row_used_table[row][n] == false && col_used_table[col][n] == false 
				&& part_used_table[(row-1)/3+1][(col-1)/3+1][n] == false )
			{
				row_used_table[row][n] = col_used_table[col][n] = true;
				part_used_table[(row-1)/3+1][(col-1)/3+1][n] = true;
				sdoku[row][col] = c;
				
				if( fill_sdoku(index+1) == true )
				{
					return	true;
				}
				
				sdoku[row][col] = '0';
				part_used_table[(row-1)/3+1][(col-1)/3+1][n] = false;
				row_used_table[row][n] = col_used_table[col][n] = false;
			}
		}
	}
	else
	{
		return	fill_sdoku(index+1);
	}
	
	return	false;
}

int		main(void)
{
	init_table();
	fill_sdoku(0);
	
	for(int i=1;i<=MAX_SIZE;i++)
	{
		puts(&sdoku[i][1]);
	}
	
	return	0;
}
