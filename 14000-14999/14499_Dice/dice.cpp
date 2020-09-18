#include	<iostream>

using namespace	std;

#define	MAX_SIZE	20
#define	MAX_SIDE	6
#define	MAX_COMMAND	1000

#define	TOP		1
#define	UP		2
#define	RIGHT	3
#define	LEFT	4
#define	DOWN	5
#define	BOTTOM	6

int	N,M,K,current_status;
int	x,y;
int	grid[MAX_SIZE][MAX_SIZE];
int	dice[MAX_COMMAND+1][MAX_SIDE+1];

#define	EAST	1
#define	WEST	2
#define	NORTH	3
#define	SOUTH	4
#define	MAX_DIR	5

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{},{0,1},{0,-1},{-1,0},{1,0}};

const int	change_of_dice[MAX_DIR][MAX_SIDE+1] = {
	{},
	{0,RIGHT,UP,BOTTOM,TOP,DOWN,LEFT},	// EAST
	{0,LEFT,UP,TOP,BOTTOM,DOWN,RIGHT},	// WEST
	{0,UP,BOTTOM,RIGHT,LEFT,TOP,DOWN},	// NORTH
	{0,DOWN,TOP,RIGHT,LEFT,BOTTOM,UP}	// SOUTH
};

void	move(int move_dir)
{
	for(int i=1;i<=MAX_SIDE;i++)
	{
		int&		current_number = dice[current_status][i];
		const int&	next_side = change_of_dice[move_dir][i];
		
		dice[current_status+1][next_side] = current_number;
	}
	
	current_status++;
	
	if( grid[y][x] == 0 )
	{
		grid[y][x] = dice[current_status][BOTTOM];
	}
	else
	{
		dice[current_status][BOTTOM] = grid[y][x];
		grid[y][x] = 0;
	}
}

void	input(void)
{
	cin>>N>>M>>y>>x>>K;
	
	for(int row=0;row<N;row++)
	{
		for(int col=0;col<M;col++)
		{
			cin>>grid[row][col];
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	for(int i=1;i<=K;i++)
	{
		int	adj_y,adj_x,d;
		
		cin>>d;
		adj_y = y+adj[d].d_row;
		adj_x = x+adj[d].d_col;
		
		if( !IN_RANGE(0,adj_y,N-1) || !IN_RANGE(0,adj_x,M-1) )
		{
			continue;
		}
		
		y = adj_y;
		x = adj_x;
		
		move(d);
		cout<<dice[current_status][TOP]<<'\n';
	}
	
	return	0;
}
