#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(100+1)
#define	INF			0x7FFFFFFF
#define	MAX_PTR		2

#define	UP		0
#define	LEFT	1
#define	DOWN	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	adj_input_dir(d)	(((d)+2)%MAX_DIR)
#define	in_range(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	struct	_POS_INFO	Pos;
struct	_POS_INFO
{
	int	row,col;
};

const Pos	adj_offset[MAX_DIR] = {{-1,0},{0,-1},{1,0},{0,1}};
const int	out_dir[MAX_DIR][MAX_DIR-1] = {{DOWN,LEFT,RIGHT},{UP,RIGHT,DOWN},
										   {LEFT,UP,RIGHT},{UP,LEFT,DOWN}};

int		W,H,dp[MAX_SIZE][MAX_SIZE][MAX_DIR];
Pos		c[MAX_PTR];
char	grid[MAX_SIZE][MAX_SIZE+1];

#define	EMPTY	'.'
#define	BLOCK	'*'
#define	LASER	'C'

typedef	struct	_LASER_INFO	Laser;
struct	_LASER_INFO
{
	int	row,col,input_dir,num_of_mirror;
};

void	input(void)
{
	int	ptr;
	
	cin>>W>>H;
	ptr = 0;
	
	for(int row=1;row<=H;row++)
	{
		cin>>&grid[row][1];
		
		for(int col=1;col<=W;col++)
		{
			if( grid[row][col] == LASER )
			{
				c[ptr].row = row;
				c[ptr].col = col;
				
				ptr++;
				grid[row][col] = EMPTY;
			}
			
			fill(&dp[row][col][0],&dp[row][col][MAX_DIR],INF);
		}
	}
}

void	init(queue<Laser>&	laser_q)
{
	for(int i=UP;i<=RIGHT;i++)
	{
		Laser	l;
		
		l.row = c[0].row;
		l.col = c[0].col;
		l.num_of_mirror = 0;
		l.input_dir = i;
		
		laser_q.push(l);
		dp[l.row][l.col][i] = 0;
	}
}

int		install_mirror(void)
{
	int				ret;
	queue<Laser>	q;
	int&			dst_row = c[1].row;
	int&			dst_col = c[1].col;
	
	init(q);
	ret = INF;
	
	for(;!q.empty();)
	{
		Laser	current;
		
		current = q.front();
		q.pop();
		
		if( current.row==dst_row && current.col==dst_col )
		{
			ret = min(ret,current.num_of_mirror);
			continue;
		}
		
		for(int d=0;d<MAX_DIR-1;d++)
		{
			Laser		adj;
			const int&	out = out_dir[current.input_dir][d];
			
			int&		adj_row = adj.row;
			int&		adj_col = adj.col;
			int&		adj_mirror = adj.num_of_mirror;
			int&		adj_input_dir = adj.input_dir;
			
			adj_row = current.row+adj_offset[out].row;
			adj_col = current.col+adj_offset[out].col;
			
			if( !in_range(1,adj_row,H) || !in_range(1,adj_col,W) )
			{
				continue;	
			}
			
			adj_input_dir = adj_input_dir(out);
			adj_mirror = current.num_of_mirror+((current.input_dir==adj_input_dir)?0:1);
			
			if( grid[adj_row][adj_col]!=BLOCK 
				&& adj_mirror<dp[adj_row][adj_col][adj_input_dir] )
			{
				q.push(adj);
				dp[adj_row][adj_col][adj_input_dir] = adj_mirror;
			}		
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<install_mirror()<<'\n';

	return	0;
}
