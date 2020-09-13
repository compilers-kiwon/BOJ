#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(200+1)
#define	MOD(n)		((n)%1000000007)

int		N,M,dp[MAX_SIZE][MAX_SIZE];
char	map[MAX_SIZE][MAX_SIZE+1];

void	init(void)
{
	scanf("%d %d",&N,&M);
	
	for(int row=1;row<=N;row++)
	{
		scanf("%s",&map[row][1]);
		
		for(int col=1;col<=M;col++)
		{
			if( map[row][col] == '.' )
			{
				dp[row][col] = -1;
			}
		}
	}
	
	dp[1][1] = 1;
}

int		get_dp(int row,int col)
{
	int&	ret = dp[row][col];
	
	if( ret != -1 )
	{
		return	ret;
	}
	
	ret = MOD(get_dp(row-1,col)+get_dp(row,col-1));
	
	return	ret;
}

int		main(void)
{
	init();
	printf("%d\n",get_dp(N,M));
	
	return	0;
}
