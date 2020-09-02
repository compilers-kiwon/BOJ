#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(30+1)
#define	INF			0x7FFFFFFF

#define	NORTH	0	
#define	EAST	1	
#define	SOUTH	2	
#define	WEST	3	
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{0,1},{1,0},{0,-1}};

#define	STRAIGHT	0
#define	RIGHT		1
#define	BACK		2
#define	LEFT		3
#define	HALT		4

#define	NEXT_DIR(cur,offset)	(((cur)+(offset))%HALT)
#define	IN_RANGE(MIN,n,MAX)		((MIN)<=(n)&&(n)<=(MAX))

#define	START_ROW	1
#define	START_COL	1
#define	START_DIR	EAST

int	w,h,cost[HALT];
int	grid[MAX_SIZE][MAX_SIZE];
int	dp[MAX_SIZE][MAX_SIZE][HALT];

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO
{
	int	row,col,direction,cost;
};

int		move_robot(void)
{
	int				ret;
	State			s;
	queue<State>	state_q;
	
	s.row = START_ROW;
	s.col = START_COL;
	s.direction = START_DIR;
	s.cost = 0;
	
	state_q.push(s);
	ret = INF;
	dp[START_ROW][START_COL][START_DIR] = 0;
	
	for(;!state_q.empty();)
	{
		State	current,next;
		
		current = state_q.front();
		state_q.pop();
		
		if( current.row==h && current.col==w ) 
		{
			ret = min(ret,current.cost);
			continue;
		}
		
		for(int c=STRAIGHT;c<=LEFT;c++)
		{
			next.direction = NEXT_DIR(current.direction,c);
			next.row = current.row+adj[next.direction].d_row;
			next.col = current.col+adj[next.direction].d_col;
			next.cost = current.cost+((c==grid[current.row][current.col])?0:cost[c]);
		
			if( !IN_RANGE(1,next.row,h) || !IN_RANGE(1,next.col,w) )
			{
				continue;
			}
		
			if( next.cost < dp[next.row][next.col][next.direction] )
			{
				dp[next.row][next.col][next.direction] = next.cost;
				state_q.push(next);
			}
		}
	}
	
	return	ret;
}

bool	input(void)
{
	cin>>w>>h;
	
	if( w==0 && h==0 )
	{
		return	false;
	}
	
	for(int row=1;row<=h;row++)
	{
		for(int col=1;col<=w;col++)
		{
			cin>>grid[row][col];
			fill(&dp[row][col][STRAIGHT],&dp[row][col][LEFT+1],INF);
		}
	}
	
	for(int i=STRAIGHT;i<=LEFT;i++)
	{
		cin>>cost[i];
	}
	
	return	true;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		if( input() == false )
		{
			break;
		}
		
		cout<<move_robot()<<'\n';
	}
	
	return	0;
}
