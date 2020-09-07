#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_FLOOR	(30+1)
#define	MAX_ROW		(30+1)
#define	MAX_COL		(30+1)

#define	UP		0
#define	DOWN	1
#define	EAST	2
#define	WEST	3
#define	SOUTH	4
#define	NORTH	5
#define	MAX_DIR	6

#define	EMPTY	'.'
#define	GOLD	'#'

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

const struct{
	int	d_floor,d_row,d_col;
} adj[MAX_DIR] = {{1,0,0},{-1,0,0},{0,0,1},{0,0,-1},{0,1,0},{0,-1,0}};

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO
{
	int	time,floor,row,col;
};

int		L,R,C;
char	building[MAX_FLOOR][MAX_ROW][MAX_COL+1];

int	escape_building(State& start,State& end)
{
	queue<State>	state_q;
	int				min_escape_time;
	
	state_q.push(start);
	building[start.floor][start.row][start.col] = GOLD;
		
	while( state_q.size() != 0 )
	{
		State	current,next;
		
		current = state_q.front();
		state_q.pop();
		
		if( current.floor == end.floor && current.row == end.row && current.col == end.col )
		{
			return	current.time;
		}
		
		for(int i=UP;i<=NORTH;i++)
		{
			next.time = current.time+1;
			next.floor = current.floor+adj[i].d_floor;
			next.row = current.row+adj[i].d_row;
			next.col = current.col+adj[i].d_col;
			
			if( IN_RANGE(1,next.floor,L) && IN_RANGE(1,next.row,R) && IN_RANGE(1,next.col,C) )
			{
				if( building[next.floor][next.row][next.col] == EMPTY )
				{
					state_q.push(next);
					building[next.floor][next.row][next.col] = GOLD;
				}
			}
		}
	}
	
	return	-1;	
}

int		main(void)
{
	for(;;)
	{
		State	start,end;
		int		min_escape_time;
		
		scanf("%d %d %d",&L,&R,&C);
		
		if( L == 0 && R == 0 && C == 0 )
		{
			break;
		}
		
		start.time = end.time = -1;
		
		for(int f=1;f<=L;f++)
		{
			for(int r=1;r<=R;r++)
			{
				scanf("%s",&building[f][r][1]);
				
				if( start.time == -1 || end.time == -1 )
				{
					for(int c=1;c<=C;c++)
					{
						if( start.time == -1 && building[f][r][c] == 'S' )
						{
							start.time = 0;
							start.floor = f;
							start.row = r;
							start.col = c;
							building[f][r][c] = '.';
						}
						else if( end.time == -1 && building[f][r][c] == 'E' )
						{
							end.time = 0;
							end.floor = f;
							end.row = r;
							end.col = c;
							building[f][r][c] = '.';
						}
					}
				}
			}
		}
		
		min_escape_time = escape_building(start,end);
		
		if( min_escape_time == -1 )
		{
			puts("Trapped!");
		}
		else
		{
			printf("Escaped in %d minute(s).\n",min_escape_time);
		}
	}
	
	return	0;
}
