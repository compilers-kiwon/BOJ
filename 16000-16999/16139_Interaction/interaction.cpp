#include	<iostream>
#include	<cstring>

using namespace	std;

#define	GET_INDEX(c)	((int)((c)-'a'))
#define	MAX_LEN			200000
#define	MAX_TABLE_SIZE	26

int		dp[MAX_TABLE_SIZE][MAX_LEN];
char	S[MAX_LEN+1];

int		main(void)
{
	int	q,len;
	
	scanf("%s %d",S,&q);
	
	len = strlen(S);
	dp[GET_INDEX(S[0])][0] = 1;
	
	for(int i=1;i<len;i++)
	{
		dp[0][i] = dp[0][i-1];
		dp[1][i] = dp[1][i-1];
		dp[2][i] = dp[2][i-1];
		dp[3][i] = dp[3][i-1];
		dp[4][i] = dp[4][i-1];
		dp[5][i] = dp[5][i-1];
		dp[6][i] = dp[6][i-1];
		dp[7][i] = dp[7][i-1];
		dp[8][i] = dp[8][i-1];
		dp[9][i] = dp[9][i-1];
		dp[10][i] = dp[10][i-1];
		dp[11][i] = dp[11][i-1];
		dp[12][i] = dp[12][i-1];
		dp[13][i] = dp[13][i-1];
		dp[14][i] = dp[14][i-1];
		dp[15][i] = dp[15][i-1];
		dp[16][i] = dp[16][i-1];
		dp[17][i] = dp[17][i-1];
		dp[18][i] = dp[18][i-1];
		dp[19][i] = dp[19][i-1];
		dp[20][i] = dp[20][i-1];
		dp[21][i] = dp[21][i-1];
		dp[22][i] = dp[22][i-1];
		dp[23][i] = dp[23][i-1];
		dp[24][i] = dp[24][i-1];
		dp[25][i] = dp[25][i-1];
		
		dp[GET_INDEX(S[i])][i]++;
	}
	
	for(int i=1;i<=q;i++)
	{
		char	a;
		int		l,r,cnt;
		
		getchar();
		scanf("%c %d %d",&a,&l,&r);
		
		cnt = dp[GET_INDEX(a)][r]-dp[GET_INDEX(a)][l];
		
		if( S[l] == a )
		{
			cnt++;
		}
		
		printf("%d\n",cnt);
	}
	
	return	0;
}
