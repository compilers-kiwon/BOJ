#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(50+1)

#define	EMPTY	1
#define	WALL	0

#define	TRUE	1
#define	FALSE	0

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

struct	_MOVE{
	int	row,col;
} move_dir[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

typedef	pair<int,int>		RowCol;
typedef	pair<RowCol,int>	State;

int				n,maze[MAX_SIZE][MAX_SIZE];
int				visited[MAX_SIZE][MAX_SIZE];
queue<State>	state_q;

void	input(void)
{
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%1d",&maze[i][j]);
			visited[i][j] = n*n;
		}
	}
}

int		find_path(int start_row,int start_col)
{
	RowCol	s;
		
	s = make_pair(start_row,start_col);
	state_q.push(make_pair(s,0));
	visited[start_row][start_col] = 0;
		
	while( state_q.size() != 0 )
	{
		int	current_row,current_col,current_num_of_removed_wall;
		
		current_row = state_q.front().first.first;
		current_col = state_q.front().first.second;
		current_num_of_removed_wall = state_q.front().second;
		
		state_q.pop();
		
		if( current_row == n && current_col == n )
		{
			continue;
		}
		
		for(int i=UP;i<=RIGHT;i++)
		{
			int	next_row,next_col,next_num_of_removed_wall;
			
			next_row = current_row+move_dir[i].row;
			next_col = current_col+move_dir[i].col;
			
			if( IN_RANGE(1,next_row,n) && IN_RANGE(1,next_col,n) )
			{
				if( maze[next_row][next_col] == EMPTY )
				{
					next_num_of_removed_wall = current_num_of_removed_wall;
				}
				else
				{
					next_num_of_removed_wall = current_num_of_removed_wall+1;
				}
				
				if( visited[next_row][next_col] > next_num_of_removed_wall )
				{
					visited[next_row][next_col] = next_num_of_removed_wall;
					s = make_pair(next_row,next_col);
					state_q.push(make_pair(s,next_num_of_removed_wall));
				}
			}
		}
	}
	return	visited[n][n];
}

int		main(void)
{
	input();
	
	printf("%d\n",find_path(1,1));
	
	return	0;
}
