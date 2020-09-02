#include	<cstdio>

using namespace	std;

#define	LAND		1
#define	SEA			0
#define	MAX_SIZE	50

#define	IN_RANGE(MIN,value,MAX)	((MIN)<=(value) && (value)<=(MAX))

#define	N		0
#define	NE		1
#define	E		2
#define	SE		3
#define	S		4
#define	SW		5
#define	W		6
#define	NW		7
#define	MAX_DIR	8

struct	_MOVE{
	int	row,col;
} move_dir[MAX_DIR] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

int	map[MAX_SIZE][MAX_SIZE];
int	w,h;

void	find_land(int current_row,int current_col)
{
	for(int i=N;i<=NW;i++)
	{
		int	next_row,next_col;
		
		next_row = current_row+move_dir[i].row;
		next_col = current_col+move_dir[i].col;
		
		if( IN_RANGE(1,next_row,h) && IN_RANGE(1,next_col,w) )
		{
			if( map[next_row][next_col] == LAND )
			{
				map[next_row][next_col] = SEA;
				find_land(next_row,next_col);
			}
		}
	}
}

int		main(void)
{
	for(;;)
	{
		scanf("%d %d",&w,&h);
		
		if( w==0 && h==0 )
		{
			break;
		}
		
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		
		int	cnt = 0;
		
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)
			{
				if( map[i][j] == LAND )
				{
					map[i][j] = SEA;
					++cnt;
					find_land(i,j);
				}
			}
		}
		printf("%d\n",cnt);
	}
	return	0;
}


