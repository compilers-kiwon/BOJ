#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(100+1)
#define	MAX_STEP	3

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int	N,T,grass[MAX_SIZE][MAX_SIZE],dp[MAX_SIZE][MAX_SIZE][MAX_STEP+1];

typedef	struct	_COW_INFO	Cow;
struct	_COW_INFO
{
	int	row,col,step;
};

typedef	pair<int,Cow>	State;	// first:-time, second:cow info	

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N>>T;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cin>>grass[i][j];
			dp[i][j][1] = dp[i][j][2] = dp[i][j][3] = 0x7FFFFFFF;
		}
	}
}

int		move(void)
{
	queue<State>	state_q;
	Cow				c;
	int				min_time;
	
	c.row = c.col = 1;
	c.step = 0;
	
	state_q.push(make_pair(0,c));
	dp[1][1][1] = dp[1][1][2] = dp[1][1][3] = 0;
	
	min_time = 0x7FFFFFFF;
	
	while( !state_q.empty() )
	{
		int	current_time,current_row,current_col,current_step;
		
		current_time = state_q.front().first;
		current_row = state_q.front().second.row;
		current_col = state_q.front().second.col;
		current_step = state_q.front().second.step;
		
		state_q.pop();
		
		if( current_row==N && current_col==N )
		{
			min_time = min(min_time,current_time+((current_step==MAX_STEP)?grass[N][N]:0));
			continue;
		}
		
		int	next_time,next_row,next_col,next_step;
		
		if( current_step == 3 )
		{
			next_time = current_time+grass[current_row][current_col]+T;
			next_step = 1;
		}
		else
		{
			next_time = current_time+T;
			next_step = current_step+1;
		}
		
		for(int d=UP;d<=RIGHT;d++)
		{
			next_row = current_row+adj[d].d_row;
			next_col = current_col+adj[d].d_col;
			
			if( IN_RANGE(1,next_row,N) && IN_RANGE(1,next_col,N) )
			{
				if( next_time < dp[next_row][next_col][next_step] )
				{
					c.row = next_row;
					c.col = next_col;
					c.step = next_step;
					
					dp[next_row][next_col][next_step] = next_time;
					state_q.push(make_pair(next_time,c));					
				}
			}
		}
	}
	
	return	min_time;
}

int		main(void)
{
	init();
	cout<<move()<<'\n';

	return	0;
}
