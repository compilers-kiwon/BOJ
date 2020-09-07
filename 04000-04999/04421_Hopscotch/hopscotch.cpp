#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(100+1)

#define	TRUE	1
#define	FALSE	0
#define	UNKNOWN	-1

int	n,k,grid[MAX_SIZE][MAX_SIZE];
int	dp[MAX_SIZE][MAX_SIZE];
int	possible_path[MAX_SIZE][MAX_SIZE];

typedef	pair<int,int>	Pos;
typedef	pair<int,Pos>	State;

void	input(priority_queue<State>& pq)
{
	cin>>n>>k;
	
	for(int row=1;row<=n;row++)
	{
		for(int col=1;col<=n;col++)
		{
			cin>>grid[row][col];
			dp[row][col] = possible_path[row][col] = UNKNOWN;
			pq.push(make_pair(grid[row][col],make_pair(row,col)));
		}
	}
}

int		find_possible_path(int row,int col)
{
	int&	ret = possible_path[row][col];
	
	if( ret != UNKNOWN )
	{
		return	ret;
	}
	
	ret = FALSE;
	
	for(int prev_row=max(1,row-k);prev_row<=min(n,row+k)&&ret==FALSE;prev_row++)
	{
		if( grid[prev_row][col] < grid[row][col] )
		{
			ret = find_possible_path(prev_row,col);
		}
	}
	
	for(int prev_col=max(1,col-k);prev_col<=min(n,col+k)&&ret==FALSE;prev_col++)
	{
		if( grid[row][prev_col] < grid[row][col] )
		{
			ret = find_possible_path(row,prev_col);
		}
	}
	
	return	ret;
}

int		get_dp(int row,int col)
{
	int&	ret = dp[row][col];
	int		max_prev_pennies;
	
	if( ret != UNKNOWN )
	{
		return	ret;
	}
	
	max_prev_pennies = 0;
	
	for(int prev_row=max(1,row-k);prev_row<=min(n,row+k);prev_row++)
	{
		if( grid[prev_row][col]<grid[row][col] && possible_path[prev_row][col]==TRUE )
		{
			max_prev_pennies = max(max_prev_pennies,get_dp(prev_row,col));
		}
	}
	
	for(int prev_col=max(1,col-k);prev_col<=min(n,col+k);prev_col++)
	{
		if( grid[row][prev_col]<grid[row][col] && possible_path[row][prev_col]==TRUE )
		{
			max_prev_pennies = max(max_prev_pennies,get_dp(row,prev_col));
		}
	}
	
	ret = max_prev_pennies+grid[row][col];
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	priority_queue<State>	pq;
	
	input(pq);
	possible_path[1][1] = TRUE;
	
	for(int row=1;row<=n;row++)
	{
		for(int col=1;col<=n;col++)
		{
			find_possible_path(row,col);
		}
	}
	
	int	max_pennies;
	
	max_pennies = 0;
	dp[1][1] = grid[1][1];
	
	for(;!pq.empty();pq.pop())
	{
		int	row,col;
		
		row = pq.top().second.first;
		col = pq.top().second.second;
		
		if( possible_path[row][col] == TRUE )
		{
			max_pennies = max(max_pennies,get_dp(row,col));
		}
	}
	
	cout<<max_pennies<<'\n';
	
	return	0;
}
