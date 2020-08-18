#include	<iostream>

using namespace	std;

#define	char2int(c)			((int)((c)-'0'))
#define	int2char(n)			((char)(n)+'0')

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

#define	MAX_SIZE	(1000+1)
#define	EMPTY		'.'
#define	MINE		-1

#define	UP			0
#define	UP_RIGHT	1
#define	RIGHT		2
#define	DOWN_RIGHT	3
#define	DOWN		4
#define	DOWN_LEFT	5
#define	LEFT		6
#define	UP_LEFT		7
#define	MAX_DIR		8

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

int		N,converted_map[MAX_SIZE][MAX_SIZE];
char	map[MAX_SIZE][MAX_SIZE+1];


int		main(void)
{
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%s",&map[i][1]);
	}
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			if( map[row][col] != EMPTY )
			{
				converted_map[row][col] = MINE;
			}
			else
			{
				int	num_of_adj_mine,d;
				
				for(num_of_adj_mine=0,d=UP;d<=UP_LEFT;d++)
				{
					int	adj_row,adj_col;
					
					adj_row = row+adj[d].d_row;
					adj_col = col+adj[d].d_col;
					
					if( IN_RANGE(1,adj_row,N) && IN_RANGE(1,adj_col,N) )
					{
						if( map[adj_row][adj_col] != EMPTY )
						{
							num_of_adj_mine += char2int(map[adj_row][adj_col]);
						}
					}
				}
				converted_map[row][col] = num_of_adj_mine;
			}
		}
	}
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			char	c;
			
			if( converted_map[row][col] == MINE )
			{
				c = '*';
			}
			else
			{
				if( IN_RANGE(0,converted_map[row][col],9) )
				{
					c = int2char(converted_map[row][col]);
				}
				else
				{
					c = 'M';
				}
			}
			putchar(c);
		}
		putchar('\n');
	}
	
	return	0;
}
