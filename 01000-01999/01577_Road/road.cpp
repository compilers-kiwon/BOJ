#include	<iostream>

using namespace	std;

typedef	long long int	int64;

#define	MAX_SIZE	(100+1)

#define	BLOCKED		0
#define	NOT_BLOCKED	1

#define	GET_ROW_STATE(s)	((s).first)
#define	GET_COL_STATE(s)	((s).second)

typedef	pair<int64,int64>	State;

State	map[MAX_SIZE+1][MAX_SIZE+1];
int64	dp[MAX_SIZE+1][MAX_SIZE+1];
int		N,M,K;

int64	get_dp(int row,int col)
{
	if( dp[row][col] == -1 )
	{
		dp[row][col] = 0;
		
		if( GET_ROW_STATE(map[row][col]) == NOT_BLOCKED )
		{
			dp[row][col] += get_dp(row-1,col);
		}
		
		if( GET_COL_STATE(map[row][col]) == NOT_BLOCKED )
		{
			dp[row][col] += get_dp(row,col-1);
		}				
	}
	return	dp[row][col];
}

void	init_dp(void)
{
	cin>>N>>M>>K;
	
	for(int row=0;row<=M;row++)
	{
		for(int col=0;col<=N;col++)
		{
			dp[row][col] = -1;
			map[row][col] = make_pair(NOT_BLOCKED,NOT_BLOCKED);
		}
	}
	
	for(int col=0;col<=N;col++)
	{
		map[0][col].first = BLOCKED;
	}
	
	for(int row=0;row<=M;row++)
	{
		map[row][0].second = BLOCKED;
	}
	
	for(int i=1;i<=K;i++)
	{
		int	x1,y1,x2,y2;
		
		cin>>x1>>y1>>x2>>y2;
		
		if( x1 != x2 )
		{
			map[y1][max(x1,x2)].second = BLOCKED;
		}
		else
		{
			map[max(y1,y2)][x1].first = BLOCKED;
		}
	}
	
	dp[0][0] = 1;
}

int		main(void)
{
	init_dp();
	cout<<get_dp(M,N)<<endl;
	
	return	0;
}
