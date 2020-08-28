#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(30+1)
#define	MAX_DIR		8
#define	OFFSET		(MAX_DIR/2)

#define	in_range(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};

int		N;
char	grid[MAX_SIZE+1][MAX_SIZE+1];

void	input(void)
{
	cin>>N;
	
	for(int row=1;row<=N;row++)
	{
		cin>>&grid[row][1];
	}
}

bool	find_triple(const int& row,const int& col)
{
	char&	c = grid[row][col];
	
	for(int i=0;i<OFFSET;i++)
	{
		int	adj_row_1,adj_col_1;
		int	adj_row_2,adj_col_2;
		
		adj_row_1 = row+adj[i].d_row;
		adj_col_1 = col+adj[i].d_col;
		
		adj_row_2 = row+adj[i+OFFSET].d_row;
		adj_col_2 = col+adj[i+OFFSET].d_col;
		
		if( grid[adj_row_1][adj_col_1]==c && grid[adj_row_2][adj_col_2]==c )
		{
			return	true;
		}
	}
	
	return	false;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			if( grid[row][col]!='.' && find_triple(row,col)==true )
			{
				cout<<grid[row][col]<<'\n';
				return	0;
			}
		}
	}
	
	cout<<"ongoing\n";
	
	return	0;
}
