#include	<cstdio>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(100+1)

#define	IN_RANGE(value,low,high)	((low)<=(value)&&(value)<=(high))

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

struct	_MOVE{
	int	row,col;
} move_dir[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int	map[MAX_SIZE][MAX_SIZE];
int	N,max_cnt;

queue< pair<int,int> >	hq;

void	mark_safe_zone(int row,int col,int h)
{
	hq.push(make_pair(row,col));
	
	while( hq.size() != 0 )
	{
		int	current_row,current_col;
		
		current_row = hq.front().first;
		current_col = hq.front().second;
		hq.pop();
		
		for(int i=UP;i<=RIGHT;i++)
		{
			int	next_row,next_col;
			
			next_row = current_row+move_dir[i].row;
			next_col = current_col+move_dir[i].col;
			
			if( IN_RANGE(next_row,1,N) && IN_RANGE(next_col,1,N) )
			{
				if( map[next_row][next_col] > h )
				{
					map[next_row][next_col] = -map[next_row][next_col];
					hq.push(make_pair(next_row,next_col));
				}
			}
		}
	}
}

int		main(void)
{
	scanf("%d",&N);
	
	int	min_h,max_h;
	
	min_h = 0x7FFFFFFF;
	max_h = 0;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			int	h;
			
			scanf("%d",&h);
			map[i][j] = h;
			
			min_h = min(h,min_h);
			max_h = max(h,max_h);
		}
	}
	
	if( min_h == max_h )
	{
		puts("1");
		return	0;
	}
	
	max_cnt = 0;
	
	for(int h=min_h;h<max_h;h++)
	{
		int	cnt = 0;
		
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if( map[i][j] > h )
				{
					map[i][j] = -map[i][j];
					++cnt;
					mark_safe_zone(i,j,h);
				}
			}
		}
		max_cnt = max(cnt,max_cnt);
		
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if( map[i][j] < 0 )
				{
					map[i][j] = -map[i][j];
				}
			}
		}
	}
	printf("%d\n",max_cnt);
	
	return	0;
}
