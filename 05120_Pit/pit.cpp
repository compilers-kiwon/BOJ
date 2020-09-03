#include	<iostream>
#include	<string>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(50+1)
#define	INF			0x7FFFFFFF
	
#define	FORWARD		0
#define	BACKWARD	1
#define	FASTER		2
#define	SLOWER		3
#define	STOP		4
#define	RIGHT		5
#define	LEFT		6
#define	NOOP		7

#define	NORTH	0
#define	EAST	1
#define	SOUTH	2
#define	WEST	3
#define	MAX_DIR	4

#define	TURN_RIGHT(d)	(((d)+1)%MAX_DIR)
#define	TURN_LEFT(d)	(((d)+MAX_DIR-1)%MAX_DIR)

#define	is_stopped(s)	((s)==0)
#define	is_forward(s)	((s)>=1)

#define	MAX_SPEED	5

const struct{
	int	d_col,d_row;
} adj[MAX_DIR] = {{0,-1},{1,0},{0,1},{-1,0}};

#define	EMPTY		'.'
#define	PIT			'P'
#define	START		'R'
#define	DESTINATION	'D'

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
#define	SHIFT_SPEED(s)		(((s)==-1)?MAX_SPEED+1:s)

typedef	struct	_ROVER_INFO	Rover;
struct	_ROVER_INFO
{
	int	time;
	int	direction,speed;
	int	row,col;
};

int		h,w,s_row,s_col;
int		dp[MAX_SIZE][MAX_SIZE][MAX_DIR][MAX_SPEED+2];
char	grid[MAX_SIZE][MAX_SIZE+1];

void	input(void)
{
	cin>>h>>w;
	
	for(int row=1;row<=h;row++)
	{
		cin>>&grid[row][1];
		
		for(int col=1;col<=w;col++)
		{
			if( grid[row][col] == START )
			{
				s_row = row;
				s_col = col;
			}
		}
	}
}

bool	is_valid(Rover& dst,Rover& src)
{
	if( !IN_RANGE(1,dst.row,h) || !IN_RANGE(1,dst.col,w) )
	{
		return	false;
	}
	
	if( grid[dst.row][dst.col] == PIT )
	{
		return	false;
	}
	
	if( dst.speed < 0 )
	{
		for(int row=src.row,col=src.col;!(row==dst.row&&col==dst.col);
			row-=adj[dst.direction].d_row,col-=adj[dst.direction].d_col)
		{
			if( grid[row][col] == PIT )
			{
				return	false;
			}
		}
	}
	else
	{
		for(int row=src.row,col=src.col;!(row==dst.row&&col==dst.col);
			row+=adj[dst.direction].d_row,col+=adj[dst.direction].d_col)
		{
			if( grid[row][col] == PIT )
			{
				return	false;
			}
		}
	}
	
	if( dp[dst.row][dst.col][dst.direction][SHIFT_SPEED(dst.speed)] <= dst.time )
	{
		return	false;
	}
	
	return	true;
}

