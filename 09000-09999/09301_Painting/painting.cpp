#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	100

char	grid[MAX_SIZE+1][MAX_SIZE+2];

void	init_grid(int grid_size)
{
	for(int row=1;row<=grid_size;row++)
	{
		for(int col=1;col<=grid_size;col++)
		{
			grid[row][col] = '.';
		}
		grid[row][grid_size+1] = '\0';
	}
}

void	filled(int X,int Y,int W,int H,char c)
{
	for(int row=Y;row<Y+H;row++)
	{
		for(int col=X;col<X+W;col++)
		{
			grid[row][col] = c;
		}
	}
}

void	empty(int X,int Y,int W,int H,char c)
{
	for(int col=X;col<X+W;col++)
	{
		grid[Y][col] = grid[Y+H-1][col] = c;
	}
	
	for(int row=Y+1;row<Y+H-1;row++)
	{
		grid[row][X] = grid[row][X+W-1] = c;
	}
}

void	print_grid(int grid_size)
{
	for(int row=grid_size;row>=1;row--)
	{
		puts(&grid[row][1]);
	}
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int	N,M;
		
		cin>>N>>M;
		
		init_grid(N);
		
		for(int i=1;i<=M;i++)
		{
			string	rect;
			int		X,Y,W,H;
			char	C;
			
			cin>>rect>>X>>Y>>W>>H>>C;
			
			if( rect == "Filled" )
			{
				filled(X,Y,W,H,C);
			}
			else
			{
				empty(X,Y,W,H,C);
			}
		}
		
		cout<<"Case "<<t<<":\n";
		print_grid(N);
	}
	
	return	0;
}
