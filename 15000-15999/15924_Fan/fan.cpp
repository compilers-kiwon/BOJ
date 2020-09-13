#include	<iostream>

using namespace	std;

#define	MAX_SIZE			(3000+1)
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	long long int	int64;

int		N,M;
int64	dp[MAX_SIZE][MAX_SIZE];
char	map[MAX_SIZE][MAX_SIZE+1];

void	init(void)
{
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%s",&map[i][1]);
		
		for(int j=1;j<=M;j++)
		{
			dp[i][j] = -1;
		}
	}
	
	dp[1][1] = 1;
}

int64	get_dp(int row,int col)
{
	int64&	ret = dp[row][col];
	
	if( ret != -1 )
	{
		return	ret;
	}
	
	ret = 1;
	
	int	left_adj_row,left_adj_col,up_adj_row,up_adj_col;
	
	left_adj_row = row;
	left_adj_col = col-1;
	
	up_adj_row = row-1;
	up_adj_col = col;
	
	if( IN_RANGE(1,left_adj_row,N) && IN_RANGE(1,left_adj_col,M) )
	{
		if( map[left_adj_row][left_adj_col]=='E' || map[left_adj_row][left_adj_col]=='B' )
		{
			ret += get_dp(left_adj_row,left_adj_col);
		}
	}
	
	if( IN_RANGE(1,up_adj_row,N) && IN_RANGE(1,up_adj_col,M) )
	{
		if( map[up_adj_row][up_adj_col]=='S' || map[up_adj_row][up_adj_col]=='B' )
		{
			ret += get_dp(up_adj_row,up_adj_col);
		}
	}
	
	ret %= 1000000009;
	
	return	ret;
}

int		main(void)
{
	init();
	
	printf("%lld\n",get_dp(N,M));
	
	return	0;
}
