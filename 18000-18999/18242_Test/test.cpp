#include	<iostream>
#include	<cstring>

#define	MAX_SIZE	100

int		N,M,top,bottom,left,right;
char	grid[MAX_SIZE+1][MAX_SIZE+2];

void	input(void)
{
	scanf("%d %d",&N,&M);
	
	for(int row=1;row<=N;row++)
	{
		scanf("%s",&grid[row][1]);
	}
}

void	get_pos(void)
{
	bool	found;
	
	found = false;
	
	for(int row=1;row<=N&&found!=true;row++)
	{
		for(int col=1;col<=M&&found!=true;col++)
		{
			if( grid[row][col] == '#' )
			{
				top = row;
				left = col;
				found = true;
			}
		}
	}
	
	found = false;
	
	for(int row=N;row>=1&&found!=true;row--)
	{
		for(int col=M;col>=1&&found!=true;col--)
		{
			if( grid[row][col] == '#' )
			{
				bottom = row;
				right = col;
				found = true;
			}
		}
	}
}

void	check_query(char* result)
{
	for(int row=top;row<=bottom;row++)
	{
		if( grid[row][left] == '.' )
		{
			strcpy(result,"LEFT");
			return;
		}
		
		if( grid[row][right] == '.' )
		{
			strcpy(result,"RIGHT");
			return;
		}
	}
	
	for(int col=left;col<=right;col++)
	{
		if( grid[top][col] == '.' )
		{
			strcpy(result,"UP");
			return;
		}
		
		if( grid[bottom][col] == '.' )
		{
			strcpy(result,"DOWN");
			return;
		}
	}
}

int		main(void)
{
	char	str[MAX_SIZE];
	
	input();
	get_pos();
	
	std::fill_n(str,MAX_SIZE,0);
	
	check_query(str);
	puts(str);
	
	return	0;
}
