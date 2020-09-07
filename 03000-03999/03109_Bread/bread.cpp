#include	<iostream>

using namespace	std;

#define	MAX_ROW	(10000+1)
#define	MAX_COL	(500+1)

#define	UP		-1
#define	DOWN	1

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	EMPTY	'.'
#define	WALL	'x'

int		R,C;
char	grid[MAX_ROW][MAX_COL+1];

int		place_pipe(int current_row,int current_col)
{
	if( current_col == C )
	{
		return	1;
	}
	
	for(int d=UP;d<=DOWN;d++)
	{
		int	adj_row,adj_col;
		
		adj_row = current_row+d;
		adj_col = current_col+1;
		
		if( IN_RANGE(1,adj_row,R) && grid[adj_row][adj_col]==EMPTY )
		{
			grid[adj_row][adj_col] = WALL;
			
			if( place_pipe(adj_row,adj_col) == 1 )
			{
				return	1;
			}
		}
	}
	
	return	0;
}	

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>R>>C;
	
	for(int row=1;row<=R;row++)
	{
		cin>>&grid[row][1];
	}
	
	int	cnt;
	
	cnt = 0;
	
	for(int row=1;row<=R;row++)
	{
		cnt += place_pipe(row,1);
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
