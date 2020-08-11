#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(200+1)
#define	MAX_DIR		12
#define	MAX_HORSE	(30+1)
#define	EMPTY		0
#define	TRUE		1
#define	FALSE		0

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

typedef	struct	_Monkey	Monkey;
struct	_Monkey{
	int	row;
	int	col;
	int	num_of_movements;
	int	num_of_used_horse;
};

int		map[MAX_SIZE][MAX_SIZE];
int		visited[MAX_HORSE][MAX_SIZE][MAX_SIZE];
int		K,W,H;

int		dx[MAX_DIR] = { 0, 0,-1, 1,-1,-1,-2,-2, 1, 1, 2, 2};
int		dy[MAX_DIR] = {-1, 1, 0, 0,-2, 2, 1,-1,-2, 2,-1, 1};

int		monkey_move(void)
{
	queue<Monkey>	mq;
	Monkey			m;
	int				min_num;
	
	m.row = 1;
	m.col = 1;
	m.num_of_movements = 0;
	m.num_of_used_horse = 0;
	
	mq.push(m);
	visited[0][1][1] = TRUE;
	
	min_num = 0x7FFFFFFF;
	
	while( mq.size() != 0 )
	{
		int	current_monkey_row;
		int	current_monkey_col;
		int	current_num_of_monkey_movements;
		int	current_num_of_used_horse;
		
		current_monkey_row = mq.front().row;
		current_monkey_col = mq.front().col;
		current_num_of_monkey_movements = mq.front().num_of_movements;
		current_num_of_used_horse = mq.front().num_of_used_horse;
		
		mq.pop();
		
		if( current_monkey_row == H && current_monkey_col == W )
		{
			if( current_num_of_monkey_movements < min_num )
			{
				min_num = current_num_of_monkey_movements;
			}
			continue;
		}
		
		for(int i=0;i<4;i++)
		{
			int	next_monkey_row;
			int	next_monkey_col;
			int	next_num_of_monkey_movements;
			int	next_num_of_used_horse;
			
			next_monkey_row = current_monkey_row+dx[i];
			next_monkey_col = current_monkey_col+dy[i];
			next_num_of_monkey_movements = current_num_of_monkey_movements+1;
			next_num_of_used_horse = current_num_of_used_horse;
			
			if( IN_RANGE(1,next_monkey_row,H) && IN_RANGE(1,next_monkey_col,W) )
			{
				if( map[next_monkey_row][next_monkey_col] != EMPTY )
				{
					continue;
				}
				
				if( visited[next_num_of_used_horse][next_monkey_row][next_monkey_col] == FALSE )
				{
					m.row = next_monkey_row;
					m.col = next_monkey_col;
					m.num_of_movements = next_num_of_monkey_movements;
					m.num_of_used_horse = next_num_of_used_horse;
					
					mq.push(m);
					visited[next_num_of_used_horse][next_monkey_row][next_monkey_col] = TRUE;						
				}
			}
		}
		
		if( current_num_of_used_horse == K )
		{
			continue;
		}
				
		for(int i=4;i<MAX_DIR;i++)
		{

			int	next_monkey_row;
			int	next_monkey_col;
			int	next_num_of_monkey_movements;
			int	next_num_of_used_horse;
			
			next_monkey_row = current_monkey_row+dx[i];
			next_monkey_col = current_monkey_col+dy[i];
			next_num_of_monkey_movements = current_num_of_monkey_movements+1;
			next_num_of_used_horse = current_num_of_used_horse+1;
			
			if( IN_RANGE(1,next_monkey_row,H) && IN_RANGE(1,next_monkey_col,W) && map[next_monkey_row][next_monkey_col] == EMPTY )
			{
				if( visited[next_num_of_used_horse][next_monkey_row][next_monkey_col] == FALSE )
				{
					m.row = next_monkey_row;
					m.col = next_monkey_col;
					m.num_of_movements = next_num_of_monkey_movements;
					m.num_of_used_horse = next_num_of_used_horse;
				
					mq.push(m);
					visited[next_num_of_used_horse][next_monkey_row][next_monkey_col] = TRUE;								
				}
			}
		}
	}
	
	if( min_num == 0x7FFFFFFF )
	{
		min_num = -1;
	}
	return	min_num;
}

int		main(void)
{
	scanf("%d %d %d",&K,&W,&H);
	
	for(int i=1;i<=H;i++)
	{
		for(int j=1;j<=W;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	printf("%d\n",monkey_move());
	
	return	0;
}
