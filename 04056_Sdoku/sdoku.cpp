#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	9
#define	EMPTY		0

typedef	pair<int,int>	Pos;	// first:row,second:col

int		grid[MAX_SIZE+1][MAX_SIZE+1];

void	input(vector<Pos>& empty,vector<int> candidate[][MAX_SIZE+1])
{
	for(int row=1;row<=MAX_SIZE;row++)
	{
		scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d",&grid[row][1],&grid[row][2],&grid[row][3],
			  &grid[row][4],&grid[row][5],&grid[row][6],&grid[row][7],&grid[row][8],&grid[row][9]);
	}
	
	for(int row=1;row<=MAX_SIZE;row++)
	{
		for(int col=1;col<=MAX_SIZE;col++)
		{
			if( grid[row][col] == EMPTY )
			{
				empty.push_back(make_pair(row,col));
				
				vector<bool>	used_in_row(MAX_SIZE+1,false),used_in_col(MAX_SIZE+1,false);
				
				for(int i=1;i<=MAX_SIZE;i++)
				{
					used_in_col[grid[i][col]] = used_in_row[grid[row][i]] = true;
				}
				
				for(int i=1;i<=MAX_SIZE;i++)
				{
					if( used_in_col[i]==false && used_in_row[i]==false )
					{
						candidate[row][col].push_back(i);
					}
				}
			}
		}
	}
}

bool	dfs(vector<Pos>& empty,int ptr,vector<int> candidate[][MAX_SIZE+1])
{
	if( ptr == empty.size() )
	{
		bool	flag;
		
		flag = true;
		
		for(int i=0;i<empty.size();i++)
		{
			int&			row = empty[i].first;
			int&			col = empty[i].second;
			vector<bool>	used_in_row(MAX_SIZE+1,false);
			vector<bool>	used_in_col(MAX_SIZE+1,false);
			
			for(int j=1;j<=MAX_SIZE;j++)
			{
				if( used_in_col[grid[j][col]]==true || used_in_row[grid[row][j]]==true )
				{
					return	false;
				}
				
				used_in_col[grid[j][col]] = used_in_row[grid[row][j]] = true;
			}
		}
		
		return	true;
	}
	
	int&			row = empty[ptr].first;
	int&			col = empty[ptr].second;
	vector<int>&	c = candidate[row][col];
	
	for(int i=0;i<c.size();i++)
	{
		grid[row][col] = c[i];
		
		if( dfs(empty,ptr+1,candidate) == true )
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
		vector<int>	candidate[MAX_SIZE+1][MAX_SIZE+1];
		
		input(empty,candidate);
		
		if( i != 1 )
		{
			puts("");
		}
		
		if( dfs(empty,0,candidate) == true )
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
		else
		{
			puts("Could not complete this grid.");
		}
	}
	
	return	0;
}
