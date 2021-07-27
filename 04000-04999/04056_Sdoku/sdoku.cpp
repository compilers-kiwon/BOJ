#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	9
#define	EMPTY		0

typedef	pair<int,int>	Pos;	// first:row,second:col

int		grid[MAX_SIZE+1][MAX_SIZE+1];

bool	is_valid(void)
{
	bool	visited[MAX_SIZE+1];

	// 3x3
	for(int s_row=1;s_row<=MAX_SIZE;s_row+=3)
	{
		for(int s_col=1;s_col<=MAX_SIZE;s_col+=3)
		{
			fill(&visited[1],&visited[MAX_SIZE+1],false);

			for(int row=s_row;row<s_row+3;row++)
			{
				for(int col=s_col;col<s_col+3;col++)
				{
					int&	n = grid[row][col];

					if( n == EMPTY )
					{
						continue;
					}

					if( visited[n] == true )
					{
						return	false;
					}

					visited[n] = true;
				}
			}
		}
	}

	// Virt
	for(int col=1;col<=MAX_SIZE;col++)
	{
		fill(&visited[1],&visited[MAX_SIZE+1],false);

		for(int row=1;row<=MAX_SIZE;row++)
		{
			int&	n = grid[row][col];

			if( n == EMPTY )
			{
				continue;
			}

			if( visited[n] == true )
			{
				return	false;
			}

			visited[n] = true;
		}
	}

	// Hori
	for(int row=1;row<=MAX_SIZE;row++)
	{
		fill(&visited[1],&visited[MAX_SIZE+1],false);

		for(int col=1;col<=MAX_SIZE;col++)
		{
			int&	n = grid[row][col];

			if( n == EMPTY )
			{
				continue;
			}

			if( visited[n] == true )
			{
				return	false;
			}

			visited[n] = true;
		}
	}

	return	true;
}

bool	input(vector<Pos>& empty)
{
	for(int row=1;row<=MAX_SIZE;row++)
	{
		scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d",&grid[row][1],&grid[row][2],&grid[row][3],
			  &grid[row][4],&grid[row][5],&grid[row][6],&grid[row][7],&grid[row][8],&grid[row][9]);
	}
	
	if( !is_valid() )
	{
		return	false;
	}

	for(int row=1;row<=MAX_SIZE;row++)
	{
		for(int col=1;col<=MAX_SIZE;col++)
		{
			if( grid[row][col] == EMPTY )
			{
				empty.push_back(make_pair(row,col));
			}
		}
	}

	return	true;
}

bool	dfs(vector<Pos>& empty,int ptr)
{
	if( ptr == empty.size() )
	{
		return	is_valid();
	}
	
	int&	row = empty[ptr].first;
	int&	col = empty[ptr].second;
	
	for(int i=1;i<=MAX_SIZE;i++)
	{
		grid[row][col] = i;

		if( dfs(empty,ptr+1) == true )
		{
			return	true;
		}
	}
	
	return	false;
}

int		main(void)
{
	int	n;
	
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		vector<Pos>	empty;
				
		if( i != 1 )
		{
			puts("");
		}

		if( input(empty)==false || dfs(empty,0)==false )
		{
			puts("Could not complete this grid.");
			continue;
		}
		else
		{
			for(int row=1;row<=MAX_SIZE;row++)
			{
				for(int col=1;col<=MAX_SIZE;col++)
				{
					printf("%d",grid[row][col]);
				}
				puts("");
			}
		}
	}
	
	return	0;
}