#include	<stdio.h>

#define	MAX_SIZE	(999+1)

#define	DOWN	0
#define	RIGHT	1
#define	UP		2
#define	LEFT	3
#define	MAX_DIR	4

#define	NEXT_DIR(d)	(((d)+1)%MAX_DIR)

int	table[MAX_SIZE][MAX_SIZE];

const	struct{
	int	dy,dx;
} move_dir[MAX_DIR] = {{1,0},{0,1},{-1,0},{0,-1}};

int	main(void)
{
	int	N,n,size,x,y;
	int	ny,nx,current_y,current_x;
	int	len,dir;
	
	scanf("%d %d",&N,&n);
	
	size = len = N;
	N *= N;
	dir = DOWN;
	current_y = 0;
	current_x = 1;
	
	while(N>0)
	{
		int	i;
		
		if( dir == LEFT || dir == RIGHT )
		{
			len--;
		}
		
		for(i=1;i<=len;i++,N--)
		{
			current_y += move_dir[dir].dy;
			current_x += move_dir[dir].dx;
			
			table[current_y][current_x] = N;
			
			if( N == n )
			{
				ny = current_y;
				nx = current_x;
			}
		}
		
		dir = NEXT_DIR(dir);
	}
	
	for(y=1;y<=size;y++)
	{
		for(x=1;x<=size;x++)
		{
			printf("%d ",table[y][x]);
		}
		puts("");
	}
	printf("%d %d\n",ny,nx);
	
	return	0;
}
