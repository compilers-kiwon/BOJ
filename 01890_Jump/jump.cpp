#include	<cstdio>

using namespace	std;

typedef	unsigned long long int64;

#define	MAX_SIZE	(100+1)

int		map[MAX_SIZE][MAX_SIZE];
int64	dp[MAX_SIZE][MAX_SIZE];

int64	jump_back(int row,int col)
{
	if( dp[row][col] != -1 )
	{
		return	dp[row][col];
	}
	
	int64	result;
	
	result = 0;
	
	// row
	for(int i=1;i<=9;i++)
	{
		int	next_row;
		
		next_row = row-i;
		
		if( next_row < 1 )
		{
			break;
		}
		
		if( map[next_row][col] == i )
		{
			result += jump_back(next_row,col);
		}
	}
	
	// col
	for(int i=1;i<=9;i++)
	{
		int	next_col;
		
		next_col = col-i;
		
		if( next_col < 1 )
		{
			break;
		}
		
		if( map[row][next_col] == i )
		{
			result += jump_back(row,next_col);
		}
	}
	
	dp[row][col] = result;
	
	return	result;
}

int		main(void)
{
	int	N;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			scanf("%d",&map[i][j]);
			dp[i][j] = -1;
		}
	}
	
	dp[1][1] = 1;
	printf("%lld\n",jump_back(N,N));
	
	return	0;
}
