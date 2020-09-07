#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(100+1)

#define	INIT_ROW	1
#define	INIT_COL	1

#define	EMPTY		0
#define	SNAKE		1
#define	APPLE		2

#define	RIGHT		0
#define	DOWN		1
#define	LEFT		2
#define	UP			3
#define	MAX_DIR		4

#define	TURN_RIGHT(d)	(((d)+1)%MAX_DIR)
#define	TURN_LEFT(d)	(((d)+3)%MAX_DIR)

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>	Snake;

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{0,1},{1,0},{0,-1},{-1,0}};

int		N,K,L;
int		head,tail;
int		board[MAX_SIZE][MAX_SIZE];

vector<Snake>	snake;

bool	move(int& current_time,int& current_dir,int sec_to_move,char turn_dir)
{
	for(int sec=1;sec<=sec_to_move;sec++)
	{
		current_time++;
		
		int	next_row,next_col;
		
		next_row = snake[head].first+adj[current_dir].d_row;
		next_col = snake[head].second+adj[current_dir].d_col;
		
		if( !IN_RANGE(1,next_row,N) || !(IN_RANGE(1,next_col,N)) )
		{
			return	false;
		}
		
		if( board[next_row][next_col] == SNAKE )
		{
			return	false;
		}
		
		head++;
		snake.push_back(make_pair(next_row,next_col));
		
		if( board[next_row][next_col] == EMPTY )
		{
			int&	tail_row = snake[tail].first;
			int&	tail_col = snake[tail].second;
			
			board[tail_row][tail_col] = EMPTY;
			tail++;
		}
		board[next_row][next_col] = SNAKE;
	}
	
	if( turn_dir == 'L' )
	{
		current_dir = TURN_LEFT(current_dir);
	}
	else
	{
		current_dir = TURN_RIGHT(current_dir);
	}
	
	return	true;
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N>>K;
	
	for(int i=1;i<=K;i++)
	{
		int	r,c;
		
		cin>>r>>c;
		board[r][c] = APPLE;
	}
	
	board[INIT_ROW][INIT_COL] = SNAKE;
	snake.push_back(make_pair(INIT_ROW,INIT_COL));
	
	int		time,d,prev_time;
	bool	result;
	
	time = prev_time = 0;
	d = RIGHT;
	
	cin>>L;
	
	for(int i=1;i<=L;i++)
	{
		int		X;
		char	C;
		
		cin>>X>>C;
		
		result = move(time,d,X-prev_time,C);
		
		if( result == false )
		{
			break;
		}
		
		prev_time = X;
	}
	
	if( result == true )
	{
		move(time,d,1000000,' ');
	}
	
	cout<<time<<'\n';
	
	return	0;
}
