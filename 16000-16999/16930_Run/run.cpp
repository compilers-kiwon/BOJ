#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	NONE		0

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

typedef	pair<int,int>	Pos;	// first:row,second:col

int		N,M,K,dp[MAX_SIZE][MAX_SIZE];
char	grid[MAX_SIZE][MAX_SIZE+1];
Pos		s,e;

void	input(void)
{
	cin>>N>>M>>K;
	
	for(int row=1;row<=N;row++)
	{
		cin>>&grid[row][1];
	}
	
	cin>>s.first>>s.second>>e.first>>e.second;
}

int		get_shortest_time(void)
{
	int			ret;
	queue<Pos>	pos_q;
	
	dp[s.first][s.second] = 1;
	pos_q.push(s);
	
	ret = -1;
	
	for(;!pos_q.empty();)
	{
		int	current_row,current_col;
		
		current_row = pos_q.front().first;
		current_col = pos_q.front().second;
		
		pos_q.pop();
		
		int&	current_step = dp[current_row][current_col];
		
		if( current_row==e.first && current_col==e.second )
		{
			ret = current_step-1;
			break;
		}
		
		for(int d=UP;d<MAX_DIR;d++)
		{
			int	adj_row,adj_col;
			
			for(int i=1;i<=K;i++)
			{
				adj_row = current_row+adj[d].d_row*i;
				adj_col = current_col+adj[d].d_col*i;
				
				if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
				{
					break;
				}
				
				if( grid[adj_row][adj_col] == '#' )
				{
					break;
				}
				
				if( dp[adj_row][adj_col] == NONE )
				{
					dp[adj_row][adj_col] = current_step+1;
					pos_q.push(make_pair(adj_row,adj_col));
				}
				else
				{
					if( current_step+1 > dp[adj_row][adj_col] )
					{
						break;
					}
				}
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
	cout<<get_shortest_time()<<'\n';

	return	0;
}
