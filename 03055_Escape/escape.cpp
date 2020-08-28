#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(50+1)

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

#define	STONE	'X'
#define	WATER	'*'
#define	HEDGE	'S'
#define	BEAVE	'D'
#define	EMPTY	'.'

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO
{
	int	time,row,col;
};

struct _MOVE_DIR{
	int	dy,dx;
} move_dir[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

queue<State>	water;
queue<State>	hedgehog;

int		R,C;
char	map[MAX_SIZE][MAX_SIZE+1];

void	input(void)
{
	scanf("%d %d",&R,&C);
	
	for(int i=1;i<=R;i++)
	{
		scanf("%s",&map[i][1]);
		
		for(int j=1;j<=C;j++)
		{
			State	s;
			if( map[i][j] == HEDGE )
			{
				s.time = 0;
				s.row = i;
				s.col = j;
				
				hedgehog.push(s);
			}
			else if( map[i][j] == WATER )
			{
				s.time = 0;
				s.row = i;
				s.col = j;
				
				water.push(s);
			}
		}
	}
}

int		go_to_beaver(void)
{
	int		min_time;
	State	next_state;
	
	min_time = 0x7FFFFFFF;
	
	while( hedgehog.size() != 0 )
	{
		int	hedge_q_size,water_q_size,i;
		
		for(i=1,water_q_size=water.size();i<=water_q_size;i++)
		{
			int	water_row,water_col;
			
			water_row = water.front().row;
			water_col = water.front().col;
			water.pop();
			
			for(int d=UP;d<=RIGHT;d++)
			{
				int	next_row,next_col;
				
				next_row = water_row+move_dir[d].dy;
				next_col = water_col+move_dir[d].dx;
				
				if( IN_RANGE(1,next_row,R) && IN_RANGE(1,next_col,C) )
				{
					if( map[next_row][next_col] == EMPTY || map[next_row][next_col] == HEDGE )
					{
						map[next_row][next_col] = WATER;
						
						next_state.row = next_row;
						next_state.col = next_col;
						
						water.push(next_state);
					}
				}
			}
		}
		
		for(i=1,hedge_q_size=hedgehog.size();i<=hedge_q_size;i++)
		{
			int	hedge_time,hedge_row,hedge_col;
			
			hedge_time = hedgehog.front().time;
			hedge_row = hedgehog.front().row;
			hedge_col = hedgehog.front().col;
			
			hedgehog.pop();
					
			for(int d=UP;d<=RIGHT;d++)
			{
				int	next_time,next_row,next_col;
				
				next_time = hedge_time+1;
				next_row = hedge_row+move_dir[d].dy;
				next_col = hedge_col+move_dir[d].dx;
				
				if( IN_RANGE(1,next_row,R) && IN_RANGE(1,next_col,C) )
				{
					if( map[next_row][next_col] == BEAVE )
					{
						min_time = min(min_time,next_time);
					}
					else if( map[next_row][next_col] == EMPTY )
					{
						map[next_row][next_col] = HEDGE;
					
						next_state.time = next_time;
						next_state.row = next_row;
						next_state.col = next_col;
					
						hedgehog.push(next_state);
					}
				}
			}
		}
	}
	return	min_time;
}

int	main(void)
{
	int	t;
	
	input();
	
	t= go_to_beaver();
	
	if( t == 0x7FFFFFFF )
	{
		puts("KAKTUS");
	}
	else
	{
		cout<<t<<endl;
	}
	
	return	0;
}
