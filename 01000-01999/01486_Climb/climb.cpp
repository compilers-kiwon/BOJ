#include	<iostream>
#include	<string>
#include	<queue>
#include	<cmath>

using namespace	std;

#define	MAX_SIZE	25
#define	INF			0x7FFFFFFF

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<(MAX))

typedef	pair<int,int>	Pos;	// first:row,second:col
typedef	pair<int,Pos>	State;	// first:-time,second:Pos

int	N,M,T,D,grid[MAX_SIZE][MAX_SIZE];
int	dp_to_mountain[MAX_SIZE][MAX_SIZE];

void	input(void)
{
	int	height[0x100],h;
	
	h = 0;
	
	for(char c='A';c<='Z';c++)
	{
		height[c] = h++;
	}
	
	for(char c='a';c<='z';c++)
	{
		height[c] = h++;
	}
	
	cin>>N>>M>>T>>D;
	
	for(int row=0;row<N;row++)
	{
		string	str;
		
		cin>>str;
		
		for(int col=0;col<M;col++)
		{
			grid[row][col] = height[str[col]];
		}
	}
}

void	climb_up(void)
{
	for(int row=0;row<N;row++)
	{
		fill(&dp_to_mountain[row][0],&dp_to_mountain[row][M],INF);
	}
	
	priority_queue<State>	pq;
	
	dp_to_mountain[0][0] = 0;
	pq.push(make_pair(0,make_pair(0,0)));
	
	for(;!pq.empty();)
	{
		int	current_time,current_row,current_col;
		
		current_time = -pq.top().first;
		current_row = pq.top().second.first;
		current_col = pq.top().second.second;
		
		pq.pop();
		
		int&	current_height = grid[current_row][current_col];
		
		for(int d=UP;d<MAX_DIR;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( !IN_RANGE(0,adj_row,N) || !IN_RANGE(0,adj_col,M) )
			{
				continue;
			}
			
			int&	adj_height = grid[adj_row][adj_col];
			int		diff,t;
			
			diff = abs(adj_height-current_height);
			
			if( diff > T )
			{
				continue;
			}
			
			if( adj_height <= current_height )
			{
				t = 1;
			}
			else
			{
				t = diff*diff;
			}
			
			if( current_time+t < dp_to_mountain[adj_row][adj_col] )
			{
				dp_to_mountain[adj_row][adj_col] = current_time+t;
				pq.push(make_pair(-(current_time+t),make_pair(adj_row,adj_col)));
			}
			
		}
	}
}

int		climb_down(int s_row,int s_col)
{
	priority_queue<State>	pq;
	int						dp[MAX_SIZE][MAX_SIZE];
	
	for(int row=0;row<N;row++)
	{
		fill(&dp[row][0],&dp[row][M],INF);
	}
	
	dp[s_row][s_col] = 0;
	pq.push(make_pair(0,make_pair(s_row,s_col)));
	
	for(;!pq.empty();)
	{
		int	current_time,current_row,current_col;
		
		current_time = -pq.top().first;
		current_row = pq.top().second.first;
		current_col = pq.top().second.second;
		
		pq.pop();
		
		if( current_row==0 && current_col==0 )
		{
			break;
		}
		
		int&	current_height = grid[current_row][current_col];
		
		for(int d=UP;d<MAX_DIR;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( !IN_RANGE(0,adj_row,N) || !IN_RANGE(0,adj_col,M) )
			{
				continue;
			}
			
			int&	adj_height = grid[adj_row][adj_col];
			int		diff,t;
			
			diff = abs(adj_height-current_height);
			
			if( diff > T )
			{
				continue;
			}
			
			if( adj_height <= current_height )
			{
				t = 1;
			}
			else
			{
				t = diff*diff;
			}
			
			if( current_time+t < dp[adj_row][adj_col] )
			{
				dp[adj_row][adj_col] = current_time+t;
				pq.push(make_pair(-(current_time+t),make_pair(adj_row,adj_col)));
			}
		}
	}
	
	return	dp[0][0];
}

int		main(void)
{
	input();
	climb_up();
	
	int	max_height;
	
	max_height = 0;
	
	for(int row=0;row<N;row++)
	{
		for(int col=0;col<M;col++)
		{
			int		time_to_climb_down;
			int&	time_to_climb_up = dp_to_mountain[row][col];
			
			time_to_climb_down = climb_down(row,col);
			
			if( time_to_climb_up!=INF && time_to_climb_down!=INF )
			{
				if( time_to_climb_up+time_to_climb_down <= D )
				{
					max_height = max(max_height,grid[row][col]);
				}
			}
		}
	}
	
	cout<<max_height<<'\n';
	
	return	0;
}
