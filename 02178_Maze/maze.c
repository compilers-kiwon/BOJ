#include	<stdio.h>

#define	MAX_SIZE	(100+1)
#define	MAX_SPACE	(100*100)

#define	TRUE	'1'
#define	FALSE	'0'

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

typedef	struct	_XY_INFO	XY_info;
struct	_XY_INFO
{
	int	x,y,cnt;
};

struct{
	int	x,y;
} move_factor[MAX_DIR] = {{0,-1},{0,1},{-1,0},{1,0}};

char	maze[MAX_SIZE][MAX_SIZE+1];
int		N,M;
XY_info	queue[MAX_SPACE];
int		front,back;

int		main(void)
{
	int	i,j,answer;
	
	scanf("%d %d",&N,&M);
	
	for(i=1;i<=N;i++)
	{
		scanf("%s",&maze[i][1]);
	}
	
	front = back = 0;
	
	queue[back].x = queue[back].y = queue[back].cnt = 1;
	++back;
	
	while( front != back )
	{
		int	current_x,current_y,current_cnt;
		int	new_x,new_y,new_cnt;
		
		current_x = queue[front].x;
		current_y = queue[front].y;
		current_cnt = queue[front].cnt;
		++front;
		
		if( current_x == M && current_y == N )
		{
			answer = current_cnt;
			break;
		}
		
		new_cnt = current_cnt+1;
		
		for(i=UP;i<=RIGHT;i++)
		{
			new_x = current_x+move_factor[i].x;
			new_y = current_y+move_factor[i].y;
			
			if( new_x>=1 && new_x<=M && new_y>=1 && new_y<=N && maze[new_y][new_x]==TRUE )
			{
				queue[back].x = new_x;
				queue[back].y = new_y;
				queue[back].cnt = new_cnt;
				++back;
				
				maze[new_y][new_x] = FALSE;
			}
		}
	}
	printf("%d\n",answer);
	
	return	0;
}



