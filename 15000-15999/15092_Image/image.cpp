#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(100+1)
#define	BLACK		'#'
#define	WHITE		'.'
#define	MAX_DIR		8

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};

int		n,m;
char	image[MAX_SIZE][MAX_SIZE+1];

typedef	pair<int,int>	Pos;

void	input(void)
{
	scanf("%d %d",&n,&m);
	
	for(int row=1;row<=n;row++)
	{
		scanf("%s",&image[row][1]);
	}
}

void	find_loop(int r,int c)
{
	queue<Pos>	black_q;
	
	image[r][c] = WHITE;
	black_q.push(make_pair(r,c));
	
	for(;!black_q.empty();)
	{
		int	row,col;
		
		row = black_q.front().first;
		col = black_q.front().second;
		
		black_q.pop();
		
		for(int d=0;d<MAX_DIR;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = row+adj[d].d_row;
			adj_col = col+adj[d].d_col;
			
			if( IN_RANGE(1,adj_row,n) && IN_RANGE(1,adj_col,m) )
			{
				if( image[adj_row][adj_col] == BLACK )
				{
					image[adj_row][adj_col] = WHITE;
					black_q.push(make_pair(adj_row,adj_col));
				}
			}
		}
	}
}

int		main(void)
{
	int	cnt;
	
	input();

	cnt = 0;
	
	for(int row=1;row<=n;row++)
	{
		for(int col=1;col<=m;col++)
		{
			if( image[row][col] == BLACK )
			{
				cnt++;
				find_loop(row,col);
			}
		}
	}
	
	printf("%d\n",cnt);
	
	return	0;	
}
