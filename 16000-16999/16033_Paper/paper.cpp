#include	<iostream>

using namespace	std;

#define	MAX_SIZE	32
#define	BUF_SIZE	2

#define	VERTICAL	1
#define	HORIZONTAL	2

#define	get_next_buf(current)	(((current)+1)%BUF_SIZE)

void	init_grid(int grid[][MAX_SIZE][MAX_SIZE],int buf_ptr)
{
	for(int row=0;row<MAX_SIZE;row++)
	{
		fill(&grid[buf_ptr][row][0],&grid[buf_ptr][row][MAX_SIZE],0);
	}
}

int		vertical_folding(int grid[][MAX_SIZE][MAX_SIZE],int current,int offset)
{
	int	next;
	
	next = get_next_buf(current);
	init_grid(grid,next);
	
	for(int row=0;row<MAX_SIZE;row++)
	{
		for(int src_col=offset-1,dst_col=0;src_col>=0;src_col--,dst_col++)
		{
			grid[next][row][dst_col] += grid[current][row][src_col];
		}
		
		for(int src_col=offset,dst_col=0;src_col<MAX_SIZE;src_col++,dst_col++)
		{
			grid[next][row][dst_col] += grid[current][row][src_col];
		}
	}
	
	return	next;
}	

int		horizontal_folding(int grid[][MAX_SIZE][MAX_SIZE],int current,int offset)
{
	int	next;
	
	next = get_next_buf(current);
	init_grid(grid,next);

	for(int col=0;col<MAX_SIZE;col++)
	{
		for(int src_row=offset-1,dst_row=0;src_row>=0;src_row--,dst_row++)
		{
			grid[next][dst_row][col] += grid[current][src_row][col];
		}
		
		for(int src_row=offset,dst_row=0;src_row<MAX_SIZE;src_row++,dst_row++)
		{
			grid[next][dst_row][col] += grid[current][src_row][col];
		}
	}
	
	return	next;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	n,m,t,p,ptr;
		int	grid[BUF_SIZE][MAX_SIZE][MAX_SIZE];
		
		cin>>n>>m>>t>>p;
		
		if( n==0 && m==0 && t==0 && p==0 )
		{
			break;
		}
		
		ptr = 0;
		init_grid(grid,ptr);
		
		for(int row=0;row<m;row++)
		{
			for(int col=0;col<n;col++)
			{
				grid[ptr][row][col] = 1;
			}
		}
		
		for(int i=1;i<=t;i++)
		{
			int	d,c;
			
			cin>>d>>c;
			
			if( d == VERTICAL )
			{
				ptr = vertical_folding(grid,ptr,c);
			}
			else
			{
				ptr = horizontal_folding(grid,ptr,c);
			}
		}
		
		for(int i=1;i<=p;i++)
		{
			int	x,y;
			
			cin>>x>>y;
			cout<<grid[ptr][y][x]<<'\n';
		}
	}
	
	return	0;
}