int		find_min_time(void)
{
	queue<Rover>	rq;
	Rover			r;
	int				ret;
	
	for(int row=1;row<=h;row++)
	{
		for(int col=1;col<=w;col++)
		{
			fill(&dp[row][col][NORTH][0],&dp[row][col][NORTH][MAX_SPEED+2],INF);
			fill(&dp[row][col][EAST][0],&dp[row][col][EAST][MAX_SPEED+2],INF);
			fill(&dp[row][col][SOUTH][0],&dp[row][col][SOUTH][MAX_SPEED+2],INF);
			fill(&dp[row][col][WEST][0],&dp[row][col][WEST][MAX_SPEED+2],INF);
		}
	}
	
	r.row = s_row;
	r.col = s_col;
	r.direction = NORTH;
	r.time = r.speed = 0;;
	
	rq.push(r);
	dp[s_row][s_col][NORTH][0] = 0;
	
	for(ret=INF;!rq.empty();)
	{
		Rover	current,next;
			
		current = rq.front();
		rq.pop();

		if( is_stopped(current.speed)==true && 
			grid[current.row][current.col]==DESTINATION )
		{
			ret = current.time;
			break;
		}
		
		next.time = current.time+1;
		
		// FORWARD
		if( is_stopped(current.speed) == true )
		{
			next.speed = 1;
			next.direction = current.direction;
			
			next.row = current.row+adj[next.direction].d_row*next.speed;
			next.col = current.col+adj[next.direction].d_col*next.speed;
			
			if( is_valid(next,current) == true )
			{
				rq.push(next);
				dp[next.row][next.col][next.direction][SHIFT_SPEED(next.speed)] = next.time;
			}
		}
		
		// BACKWARD
		if( is_stopped(current.speed) == true )
		{
			next.speed = -1;
			next.direction = current.direction;
			
			next.row = current.row+adj[next.direction].d_row*next.speed;
			next.col = current.col+adj[next.direction].d_col*next.speed;
			
			if( is_valid(next,current) == true )
			{
				rq.push(next);
				dp[next.row][next.col][next.direction][SHIFT_SPEED(next.speed)] = next.time;
			}
		}
		
		// FASTER
		if( is_forward(current.speed) == true )
		{
			next.speed = min(current.speed+1,MAX_SPEED);
			next.direction = current.direction;
			
			next.row = current.row+adj[next.direction].d_row*next.speed;
			next.col = current.col+adj[next.direction].d_col*next.speed;
			
			if( is_valid(next,current) == true )
			{
				rq.push(next);
				dp[next.row][next.col][next.direction][SHIFT_SPEED(next.speed)] = next.time;
			}
		}
		
		// SLOWER
		if( is_forward(current.speed) == true )
		{
			next.speed = max(current.speed-1,0);
			next.direction = current.direction;
			
			next.row = current.row+adj[next.direction].d_row*next.speed;
			next.col = current.col+adj[next.direction].d_col*next.speed;
			
			if( is_valid(next,current) == true )
			{
				rq.push(next);
				dp[next.row][next.col][next.direction][SHIFT_SPEED(next.speed)] = next.time;
			}
		}
		
		// STOP
		if( is_stopped(current.speed) == false )
		{
			next.speed = 0;
			next.direction = current.direction;
			
			next.row = current.row;
			next.col = current.col;
			
			if( is_valid(next,current) == true )
			{
				rq.push(next);
				dp[next.row][next.col][next.direction][SHIFT_SPEED(next.speed)] = next.time;
			}
		}
		
		// RIGHT
		if( is_stopped(current.speed) == true )
		{
			next.speed = current.speed;
			next.direction = TURN_RIGHT(current.direction);
			
			next.row = current.row;
			next.col = current.col;
			
			if( is_valid(next,current) == true )
			{
				rq.push(next);
				dp[next.row][next.col][next.direction][SHIFT_SPEED(next.speed)] = next.time;
			}
		}
		
		// LEFT
		if( is_stopped(current.speed) == true )
		{
			next.speed = current.speed;
			next.direction = TURN_LEFT(current.direction);
			
			next.row = current.row;
			next.col = current.col;
			
			if( is_valid(next,current) == true )
			{
				rq.push(next);
				dp[next.row][next.col][next.direction][SHIFT_SPEED(next.speed)] = next.time;
			}
		}
		
		// NOOP
		if( is_stopped(current.speed) == false )
		{
			next.speed = current.speed;
			next.direction = current.direction;
			
			next.row = current.row+adj[next.direction].d_row*next.speed;
			next.col = current.col+adj[next.direction].d_col*next.speed;
			
			if( is_valid(next,current) == true )
			{
				rq.push(next);
				dp[next.row][next.col][next.direction][SHIFT_SPEED(next.speed)] = next.time;
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int	ret;
		
		input();
		ret = find_min_time();
		
		cout<<"Data Set "<<k<<":\n";
		
		if( ret == INF )
		{
			cout<<"Impossible\n\n";
		}
		else
		{
			cout<<ret<<"\n\n";
		}
	}
	
	return	0;
}
