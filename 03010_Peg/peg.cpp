#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	2
#define	MAX_DIR		4
#define	EMPTY		'.'
#define	PAWN		'o'

#define	in_range(MIN,n,MAX)	((MIN)<=(n)&&(n)<(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

void	input(vector<string>& grid)
{
	for(;;)
	{
		string	str;
		
		getline(cin,str);
		
		if( str == "" )
		{
			break;
		}
		
		grid.push_back(str);
	}
}

int		check_pawn_pos(int row,int col,
					   int row_size,int col_size,
					   const vector<string>& grid)
{
	int		cnt;
	
	cnt = 0;
	
	for(int d=0;d<MAX_DIR;d++)
	{
		string	p;
		
		for(int i=1;i<=MAX_SIZE;i++)
		{
			int	adj_row,adj_col;
			
			adj_row = row+adj[d].d_row*i;
			adj_col = col+adj[d].d_col*i;
			
			if( !in_range(0,adj_row,row_size) || !in_range(0,adj_col,col_size) )
			{
				continue;
			}
			
			p.push_back(grid[adj_row][adj_col]);
		}
		
		if( p == "oo" )
		{
			cnt++;
		}
	}
	
	return	cnt;
}

int		count(const vector<string>& grid)
{
	int	row_size,col_size,ret;
	
	ret = 0;
	
	row_size = grid.size();
	col_size = grid[0].length();
	
	for(int row=0;row<row_size;row++)
	{
		for(int col=0;col<col_size;col++)
		{
			if( grid[row][col] == EMPTY )
			{
				ret += check_pawn_pos(row,col,row_size,col_size,grid);
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	vector<string>	grid;
	
	input(grid);
	cout<<count(grid)<<'\n';
	
	return	0;
}
