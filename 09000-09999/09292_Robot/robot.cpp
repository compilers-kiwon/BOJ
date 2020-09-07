#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(20+1)
#define	MAX_BATTERY	(30+1)
#define	INF			0x7FFFFFFF

#define	UP		0
#define	RIGHT	1
#define	DOWN	2
#define	LEFT	3
#define	MAX_DIR	4

#define	NEXT_DIR(d)	(((d)+1)%MAX_DIR)

#define	POWER	'p'
#define	WALL	'x'
#define	EMPTY	'-'
#define	MESS	'm'
#define	ROBOT	'r'

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{0,1},{1,0},{0,-1}};

typedef	pair<int,int>	Pos;

typedef	struct	_ROBOT_INFO	Robot;
struct	_ROBOT_INFO
{
	int	row,col,steps,direction,battery;
};

char	room[MAX_SIZE][MAX_SIZE+1];

bool	is_adj_power_outlet(int row,int col)
{
	bool	ret;
	
	ret = false;
	
	for(int d=UP;d<=LEFT&&ret!=true;d++)
	{
		int	adj_row,adj_col;
		
		adj_row = row+adj[d].d_row;
		adj_col = col+adj[d].d_col;
		
		if( room[adj_row][adj_col] == POWER )
		{
			ret = true;
		}
	}

	return	ret;
}

int		move(Robot& r,Pos& mess,int row_size,int col_size,int full_battery)
{
	bool	visited[row_size+1][col_size+1][r.battery+1][MAX_DIR];
	int		min_steps;
	
	for(int row=1;row<=row_size;row++)
	{
		for(int col=1;col<=col_size;col++)
		{
			for(int b=0;b<=full_battery;b++)
			{
				visited[row][col][b][UP] = visited[row][col][b][RIGHT] =
				visited[row][col][b][DOWN] = visited[row][col][b][LEFT] = false;
			}
		}
	}
	
	visited[r.row][r.col][r.battery][r.direction] = true;
		
	for(min_steps=INF;;)
	{
		if( r.row==mess.first && r.col==mess.second )
		{
			min_steps = r.steps;
			break;
		}
		
		// 1. need to charge ?
		if( r.battery<=full_battery/2 && 
			is_adj_power_outlet(r.row,r.col)==true )
		{
			r.steps += full_battery-r.battery;
			r.battery = full_battery;
		}
		
		if( r.battery == 0 )
		{
			break;
		}
		
		// 2. go ahead
		int	prev_row,prev_col;
		
		prev_row = r.row;
		prev_col = r.col;
		
		r.row = r.row+adj[r.direction].d_row;
		r.col = r.col+adj[r.direction].d_col;
		r.steps = r.steps+1;
		r.battery = r.battery-1;
		
		if( room[r.row][r.col] != EMPTY )
		{
			r.row = prev_row;
			r.col = prev_col;
			r.direction = NEXT_DIR(r.direction);
		}
		
		if( visited[r.row][r.col][r.battery][r.direction] == true )
		{
			break;
		}
		
		visited[r.row][r.col][r.battery][r.direction] = true;
	}
	
	return	min_steps;
}

int		main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	for(int t=1;t<=T;t++)
	{
		int		n,d;
		Pos		robot,mess;
		
		scanf("%d %d",&n,&d);
		
		for(int row=1;row<=n;row++)
		{
			scanf("%s",&room[row][1]);
			
			for(int col=1;col<=n;col++)
			{
				if( room[row][col] == ROBOT )
				{
					robot.first = row;
					robot.second = col;
					room[row][col] = EMPTY;
				}
				
				if( room[row][col] == MESS )
				{
					mess.first = row;
					mess.second = col;
					room[row][col] = EMPTY;
				}
			}
		}

		Robot	initial;
		int		min_steps;
		
		initial.row = robot.first;
		initial.col = robot.second;
		initial.direction = RIGHT;
		initial.steps = 0;
		initial.battery = d;
		
		min_steps = move(initial,mess,n,n,d);
		
		printf("Case %d: ",t);
		
		if( min_steps == INF )
		{
			cout<<"NEVER\n";
		}
		else
		{
			cout<<min_steps<<'\n';
		}
	}
	
	return	0;
}
