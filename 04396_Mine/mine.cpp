#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	10
#define	MINE		'*'
#define	OPENED		'x'
#define	CLOSED		'.'

#define	int2char(n)			((char)((n)+(int)'0'))
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	MAX_DIR	8

const	struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

typedef	pair<int,int>	Pos;

int		n;
char	grid[MAX_SIZE+1][MAX_SIZE+1],current[MAX_SIZE+1][MAX_SIZE+1];

void	init(vector<Pos>& mine)
{
	scanf("%d",&n);
	
	for(int row=1;row<=n;row++)
	{
		scanf("%s",&grid[row][1]);
	}
	
	for(int row=1;row<=n;row++)
	{
		for(int col=1;col<=n;col++)
		{
			if( grid[row][col] == MINE )
			{
				mine.push_back(make_pair(row,col));
			}
		}
	}
	
	for(int row=1;row<=n;row++)
	{
		scanf("%s",&current[row][1]);
	}
}

bool	is_mine_opened(vector<Pos>& mine)
{
	bool	ret;
	int		i;
	
	for(ret=false,i=0;i<mine.size();i++)
	{
		int&	row = mine[i].first;
		int&	col = mine[i].second;
		
		if( current[row][col] == OPENED )
		{
			ret = true;
			break;
		}
	}
	
	return	ret;
}

char	count_num_of_mine(int row,int col)
{
	if( grid[row][col] == MINE )
	{
		return	MINE;
	}
	
	int	d,cnt;
	
	for(d=cnt=0;d<MAX_DIR;d++)
	{
		int	adj_row,adj_col;
		
		adj_row = row+adj[d].d_row;
		adj_col = col+adj[d].d_col;
		
		if( IN_RANGE(1,adj_row,n) && IN_RANGE(1,adj_col,n) && grid[adj_row][adj_col]==MINE )
		{
			cnt++;
		}
	}
	
	return	int2char(cnt);
}

int		main(void)
{
	vector<Pos>	m;
	bool		mine_flag;
	
	init(m);
	
	mine_flag = false;
	
	if( is_mine_opened(m) == true )
	{
		mine_flag = true;
	}
	
	for(int row=1;row<=n;row++)
	{
		for(int col=1;col<=n;col++)
		{
			char	c;
			
			if( current[row][col] == OPENED )
			{
				c = count_num_of_mine(row,col);
			}
			else
			{
				if( mine_flag==true && grid[row][col]==MINE )
				{
					c = MINE;
				}
				else
				{
					c = CLOSED;
				}
			}
			
			putchar(c);
		}
		puts("");
	}
	
	return	0;
}
