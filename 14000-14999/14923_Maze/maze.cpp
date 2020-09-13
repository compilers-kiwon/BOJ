#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	CRASH		2

#define	TRUE	1
#define	FALSE	0

#define	WALL	1
#define	EMPTY	0

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	dx,dy;
} adj[MAX_DIR] = {{0,-1},{0,1},{-1,0},{1,0}};

int	maze[MAX_SIZE][MAX_SIZE],dp[MAX_SIZE][MAX_SIZE][CRASH];
int	N,M,Hx,Hy,Ex,Ey;

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO
{
	int	x,y,crashed,m;
};

void	input(void)
{
	scanf("%d %d %d %d %d %d",&N,&M,&Hy,&Hx,&Ey,&Ex);
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			scanf("%d",&maze[i][j]);
			dp[i][j][TRUE] = dp[i][j][FALSE] = 0x7FFFFFFF;
		}
	}
}

void	escape(void)
{
	queue<State>	state_q;
	State			s;
	
	s.x = Hx;
	s.y = Hy;
	s.crashed = maze[Hy][Hx];
	s.m = 0;
	
	dp[Hy][Hx][s.crashed] = 0;
	state_q.push(s);
	
	while( !state_q.empty() )
	{
		State	current;
		
		current = state_q.front();
		state_q.pop();
		
		if( current.x == Ex && current.y == Ey )
		{
			continue;	
		}
		
		for(int i=UP;i<=RIGHT;i++)
		{
			State	next;
			
			next.x = current.x+adj[i].dx;
			next.y = current.y+adj[i].dy;
			
			if( IN_RANGE(1,next.x,M) && IN_RANGE(1,next.y,N) )
			{
				if( maze[next.y][next.x] == EMPTY || current.crashed == FALSE )
				{
					if( maze[next.y][next.x] == WALL )
					{
						next.crashed = TRUE;
					}
					else
					{
						next.crashed = current.crashed;
					}
					
					next.m = current.m+1;
					
					if( next.m < dp[next.y][next.x][next.crashed] )
					{
						dp[next.y][next.x][next.crashed] = next.m;
						state_q.push(next);
					}
				}
			}	
		}	
	} 
}

int		main(void)
{
	input();
	escape();
	
	int	D;
	
	D = min(dp[Ey][Ex][TRUE],dp[Ey][Ex][FALSE]);
	
	if( D == 0x7FFFFFFF )
	{
		D = -1;
	}
	printf("%d\n",D);
	
	return	0;
}
