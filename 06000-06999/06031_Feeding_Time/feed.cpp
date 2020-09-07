#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(750+1)
#define	GRASS		'.'
#define	ROCK		'*'

#define	in_range(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>	Pos;	// first:row,second:col

int		W,H;
char	grid[MAX_SIZE][MAX_SIZE+1];

int	bfs(int row,int col)
{
	queue<Pos>	q;
	int			cnt;
	
	cnt = 1;
	q.push(make_pair(row,col));
	grid[row][col] = ROCK;
	
	for(;!q.empty();)
	{
		int	current_row,current_col;
		
		current_row = q.front().first;
		current_col = q.front().second;
		
		q.pop();
		
		for(int d_row=-1;d_row<=1;d_row++)
		{
			for(int d_col=-1;d_col<=1;d_col++)
			{
				int	adj_row,adj_col;
				
				adj_row = current_row+d_row;
				adj_col = current_col+d_col;
				
				if( !in_range(1,adj_row,H) || !in_range(1,adj_col,W) )
				{
					continue;
				}
				
				if( grid[adj_row][adj_col] == GRASS )
				{
					cnt++;
					q.push(make_pair(adj_row,adj_col));
					grid[adj_row][adj_col] = ROCK;
				}
			}
		}
	}
	
	return	cnt;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>W>>H;
	
	for(int row=1;row<=H;row++)
	{
		cin>>&grid[row][1];
	}
	
	int	max_cnt;
	
	max_cnt = 0;
	
	for(int row=1;row<=H;row++)
	{
		for(int col=1;col<=W;col++)
		{
			if( grid[row][col] == GRASS )
			{
				max_cnt = max(max_cnt,bfs(row,col));
			}
		}
	}
	
	cout<<max_cnt<<'\n';
	
	return	0;
}
