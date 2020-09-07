#include	<cstdio>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(50+1)
#define	INF			(MAX_SIZE*MAX_SIZE+MAX_SIZE*MAX_SIZE+1)

#define	IN_RANGE(MIN,V,MAX)	((MIN)<=(V) && (V)<=(MAX))

#define	WATER	'W'
#define	LAND	'L'

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

typedef	pair<int,int>		Location;
typedef	pair<Location,int>	Journey;

struct	_MOVE{
	int	row,col;
} move_dir[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

char	map[MAX_SIZE][MAX_SIZE+1];
bool	visited[MAX_SIZE][MAX_SIZE];

void	init_visited(int h,int w)
{
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			visited[i][j] = false;
		}
	}
}

int		bfs(int row,int col,int h,int w)
{
	queue<Journey>	q;
	Location		loc;
	
	init_visited(h,w);
	
	visited[row][col] = true;
	loc = make_pair(row,col);
	q.push(make_pair(loc,0));
	
	int	max_time = 0;
	
	while( q.size() != 0 )
	{
		int	current_row,current_col,current_time;
		
		current_row = q.front().first.first;
		current_col = q.front().first.second;
		current_time = q.front().second;
		q.pop();
		
		max_time = max(max_time,current_time);
		
		for(int i=UP;i<=RIGHT;i++)
		{
			int	next_row,next_col,next_time;
			
			next_row = current_row+move_dir[i].row;
			next_col = current_col+move_dir[i].col;
			next_time = current_time+1;
			
			if( IN_RANGE(1,next_row,h) && IN_RANGE(1,next_col,w) )
			{
				if( map[next_row][next_col] == LAND && visited[next_row][next_col] == false )
				{
					visited[next_row][next_col] = true;
					loc = make_pair(next_row,next_col);
					q.push(make_pair(loc,next_time));
				}
			}
		}
	}
	return	max_time;
}

int		main(void)
{
	int	h,w;
	
	scanf("%d %d",&h,&w);
	
	int	num_of_cells = h*w;
	
	for(int i=1;i<=h;i++)
	{
		scanf("%s",&map[i][1]);
	}
	
	int	max_time = 0;
	
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if( map[i][j] == LAND )
			{
				max_time = max(max_time,bfs(i,j,h,w));
			}
		}
	}
	printf("%d\n",max_time);
	
	return	0;
}
