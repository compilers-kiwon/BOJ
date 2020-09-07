#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000+1)

#define	EMPTY	0
#define	WALL	1

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
	int	distance;
	int	crash;
};

int	maze[MAX_SIZE][MAX_SIZE];
int	visited[2][MAX_SIZE][MAX_SIZE];
int	N,M;

int	dx[MAX_DIR] = { 0, 0,-1, 1};
int	dy[MAX_DIR] = {-1, 1, 0, 0};

queue<State>	state_q;

void	input(void)
{
	scanf("%d %d",&N,&M);
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			scanf("%1d",&maze[row][col]);
			visited[0][row][col] = visited[1][row][col] = MAX_SIZE*MAX_SIZE;
		}
	}
}

int		find_min_distance(void)
{
	State	s;
	
	s.row = 1;
	s.col = 1;
	s.distance = 1;
	s.crash = 0;
	
	visited[0][1][1] = 1;
	state_q.push(s);
	
	while( state_q.size() != 0 )
	{
		int	current_row,current_col,current_distance,current_crash;
		
		current_row = state_q.front().row;
		current_col = state_q.front().col;
		current_distance = state_q.front().distance;
		current_crash = state_q.front().crash;
		
		state_q.pop();
		
		if( current_row == N && current_col == M )
		{
			continue;
		}
		
		for(int i=UP;i<=RIGHT;i++)
		{
			int	next_row,next_col,next_distance,next_crash;
			
			next_row = current_row+dy[i];
			next_col = current_col+dx[i];
			next_distance = current_distance+1;
			
			if( IN_RANGE(1,next_row,N) && IN_RANGE(1,next_col,M) )
			{
				if( maze[next_row][next_col] == WALL && current_crash == 0 )
				{
					next_crash = current_crash+1;
				}
				else if( maze[next_row][next_col] == EMPTY )
				{
					next_crash = current_crash;
				}
				else
				{
					continue;
				}
				
				if( next_distance < visited[next_crash][next_row][next_col] )
				{
					s.row = next_row;
					s.col = next_col;
					s.distance = next_distance;
					s.crash = next_crash;
					
					state_q.push(s);
					visited[next_crash][next_row][next_col] = next_distance;
				}
			}
		}
	}
	
	int	result = min(visited[0][N][M],visited[1][N][M]);
	
	if( result == MAX_SIZE*MAX_SIZE )
	{
		result = -1;
	}
	
	return	result;
}

int		main(void)
{
	input();
	
	printf("%d\n",find_min_distance());
	
	return	0;
}
