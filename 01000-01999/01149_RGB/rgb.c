#include <stdio.h>

#define MIN(a,b) ((a)<(b)?(a):(b))

#define MAX_SIZE (1000+1)

#define RED 0
#define GREEN 1
#define BLUE 2
#define MAX_COLOR 3

int main(void)
{
	int table[MAX_SIZE][MAX_COLOR];
	int dp[MAX_SIZE][MAX_COLOR];
	int N,i;
	
	scanf("%d",&N);
	
	for(i=1;i<=N;i++)
	{
		scanf("%d %d %d",&table[i][RED],&table[i][GREEN],&table[i][BLUE]);
	}
	
	dp[0][RED] = dp[0][GREEN] = dp[0][BLUE] = 0;
	
	for(i=1;i<=N;i++)
	{
		dp[i][RED] = MIN(dp[i-1][GREEN],dp[i-1][BLUE])+table[i][RED];
		dp[i][GREEN] = MIN(dp[i-1][RED],dp[i-1][BLUE])+table[i][GREEN];
		dp[i][BLUE] = MIN(dp[i-1][GREEN],dp[i-1][RED])+table[i][BLUE];
	}
	
	printf("%d\n",MIN(dp[N][RED],MIN(dp[N][GREEN],dp[N][BLUE])));
	
	return 0;
}
