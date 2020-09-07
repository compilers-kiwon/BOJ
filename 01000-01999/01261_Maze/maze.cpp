#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(100+1)
#define	MAX_CRASH	(98+1)

#define	EMPTY	'0'
#define	WALL	'1'

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

typedef	struct	_STATE	State;
struct	_STATE
{
	int	row;
	int	col;
	int	crash;
};

int		dx[MAX_DIR] = { 0, 0,-1, 1};
int		dy[MAX_DIR] = {-1, 1, 0, 0};

char	maze[MAX_SIZE][MAX_SIZE+1];
int		visited[MAX_SIZE][MAX_SIZE];

int		N,M;

void	input(void)
{
	scanf("%d %d",&M,&N);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%s",&maze[i][1]);
	}
}

int		find_path(void)
{
	State			s;
	queue<State>	state_q;
	
	s.row = 1;
	s.col = 1;
	s.crash = 0;
	
	state_q.push(s);
	visited[1][1] = 0;
	
	while( state_q.size() != 0 )
	{
		int	current_row,current_col,current_crash;
		
		current_row = state_q.front().row;
		current_col = state_q.front().col;
		current_crash = state_q.front().crash;
		
		state_q.pop();
		
		if( current_row == N && current_col == M )
		{
			continue;
		}
		
		for(int i=UP;i<=RIGHT;i++)
		{
			int	next_row,next_col,next_crash;
			
			next_row = current_row+dy[i];
			next_col = current_col+dx[i];
						
			if( IN_RANGE(1,next_row,N) && IN_RANGE(1,next_col,M) )
			{
				if( maze[next_row][next_col] == WALL )
				{
					next_crash = current_crash+1;
				}
				else
				{
					next_crash = current_crash;
				}
								
				if( next_crash < visited[next_row][next_col] )
				{
					s.row = next_row;
					s.col = next_col;
					s.crash = next_crash;
				
					state_q.push(s);
					visited[next_row][next_col] = next_crash;
				}
			}
		}
	}
	return	visited[N][M];
}

int		main(void)
{
	input();
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			visited[row][col] = MAX_SIZE*MAX_SIZE;
		}
	}
	cout<<find_path()<<endl;
	
	return	0;
}
