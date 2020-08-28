#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(500+1)

#define	UP		0
#define	RIGHT	1
#define	DOWN	2
#define	LEFT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

bool	visited[MAX_SIZE][MAX_SIZE][MAX_DIR];

typedef	struct	_SIGNAL_INFO	Signal;
struct	_SIGNAL_INFO
{
	int	row,col,direction,time;
};

const struct{
	int	d_row,d_col;
}adj[MAX_DIR] = {{-1,0},{0,1},{1,0},{0,-1}};

#define	EMPTY		'.'
#define	BLACK_HOLE	'C'
#define	PLANET1		'\\'
#define	PLANET2		'/'

#define	NOT_VISITED	-1

const int	next_dir_of_planet1[MAX_DIR] = {LEFT,DOWN,RIGHT,UP};
const int	next_dir_of_planet2[MAX_DIR] = {RIGHT,UP,LEFT,DOWN};
const char	dir_char[MAX_DIR] = {'U','R','D','L'};

int		N,M,PR,PC;
char	space[MAX_SIZE][MAX_SIZE+1];

void	init_visited(void)
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			visited[i][j][UP] = visited[i][j][DOWN] = visited[i][j][LEFT] = visited[i][j][RIGHT] = false;
		}
	}
}
int		send_signal(int s_row,int s_col,int s_dir)
{
	Signal			s;
	int				max_time;
	
	s.row = s_row;
	s.col = s_col;
	s.time = 0;
	s.direction = s_dir;

	max_time = 0;
	
	while(1)
	{
		if( !IN_RANGE(1,s.row,N) || !IN_RANGE(1,s.col,M) || space[s.row][s.col] == BLACK_HOLE )
		{
			max_time = max(max_time,s.time);
			break;
		}
		
		if( visited[s.row][s.col][s.direction] == true )
		{
			max_time = 0x7FFFFFFF;
			break;
		}
		
		visited[s.row][s.col][s.direction] = true;
		
		s.row = s.row+adj[s.direction].d_row;
		s.col = s.col+adj[s.direction].d_col;
		s.time = s.time+1;
		
		if( space[s.row][s.col] != EMPTY )
		{
			if( space[s.row][s.col] == PLANET1 )
			{
				s.direction = next_dir_of_planet1[s.direction];
			}
			else
			{
				s.direction = next_dir_of_planet2[s.direction];
			}
		}
	}
	
	return	max_time;
}

int		main(void)
{
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%s",&space[i][1]);
	}
	
	scanf("%d %d",&PR,&PC);
	
	int	max_time,max_time_dir;
	
	max_time = 0;
	
	for(int i=UP;i<=LEFT;i++)
	{
		int	current_max_time;
		
		init_visited();
		
		current_max_time = send_signal(PR,PC,i);
		
		if( current_max_time > max_time )
		{
			max_time = current_max_time;
			max_time_dir = i;
		}
		
		if( max_time == 0x7FFFFFFF )
		{
			break;
		}
	}
	
	if( max_time != 0x7FFFFFFF )
	{
		printf("%c\n%d\n",dir_char[max_time_dir],max_time);
	}
	else
	{
		printf("%c\nVoyager\n",dir_char[max_time_dir]);
	}
	
	return	0;
}
