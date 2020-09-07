#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100+1)

char	mine[MAX_SIZE][MAX_SIZE+1];
int		cnt[MAX_SIZE][MAX_SIZE];

#define	MINE		'*'

#define	UP			0
#define	UP_RIGHT	1
#define	RIGHT		2
#define	DOWN_RIGHT	3
#define	DOWN		4
#define	DOWN_LEFT	5
#define	LEFT		6
#define	UP_LEFT		7
#define	MAX_DIR		8

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const	struct{
	int	dx,dy;
} adj[MAX_DIR] = {{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1}};

int		main(void)
{
	while(1)
	{
		int	R,C;
		
		scanf("%d %d",&R,&C);
		
		if( R == 0 && C == 0 )
		{
			break;
		}
		
		for(int i=1;i<=R;i++)
		{
			scanf("%s",&mine[i][1]);
		}
		
		for(int row=1;row<=R;row++)
		{
			for(int col=1;col<=C;col++)
			{
				if( mine[row][col] != MINE )
				{
					cnt[row][col] = 0;
					
					for(int i=UP;i<=UP_LEFT;i++)
					{
						int	adj_row,adj_col;
						
						adj_row = row+adj[i].dy;
						adj_col = col+adj[i].dx;
						
						if( IN_RANGE(1,adj_row,R) && IN_RANGE(1,adj_col,C) && mine[adj_row][adj_col] == MINE )
						{
							cnt[row][col]++;
						}
					}
				}
			}
		}
		
		for(int row=1;row<=R;row++)
		{
			for(int col=1;col<=C;col++)
			{
				if( mine[row][col] == MINE )
				{
					putchar(MINE);
				}
				else
				{
					printf("%d",cnt[row][col]);
				}
			}
			puts("");
		}
	}
	
	return	0;
}
