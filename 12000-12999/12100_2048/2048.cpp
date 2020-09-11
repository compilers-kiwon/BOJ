#include	<iostream>
#include	<vector>
#include	<cstring>

using namespace	std;

#define	MAX_SIZE		(20+1)
#define	MAX_OPERATION	5
#define	NONE			0

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

typedef	pair<int,int>	Pos;	// first:row,second:col

void	merge_vert(int grid[][MAX_SIZE],int size,int head,int tail,int offset)
{
	Pos	merged[MAX_SIZE*MAX_SIZE/2];
	int	merged_ptr;
	
	merged_ptr = 0;
	
	for(int col=1;col<=size;col++)
	{
		int		block[MAX_SIZE],ptr;
		
		ptr = 0;
		
		for(int row=head;row!=tail;row+=offset)
		{
			int&	current_block = grid[row][col];
			
			if( current_block != NONE )
			{
				if( ptr == 0 )
				{
					if( row != head )
					{
						grid[head][col] = current_block;
						current_block = NONE;
					}
					
					block[++ptr] = head;
					continue;
				}
				
				int&	prev_row = block[ptr];
				int&	prev_block = grid[prev_row][col];
				
				if( prev_block>0 && current_block==prev_block )
				{
					prev_block *= -2;
					current_block = NONE;
					
					merged[++merged_ptr] = make_pair(prev_row,col);
				}
				else
				{
					if( prev_row+offset != row )
					{
						grid[prev_row+offset][col] = current_block;
						current_block = NONE;
					
						block[++ptr] = prev_row+offset;
					}
					else
					{
						block[++ptr] = row;
					}
				}
			}
		}
	}
	
	for(int i=1;i<=merged_ptr;i++)
	{
		int&	row = merged[i].first;
		int&	col = merged[i].second;
		
		grid[row][col] *= -1;
	}
}

void	merge_hori(int grid[][MAX_SIZE],int size,int head,int tail,int offset)
{
	Pos	merged[MAX_SIZE*MAX_SIZE/2];
	int	merged_ptr;
	
	merged_ptr = 0;
	
	for(int row=1;row<=size;row++)
	{
		int		block[MAX_SIZE],ptr;
		
		ptr = 0;
		
		for(int col=head;col!=tail;col+=offset)
		{
			int&	current_block = grid[row][col];
			
			if( current_block != NONE )
			{
				if( ptr == 0 )
				{
					if( col != head )
					{
						grid[row][head] = current_block;
						current_block = NONE;
					}
					
					block[++ptr] = head;
					continue;
				}
				
				int&	prev_col = block[ptr];
				int&	prev_block = grid[row][prev_col];
				
				if( prev_block>0 && current_block==prev_block )
				{
					prev_block *= -2;
					current_block = NONE;
					
					merged[++merged_ptr] = make_pair(row,prev_col);
				}
				else
				{
					if( prev_col+offset != col )
					{
						grid[row][prev_col+offset] = current_block;
						current_block = NONE;
					
						block[++ptr] = prev_col+offset;
					}
					else
					{
						block[++ptr] = col;
					}
				}
			}
		}
	}
	
	for(int i=1;i<=merged_ptr;i++)
	{
		int&	row = merged[i].first;
		int&	col = merged[i].second;
		
		grid[row][col] *= -1;
	}
}

void	copy_grid(int src[][MAX_SIZE],int dst[][MAX_SIZE],int size)
{
	for(int row=1;row<=size;row++)
	{
		memcpy(&dst[row][1],&src[row][1],sizeof(int)*size);
	}
}

int		count_max_block(int grid[][MAX_SIZE],int size)
{
	int	ret;
	
	ret = 0;
	
	for(int row=1;row<=size;row++)
	{
		for(int col=1;col<=size;col++)
		{
			ret = max(ret,grid[row][col]);
		}
	}
	
	return	ret;
}

void	find_max_block(int num_of_operation,int& max_block,int grid[][MAX_SIZE],int size)
{
	int	tmp;
	
	tmp = count_max_block(grid,size);
	
	if( num_of_operation==MAX_OPERATION || (tmp<<(MAX_OPERATION-num_of_operation))<=max_block )
	{
		if( num_of_operation == MAX_OPERATION )
		{
			max_block = max(max_block,tmp);
		}
		
		return;
	}
	
	for(int i=UP;i<=RIGHT;i++)
	{
		int	tmp[MAX_SIZE][MAX_SIZE];
		
		copy_grid(grid,tmp,size);
		
		switch(i)
		{
			case	UP:
				merge_vert(tmp,size,1,size+1,1);
				break;
			case	DOWN:
				merge_vert(tmp,size,size,0,-1);
				break;
			case	LEFT:
				merge_hori(tmp,size,1,size+1,1);
				break;
			case	RIGHT:
				merge_hori(tmp,size,size,0,-1);
				break;
			default:
				// do nothing
				break;
		}
		
		find_max_block(num_of_operation+1,max_block,tmp,size);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int			N,max_block,grid[MAX_SIZE][MAX_SIZE];
	vector<int>	operation;
	
	cin>>N;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			cin>>grid[row][col];
		}
	}
	
	max_block = 0;
	find_max_block(0,max_block,grid,N);
	
	cout<<max_block<<'\n';
	
	return	0;
}
