#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(2222+1)

#define	DOWN	0
#define	RIGHT	1
#define	MAX_DIR	2

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{1,0},{0,1}};

int	n,A[MAX_SIZE][MAX_SIZE];

typedef	pair<int,int>		RowCol;
typedef	pair<int,RowCol>	State;	// first:-cost, second:(row,col)

int	escape(void)
{
	vector<int>				dp[n+1];
	priority_queue<State>	state_q;
	int						min_cost;
	
	for(int i=1;i<=n;i++)
	{
		dp[i].resize(n+1,0x7FFFFFFF);
	}
	
	dp[1][1] = 0;
	state_q.push(make_pair(0,make_pair(1,1)));
	min_cost = 0x7FFFFFFF;
	
	while( !state_q.empty() )
	{
		int	current_row,current_col,current_cost;
		
		current_row = state_q.top().second.first;
		current_col = state_q.top().second.second;
		current_cost = -state_q.top().first;
		
		state_q.pop();
		
		if( current_row==n && current_col==n )
		{
			min_cost = current_cost;
			break;
		}
		
		for(int d=DOWN;d<=RIGHT;d++)
		{
			int	next_row,next_col,next_cost;
			
			next_row = current_row+adj[d].d_row;
			next_col = current_col+adj[d].d_col;
			
			if( IN_RANGE(1,next_row,n) && IN_RANGE(1,next_col,n) )
			{
				if( A[current_row][current_col] > A[next_row][next_col] )
				{
					next_cost = current_cost;
				}
				else
				{
					next_cost = current_cost+(A[next_row][next_col]-A[current_row][current_col]+1);
				}
				
				if( next_cost < dp[next_row][next_col] )
				{
					dp[next_row][next_col] = next_cost;					
					state_q.push(make_pair(-next_cost,make_pair(next_row,next_col)));
				}
			}
		}
	}
	
	return	min_cost;
}

int	main(void)
{
	cin.sync_with_stdio(false);
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>A[i][j];
		}
	}
	
	cout<<escape()<<'\n';
	
	return	0;
}
