#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE			(20+1)
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
#define	MAX_ALLOWED_BUTTON	10

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	WALL	'#'
#define	EMPTY	'.'
#define	COIN	'o'

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

typedef	struct	_COIN_STATE	Coin;
struct	_COIN_STATE
{
	int	c1_row,c1_col,c2_row,c2_col;
};

int		N,M;
char	board[MAX_SIZE][MAX_SIZE+1];
bool	visited[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE];

int		solve(Coin& init)
{
	queue<Coin>	coin_queue;
	
	coin_queue.push(init);
	visited[init.c1_row][init.c1_col][init.c2_row][init.c2_col] = true;
	
	for(int i=1;i<=MAX_ALLOWED_BUTTON;i++)
	{
		for(int j=1,q_size=coin_queue.size();j<=q_size;j++)
		{
			Coin	current,next;
			
			current = coin_queue.front();
			coin_queue.pop();
			
			for(int d=UP;d<=RIGHT;d++)
			{
				next.c1_row = current.c1_row+adj[d].d_row;
				next.c1_col = current.c1_col+adj[d].d_col;
				next.c2_row = current.c2_row+adj[d].d_row;
				next.c2_col = current.c2_col+adj[d].d_col;
				
				if( IN_RANGE(1,next.c1_row,N) && IN_RANGE(1,next.c1_col,M) && board[next.c1_row][next.c1_col] == WALL )
				{
					next.c1_row = current.c1_row;
					next.c1_col = current.c1_col;
				}
				
				if( IN_RANGE(1,next.c2_row,N) && IN_RANGE(1,next.c2_col,M) && board[next.c2_row][next.c2_col] == WALL )
				{
					next.c2_row = current.c2_row;
					next.c2_col = current.c2_col;
				}
							
				if( IN_RANGE(1,next.c1_row,N) && IN_RANGE(1,next.c1_col,M) )
				{
					if( !(IN_RANGE(1,next.c2_row,N) && IN_RANGE(1,next.c2_col,M)) )
					{
						return	i;
					}
				}
				
				if( IN_RANGE(1,next.c2_row,N) && IN_RANGE(1,next.c2_col,M) )
				{
					if( !(IN_RANGE(1,next.c1_row,N) && IN_RANGE(1,next.c1_col,M)) )
					{
						return	i;
					}
				}
				
				if( !(IN_RANGE(1,next.c1_row,N) && IN_RANGE(1,next.c1_col,M)) && 
					!(IN_RANGE(1,next.c2_row,N) && IN_RANGE(1,next.c2_col,M)) )
				{
					continue;		
				}
				
				if( visited[next.c1_row][next.c1_col][next.c2_row][next.c2_col] == false )
				{
					visited[next.c1_row][next.c1_col][next.c2_row][next.c2_col] = true;
					coin_queue.push(next);
				}
			}
		}
	}
	
	return	-1;
}

int		main(void)
{
	pair<int,int>	coin[2];
	int				index;
	Coin			c;
	
	scanf("%d %d",&N,&M);
	
	index = 0;
	
	for(int i=1;i<=N;i++)
	{
		scanf("%s",&board[i][1]);
		
		for(int j=1;j<=M;j++)
		{
			if( board[i][j] == COIN )
			{
				coin[index].first = i;
				coin[index].second = j;
				index++;
				
				board[i][j] = EMPTY;
			}
		}
	}
	
	c.c1_row = coin[0].first;
	c.c1_col = coin[0].second;
	c.c2_row = coin[1].first;
	c.c2_col = coin[1].second;
	
	printf("%d\n",solve(c));
	
	return	0;
}
