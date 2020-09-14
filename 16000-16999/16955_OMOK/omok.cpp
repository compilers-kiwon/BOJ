#include	<iostream>

using namespace	std;

#define	KOO		'X'
#define	CUBE	'O'
#define	EMPTY	'.'

#define	MAX_SIZE	10
#define	WIN_CNT		4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	UP			0
#define	DOWN		1
#define	LEFT		2
#define	RIGHT		3
#define	UP_LEFT		4
#define	DOWN_RIGHT	5
#define	UP_RIGHT	6
#define	DOWN_LEFT	7
#define	MAX_DIR		8

const struct{
	int	d_row,d_col;	
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,1},{-1,1},{1,-1}};

char	state[MAX_SIZE+1][MAX_SIZE+2];

int	get_cnt(int row,int col,int d1,int d2)
{
	int	cnt,adj_row,adj_col;
	
	cnt = 0;
	
	for(adj_row=row+adj[d1].d_row,adj_col=col+adj[d1].d_col;
		IN_RANGE(1,adj_row,MAX_SIZE)&&IN_RANGE(1,adj_col,MAX_SIZE)&&state[adj_row][adj_col]==KOO;
		adj_row=adj_row+adj[d1].d_row,adj_col=adj_col+adj[d1].d_col,cnt++);
		
	for(adj_row=row+adj[d2].d_row,adj_col=col+adj[d2].d_col;
		IN_RANGE(1,adj_row,MAX_SIZE)&&IN_RANGE(1,adj_col,MAX_SIZE)&&state[adj_row][adj_col]==KOO;
		adj_row=adj_row+adj[d2].d_row,adj_col=adj_col+adj[d2].d_col,cnt++);
	
	return	cnt;	
}

int	main(void)
{
	for(int i=1;i<=MAX_SIZE;i++)
	{
		scanf("%s",&state[i][1]);
	}
	
	bool	found;
	
	found = false;
	
	for(int row=1;row<=MAX_SIZE&&found==false;row++)
	{
		for(int col=1;col<=MAX_SIZE&&found==false;col++)
		{
			if( state[row][col]==EMPTY )
			{
				for(int d=UP;d<MAX_DIR&&found==false;d+=2)
				{
					if( get_cnt(row,col,d,d+1) >= WIN_CNT )
					{
						found = true;
					}
				}
			}
		}
	}
	
	if( found == true )
	{
		puts("1");
	}
	else
	{
		puts("0");
	}
	
	return	0;
}
