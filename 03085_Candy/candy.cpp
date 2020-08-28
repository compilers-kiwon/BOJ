#include	<iostream>

using namespace	std;

#define	MAX_SIZE		(50+1)
#define	NUM_OF_COLORS	4

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int		N;
char	grid[MAX_SIZE][MAX_SIZE+1];
bool	changed_already[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE];

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

void	input(void)
{
	scanf("%d",&N);

	for(int row=1;row<=N;row++)
	{
		scanf("%s",&grid[row][1]);
	}
}

int		find_longest_consecutive_color_length(void)
{
	int	max_len;
	
	max_len = 0;
	
	for(int row=1;row<=N;row++)
	{
		int	cnt;
		
		cnt = 1;
		
		for(int col=2;col<=N;col++)
		{
			char&	prev_color = grid[row][col-1];
			char&	current_color = grid[row][col];
			
			if( prev_color == current_color )
			{
				cnt++;
			}
			else
			{
				max_len = max(max_len,cnt);
				cnt = 1;
			}
		}
		
		max_len = max(max_len,cnt);
	}
	
	for(int col=1;col<=N;col++)
	{
		int	cnt;
		
		cnt = 1;
		
		for(int row=2;row<=N;row++)
		{
			char&	prev_color = grid[row-1][col];
			char&	current_color = grid[row][col];
			
			if( prev_color == current_color )
			{
				cnt++;
			}
			else
			{
				max_len = max(max_len,cnt);
				cnt = 1;
			}
		}
		
		max_len = max(max_len,cnt);
	}
	
	return	max_len;
}

int		main(void)
{
	int	max_len;
	
	input();
	max_len = 0;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			for(int d=UP;d<=RIGHT;d++)
			{
				int	adj_row,adj_col;
				
				adj_row = row+adj[d].d_row;
				adj_col = col+adj[d].d_col;
				
				if( IN_RANGE(1,adj_row,N) && IN_RANGE(1,adj_col,N) )
				{
					if( changed_already[row][col][adj_row][adj_col] == false )
					{
						changed_already[row][col][adj_row][adj_col] = true;
						changed_already[adj_row][adj_col][row][col] = true;
						
						swap(grid[row][col],grid[adj_row][adj_col]);
						max_len = max(max_len,find_longest_consecutive_color_length());
						swap(grid[row][col],grid[adj_row][adj_col]);
					}
				}
			}
		}
	}
	
	printf("%d\n",max_len);
	
	return	0;	
}
