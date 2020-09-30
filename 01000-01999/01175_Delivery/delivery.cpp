#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(50+1)
#define	INF			0x7FFFFFFF

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	TOTAL_DELIVERY	2

#define	BLOCK		'#'
#define	ENPTY		'.'
#define	MINSIK		'S'
#define	DELIVERY	'C'

typedef	pair<int,int>	Pos;

int		N,M;
bool	visited[MAX_SIZE][MAX_SIZE][TOTAL_DELIVERY][MAX_SIZE][MAX_SIZE][MAX_DIR];
char	grid[MAX_SIZE][MAX_SIZE+1];
Pos		minsik;

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO
{
	int	row,col,num_of_steps;
	int	num_of_delivered;
	int	direction;
	int	last_delivered_row,last_delivered_col;
};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

void	input(void)
{
	cin>>N>>M;
	
	for(int row=1;row<=N;row++)
	{
		cin>>&grid[row][1];
		
		for(int col=1;col<=M;col++)
		{
			if( grid[row][col] == MINSIK )
			{
				minsik = make_pair(row,col);
			}
		}
	}
}

int		bfs(void)
{
	int				ret;
	queue<State>	state_q;
	
	ret = INF;
		
	for(int d=UP;d<=RIGHT;d++)
	{
		State	s;
		
		s.row = minsik.first;
		s.col = minsik.second;
		s.num_of_delivered = 0;
		s.direction = d;
		s.num_of_steps = 0;
		s.last_delivered_row = s.last_delivered_col = 0;
		
		state_q.push(s);
		visited[s.row][s.col][0][0][0][d] = true;
	}
	
	for(;!state_q.empty();)
	{
		State	current,next;
		
		current = state_q.front();
		state_q.pop();

		if( current.num_of_delivered == TOTAL_DELIVERY )
		{
			ret = min(ret,current.num_of_steps);
			continue;
		}
		
		for(int d=UP;d<=RIGHT;d++)
		{
			if( d == current.direction )
			{
				continue;
			}
			
			next.row = current.row+adj[d].d_row;
			next.col = current.col+adj[d].d_col;
			
			next.direction = d;
			next.num_of_steps = current.num_of_steps+1;
			
			if( !IN_RANGE(1,next.row,N) || !IN_RANGE(1,next.col,M) )
			{
				continue;
			}
			
			char&	c = grid[next.row][next.col];
			
			if( c == BLOCK )
			{
				continue;
			}
			else if( c == DELIVERY )
			{
				if( current.num_of_delivered == 0 )
				{
					next.last_delivered_row = next.row;
					next.last_delivered_col = next.col;
					next.num_of_delivered = 1;
				}
				else
				{
					if( next.row!=current.last_delivered_row ||
						next.col!=current.last_delivered_col )
					{
						next.last_delivered_row = next.row;
						next.last_delivered_col = next.col;
						next.num_of_delivered = 2;
					}
					else
					{
						next.last_delivered_row = current.last_delivered_row;
						next.last_delivered_col = current.last_delivered_col;
						next.num_of_delivered = 1;
					}
				}
			}
			else
			{
				next.num_of_delivered = current.num_of_delivered;
				next.last_delivered_row = current.last_delivered_row;
				next.last_delivered_col = current.last_delivered_col;
			}
			
			if( visited[next.row][next.col][next.num_of_delivered]
					[next.last_delivered_row][next.last_delivered_col][next.direction] == true )
			{
				continue;
			}
			
			state_q.push(next);
			visited[next.row][next.col][next.num_of_delivered]
				[next.last_delivered_row][next.last_delivered_col][next.direction] = true;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	int	best;
	
	best = bfs();
	
	if( best == INF )
	{
		cout<<"-1\n";
	}
	else
	{
		cout<<best<<'\n';
	}
	
	return	0;
}
