#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE			(100+1)
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>	Pos;	// first:row,second:col

void	bfs(char grid[][MAX_SIZE+1],
			const int& oil_row,const int& oil_col,
			const int& row_size,const int& col_size)
{
	queue<Pos>	oil;
	
	grid[oil_row][oil_col] = '*';
	oil.push(make_pair(oil_row,oil_col));
	
	for(;!oil.empty();)
	{
		int	current_row,current_col;
		
		current_row = oil.front().first;
		current_col = oil.front().second;
		
		oil.pop();
		
		for(int d_row=-1;d_row<=1;d_row++)
		{
			for(int d_col=-1;d_col<=1;d_col++)
			{
				int	adj_row,adj_col;
				
				adj_row = current_row+d_row;
				adj_col = current_col+d_col;
				
				if( !IN_RANGE(1,adj_row,row_size) || !IN_RANGE(1,adj_col,col_size) )
				{
					continue;
				}
				
				if( grid[adj_row][adj_col] == '@' )
				{
					grid[adj_row][adj_col] = '*';
					oil.push(make_pair(adj_row,adj_col));
				}
			}
		}
	}
}

bool	input(int& row_size,int& col_size,char grid[][MAX_SIZE+1])
{
	cin>>row_size>>col_size;
	
	if( row_size==0 && col_size==0 )
	{
		return	false;
	}
	
	for(int row=1;row<=row_size;row++)
	{
		cin>>&grid[row][1];
	}
	
	return	true;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int		m,n,cnt;
		char	grid[MAX_SIZE][MAX_SIZE+1];
		
		if( input(m,n,grid) == false )
		{
			break;
		}
		
		cnt = 0;
		
		for(int row=1;row<=m;row++)
		{
			for(int col=1;col<=n;col++)
			{
				if( grid[row][col] == '@' )
				{
					cnt++;
					bfs(grid,row,col,m,n);
				}
			}
		}
		
		cout<<cnt<<'\n';
	}
	
	return	0;
}
