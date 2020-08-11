#include	<cstdio>

using namespace	std;

#define	MAX_SIZE	(500+1)

#define	UP		0
#define	DWON	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,V,MAX)	(((MIN)<=(V))&&((V)<=(MAX)))

struct	_MOVE{
	int	row,col;
} move_dir[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int	map[MAX_SIZE][MAX_SIZE],cnt[MAX_SIZE][MAX_SIZE];
int	M,N;	// M:row,N:col


int	count_possible_path(int row,int col)
{
	if( cnt[row][col] != -1 )
	{
		return	cnt[row][col];
	}
	
	int result = 0;
	
	for(int i=UP;i<=RIGHT;i++)
	{
		int	prev_row,prev_col;
		
		prev_row = row+move_dir[i].row;
		prev_col = col+move_dir[i].col;
		
		if( IN_RANGE(1,prev_row,M)==true && IN_RANGE(1,prev_col,N)==true )
		{
			if( map[row][col] < map[prev_row][prev_col] )
			{
				result += count_possible_path(prev_row,prev_col);
			}
		}
	}
	cnt[row][col] = result;
	
	return	result;
}

int		main(void)
{
	scanf("%d %d",&M,&N);
	
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=N;j++)
		{
			scanf("%d",&map[i][j]);
			cnt[i][j] = -1;
		}
	}
	
	cnt[1][1] = 1;
		
	printf("%d\n",count_possible_path(M,N));
	
	return	0;
}
