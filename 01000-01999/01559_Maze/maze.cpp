#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE		(100+1)
#define	MAX_TREASURE	8
#define	INF				0x7FFFFFFF
#define	NONE			0

#define	NORTH	0
#define	EAST	1
#define	SOUTH	2
#define	WEST	3
#define	MAX_DIR	4

#define	current_dir(initial,time)	(((initial)+(time))%(MAX_DIR))
#define	IN_RANGE(MIN,n,MAX)			((MIN)<=(n)&&(n)<=(MAX))

const struct{
	int d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{0,1},{1,0},{0,-1}};

int	M,N,K;	// M:row,N:col
int	treasure[MAX_SIZE][MAX_SIZE];
int	grid[MAX_SIZE][MAX_SIZE];
int	dp[MAX_SIZE][MAX_SIZE][1<<MAX_TREASURE];
int	max_treasure;

typedef	pair<int,int>	Pos;	// first:row,second:col
typedef	pair<int,int>	Time;	// first:-time,second:treasure_in_hands
typedef	pair<Time,Pos>	State;

bool	input(void)
{
	cin>>M>>N;
	
	if( M==0 && N ==0 )
	{
		return	false;
	}
	
	for(int row=1;row<=M;row++)
	{
		char	buf[MAX_SIZE+1];
		
		cin>>&buf[1];
		
		for(int col=1;col<=N;col++)
		{
			int& d = grid[row][col];
			
			switch(buf[col])
			{
				case	'N':
					d = NORTH;
					break;
				case	'E':
					d = EAST;
					break;
				case	'S':
					d = SOUTH;
					break;
				case	'W':
					d = WEST;
					break;
				default:
					// do nothing
					break;
			}
		}
	}
	
	cin>>K;
	max_treasure = (1<<K)-1;
	
	for(int row=1;row<=M;row++)
	{
		for(int col=1;col<=N;col++)
		{
			for(int t=0;t<=max_treasure;t++)
			{
				dp[row][col][t] = INF;
			}
			treasure[row][col] = 0;
		}
	}
	
	for(int t=1;t<=K;t++)
	{
		int	row,col;
		
		cin>>row>>col;
		treasure[row][col] = t;
	}
	
	return	true;
}

int		get_shortest_time(void)
{
	priority_queue<State>	pq;
	
	dp[1][1][0] = 0;
	pq.push(make_pair(make_pair(0,0),make_pair(1,1)));
	
	for(;!pq.empty();)
	{
		int	current_time,current_treasure;
		int	current_row,current_col;
		
		current_time = -pq.top().first.first;
		current_treasure = pq.top().first.second;
		current_row = pq.top().second.first;
		current_col = pq.top().second.second;
		
		pq.pop();
		
		if( current_row==M && current_col==N 
			&& current_treasure==max_treasure)
		{
			break;
		}
		
		int	current_room_dir;
		
		current_room_dir = 
			current_dir(grid[current_row][current_col],current_time);
	
		for(int d=0;d<MAX_DIR;d++)
		{
			int	adj_dir,adj_row,adj_col;
			
			adj_dir = current_dir(current_room_dir,d);
			adj_row = current_row+adj[adj_dir].d_row;
			adj_col = current_col+adj[adj_dir].d_col;
			
			if( !IN_RANGE(1,adj_row,M) || !IN_RANGE(1,adj_col,N) )
			{
				continue;
			}
			
			int		adj_treasure,adj_time;
			int&	treasure_idx = treasure[adj_row][adj_col];
			
			if( treasure_idx != NONE )
			{
				adj_treasure = current_treasure|(1<<(treasure_idx-1));
			}
			else
			{
				adj_treasure = current_treasure;
			}
			
			adj_time = current_time+d+1;
			
			if( adj_time < dp[adj_row][adj_col][adj_treasure] )
			{
				dp[adj_row][adj_col][adj_treasure] = adj_time;
				pq.push(make_pair(make_pair(-adj_time,adj_treasure),make_pair(adj_row,adj_col)));
			}
		}		
	}
	
	return	dp[M][N][max_treasure];
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
		
		cout<<get_shortest_time()<<'\n';
	}
	
	return	0;
}
