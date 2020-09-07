#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE			(30+1)
#define	MAX_JUMP_DISTANCE	5
#define	INF					0x7FFFFFFF

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

typedef	pair<int,int>		Pos;		// first:row,second:col
typedef	pair<int,Pos>		Kangaroo;	// first:direction,second:Pos
typedef	pair<int,Kangaroo>	State;		// first:-time,second:Kangaroo

int		h,w,dp[MAX_SIZE][MAX_SIZE][MAX_DIR];
char	grid[MAX_SIZE][MAX_SIZE+1];
Pos		k_pos,g_pos;

void	input(void)
{
	cin>>h>>w;
	
	for(int row=1;row<=h;row++)
	{
		cin>>&grid[row][1];
		
		for(int col=1;col<=w;col++)
		{
			switch(grid[row][col])
			{
				case	'K':
					k_pos = make_pair(row,col);
					break;
				case	'G':
					g_pos = make_pair(row,col);
					break;
				default:
					// do nothing
					break;
			}
		}
	}
}

void	init_dp(void)
{
	for(int row=1;row<=h;row++)
	{
		for(int col=1;col<=w;col++)
		{
			fill(&dp[row][col][0],&dp[row][col][MAX_DIR],INF);
		}
	}
}

void	init_pq(priority_queue<State>& pq)
{
	for(int i=0;i<MAX_DIR;i++)
	{
		State	s;
		int&	current_time = s.first;
		int&	current_direction = s.second.first;
		int&	current_row = s.second.second.first;
		int&	current_col = s.second.second.second;
		
		current_time = 0;
		current_direction = i;
		current_row = k_pos.first;
		current_col = k_pos.second;
		
		pq.push(s);
		dp[current_row][current_col][current_direction] = 0;
	}
}

int		get_min_arrival_time(void)
{
	priority_queue<State>	pq;
	
	init_dp();
	init_pq(pq);
	
	for(;!pq.empty();)
	{
		int	current_time;
		int	current_direction;
		int	current_row;
		int	current_col;
		
		current_time = -pq.top().first;
		current_direction = pq.top().second.first;
		current_row = pq.top().second.second.first;
		current_col = pq.top().second.second.second;
		
		pq.pop();
		
		if( current_row==g_pos.first && current_col==g_pos.second )
		{
			return	current_time;
		}
		
		State	next;
		int&	next_time = next.first;
		int&	next_direction = next.second.first;
		int&	next_row = next.second.second.first;
		int&	next_col = next.second.second.second;
		
		// 1. change direction
		for(int offset=1;offset<MAX_DIR;offset++)
		{
			next_time = current_time+1;
			next_direction = (current_direction+offset)%MAX_DIR;
			next_row = current_row;
			next_col = current_col;
			
			if( next_time < dp[next_row][next_col][next_direction] )
			{
				dp[next_row][next_col][next_direction] = next_time;
				
				next_time *= -1;
				pq.push(next);
			}
		}
		
		// 2. jump
		for(int d=1;d<=MAX_JUMP_DISTANCE;d++)
		{
			next_row = current_row+adj[current_direction].d_row*d;
			next_col = current_col+adj[current_direction].d_col*d;
			
			if( !IN_RANGE(1,next_row,h) || !IN_RANGE(1,next_col,w) )
			{
				break;
			}
			
			if( grid[next_row][next_col] == '.' )
			{
				continue;
			}
			
			next_time = current_time+1;
			next_direction = current_direction;
			
			if( grid[next_row][next_col] != 'G' )
			{
				next_time += (d-1)*(d-1);
			}
			
			if( next_time < dp[next_row][next_col][next_direction] )
			{
				dp[next_row][next_col][next_direction] = next_time;
				
				next_time *= -1;
				pq.push(next);
			}
		}
	}
	
	return	INF;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int	min_time;
		
		input();
		min_time = get_min_arrival_time();
		
		cout<<"Data Set "<<k<<":\n";
		
		if( min_time == INF )
		{
			cout<<"Impossible\n\n";
		}
		else
		{
			cout<<min_time<<"\n\n";
		}
	}
	
	return	0;
}
