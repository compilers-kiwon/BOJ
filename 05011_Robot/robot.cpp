#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	TBD			-1
#define	MOD(n)		((n)%0x7FFFFFFF)

typedef	long long int	int64;
typedef	pair<int,int>	Pos;	// first:row,second:col

int		n;
int64	dp[MAX_SIZE][MAX_SIZE];
char	grid[MAX_SIZE][MAX_SIZE+1];

#define	UP		0
#define	LEFT	1
#define	DOWN	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{0,-1},{1,0},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

void	input(void)
{
	cin>>n;
	
	for(int row=1;row<=n;row++)
	{
		cin>>&grid[row][1];
		
		for(int col=1;col<=n;col++)
		{
			if( grid[row][col] == '.' )
			{
				dp[row][col] = TBD;
			}
		}
	}
}

int64	get_dp(const int& row,const int& col)
{
	int64&	ret = dp[row][col];
	
	if( ret != TBD )
	{
		return	ret;
	}
	
	ret = 0;
	
	for(int d=UP;d<=LEFT;d++)
	{
		int	adj_row,adj_col;
		
		adj_row = row+adj[d].d_row;
		adj_col = col+adj[d].d_col;
		
		if( !IN_RANGE(1,adj_row,n) || !IN_RANGE(1,adj_col,n) )
		{
			continue;
		}
		
		ret = MOD(ret+get_dp(adj_row,adj_col));
	}
	
	return	ret;
}

bool	bfs(void)
{
	queue<Pos>	pos_q;
	
	grid[1][1] = '#';
	pos_q.push(make_pair(1,1));
	
	for(;!pos_q.empty();)
	{
		int	current_row,current_col;
		
		current_row = pos_q.front().first;
		current_col = pos_q.front().second;
		
		pos_q.pop();
		
		if( current_row==n && current_col==n )
		{
			return	true;
		}
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( !IN_RANGE(1,adj_row,n) || !IN_RANGE(1,adj_col,n) )
			{
				continue;
			}
			
			if( grid[adj_row][adj_col] == '.' )
			{
				grid[adj_row][adj_col] = '#';
				pos_q.push(make_pair(adj_row,adj_col));
			}
		}
	}
	
	return	false;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	dp[1][1] = 1;
	
	int64	num_of_paths;
	
	num_of_paths = get_dp(n,n);
	
	if( num_of_paths != 0 )
	{
		cout<<num_of_paths<<'\n';
	}
	else
	{
		if( bfs() == true )
		{
			cout<<"THE GAME IS A LIE\n";
		}
		else
		{
			cout<<"INCONCEIVABLE\n";
		}
	}
	
	return	0;
}
