#include	<iostream>
#include	<vector>
#include	<string>
#include	<cmath>

using namespace	std;

#define	GRID_SIZE		4
#define	MAX_SIZE		(GRID_SIZE+1)
#define	MAX_OPERATION	5
#define	NONE			0

#define	UP		'U'
#define	DOWN	'D'
#define	LEFT	'L'
#define	RIGHT	'R'

#define	char2int(c)	((int)((c)-'0'))

#define	DIR_OFFSET	0
#define	TILE_OFFSET	1
#define	ROW_OFFSET	2
#define	COL_OFFSET	3
#define	MAX_OFFSET	4

int	merge_vert(int grid[][MAX_SIZE],int size,int head,int tail,int offset)
{
	int			ret = 0;
	vector<int>	block[MAX_SIZE];
	
	for(int col=1;col<=size;col++)
	{
		for(int row=head;row!=tail;row+=offset)
		{
			int&	current_block = grid[row][col];
			
			if( current_block != NONE )
			{
				vector<int>&	current_column = block[col];
				
				if( current_column.empty() )
				{
					if( row != head )
					{
						grid[head][col] = current_block;
						current_block = NONE;
					}
					
					current_column.push_back(head);
					continue;
				}
				
				int&	prev_row = current_column.back();
				int&	prev_block = grid[prev_row][col];
				
				if( current_block>0 && prev_block>0 && current_block==prev_block )
				{
					prev_block *= -2;
					current_block = NONE;
					ret += -prev_block;
				}
				else
				{
					if( prev_row+offset != row )
					{
						grid[prev_row+offset][col] = current_block;
						current_block = NONE;
					
						current_column.push_back(prev_row+offset);
					}
					else
					{
						current_column.push_back(row);
					}
				}
			}
		}
	}
	
	for(int row=1;row<=size;row++)
	{
		for(int col=1;col<=size;col++)
		{
			grid[row][col] = abs(grid[row][col]);
		}
	}
	
	return	ret;
}

int	merge_hori(int grid[][MAX_SIZE],int size,int head,int tail,int offset)
{
	int			ret = 0;
	vector<int>	block[MAX_SIZE];
	
	for(int row=1;row<=size;row++)
	{
		for(int col=head;col!=tail;col+=offset)
		{
			int&	current_block = grid[row][col];
			
			if( current_block != NONE )
			{
				vector<int>&	current_row = block[row];
				
				if( current_row.empty() )
				{
					if( col != head )
					{
						grid[row][head] = current_block;
						current_block = NONE;
					}
					
					current_row.push_back(head);
					continue;
				}
				
				int&	prev_col = current_row.back();
				int&	prev_block = grid[row][prev_col];
				
				if( current_block>0 && prev_block>0 && current_block==prev_block )
				{
					prev_block *= -2;
					current_block = NONE;
					ret += - prev_block;
				}
				else
				{
					if( prev_col+offset != col )
					{
						grid[row][prev_col+offset] = current_block;
						current_block = NONE;
					
						current_row.push_back(prev_col+offset);
					}
					else
					{
						current_row.push_back(col);
					}
				}
			}
		}
	}
	
	for(int row=1;row<=size;row++)
	{
		for(int col=1;col<=size;col++)
		{
			grid[row][col] = abs(grid[row][col]);
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int			S,grid[MAX_SIZE][MAX_SIZE];
	string		M;
	
	cin>>S>>M;
	
	for(int row=1;row<=GRID_SIZE;row++)
	{
		for(int col=1;col<=GRID_SIZE;col++)
		{
			cin>>grid[row][col];
		}
	}
	
	for(int i=0;i<M.length();i+=MAX_OFFSET)
	{
		switch(M[i+DIR_OFFSET])
		{
			case	UP:
				S += merge_vert(grid,GRID_SIZE,1,GRID_SIZE+1,1);
				break;
			case	DOWN:
				S += merge_vert(grid,GRID_SIZE,GRID_SIZE,0,-1);
				break;
			case	LEFT:
				S += merge_hori(grid,GRID_SIZE,1,GRID_SIZE+1,1);
				break;
			case	RIGHT:
				S += merge_hori(grid,GRID_SIZE,GRID_SIZE,0,-1);
				break;
			default:
				// do nothing
				break;
		}
		
		int	row,col,t;
		
		t = char2int(M[i+TILE_OFFSET]);
		row = char2int(M[i+ROW_OFFSET])+1;
		col = char2int(M[i+COL_OFFSET])+1;
		
		grid[row][col] = t;
	}
	
	cout<<S<<'\n';
	
	return	0;
}
