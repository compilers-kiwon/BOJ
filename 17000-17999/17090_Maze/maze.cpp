#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(500+1)

#define	POSSIBLE	1
#define	IMPOSSIBLE	0
#define	TBD			-1

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int	N,M,map[MAX_SIZE][MAX_SIZE],state[MAX_SIZE][MAX_SIZE];

int		dfs(int row,int col)
{
	int&	ret = state[row][col];
	int&	d = map[row][col];
	int		adj_row,adj_col;
	
	if( ret != TBD )
	{
		return	ret;
	}
	
	ret = IMPOSSIBLE;
	
	adj_row = row+adj[d].d_row;
	adj_col = col+adj[d].d_col;
	
	if( IN_RANGE(1,adj_row,N) && IN_RANGE(1,adj_col,M) )
	{
		ret = dfs(adj_row,adj_col);
	}
	else
	{
		ret = POSSIBLE;
	}
	
	return	ret;
}

void	input(void)
{
	scanf("%d %d\n",&N,&M);
	
	for(int row=1;row<=N;row++)
	{
		char	buf[MAX_SIZE+1];
		
		scanf("%s",&buf[1]);
		
		for(int col=1;col<=M;col++)
		{
			int&	m = map[row][col];
			
			switch(buf[col])
			{
				case	'U':
					m = UP;
					break;
				case	'D':
					m = DOWN;
					break;
				case	'L':
					m = LEFT;
					break;
				case	'R':
					m = RIGHT;
					break;
			}
			
			state[row][col] = TBD;
		}
	}
}

int		main(void)
{
	input();
	
	int	cnt;
	
	cnt = 0;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			cnt += dfs(row,col);
		}
	}
	
	printf("%d\n",cnt);
	
	return	0;
}
