#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE			(1000+1)
#define	MAX_BROKEN_BLOCKS	(100+1)

#define	INF	0x7FFFFFFF

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	EMPTY	'0'
#define	BLOCK	'1'

#define	DAY				0
#define	NIGHT			1
#define	NEXT_TIME(t)	(((t)==DAY)?NIGHT:DAY)

int		N,M,K,dp[MAX_SIZE][MAX_SIZE][MAX_BROKEN_BLOCKS];
char	grid[MAX_SIZE][MAX_SIZE+1];

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO
{
	int	row,col,num_of_visited;
	int	time,num_of_broken_blocks;
};

int		simulate(void)
{
	queue<State>	state_q;
	State			s;
	
	s.row=1;s.col=1;s.num_of_visited=1;
	s.time = DAY;s.num_of_broken_blocks=0;
	
	for(int broken=0;broken<=K;broken++)
	{
		dp[1][1][broken] = 1;
	}
	
	state_q.push(s);
	
	for(;!state_q.empty();)
	{
		State	current,next;
		
		current = state_q.front();
		state_q.pop();
		
		if( current.row==N && current.col==M )
		{
			continue;
		}
		
		for(int d=UP;d<=RIGHT;d++)
		{
			next.row = current.row+adj[d].d_row;
			next.col = current.col+adj[d].d_col;
			
			if( !IN_RANGE(1,next.row,N) || !IN_RANGE(1,next.col,M) )
			{
				continue;
			}
			
			next.num_of_visited = current.num_of_visited+1;
			next.num_of_broken_blocks = current.num_of_broken_blocks;
			next.time = NEXT_TIME(current.time);
			
			if( grid[next.row][next.col] == BLOCK )
			{
				next.num_of_broken_blocks = current.num_of_broken_blocks+1;
				
				if( next.time != NIGHT )
				{
					next.time = NIGHT;
					next.num_of_visited++;
				}
			}
			
			if( next.num_of_broken_blocks > K )
			{
				continue;
			}
			
			if( next.num_of_visited < dp[next.row][next.col][next.num_of_broken_blocks]) 
			{
				dp[next.row][next.col][next.num_of_broken_blocks] = next.num_of_visited;
				state_q.push(next);
			}
		}
	}
	
	int	ret = INF;
	
	for(int i=0;i<=K;i++)
	{
		ret = min(ret,dp[N][M][i]);
	}
	
	return	((ret==INF)?-1:ret);
}

int		main(void)
{
	cin>>N>>M>>K;
	
	for(int row=1;row<=N;row++)
	{
		cin>>&grid[row][1];
		
		for(int col=1;col<=M;col++)
		{
			fill(&dp[row][col][0],&dp[row][col][K+1],INF);
		}
	}
	
	cout<<simulate()<<'\n';
	
	return	0;
}
