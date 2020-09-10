#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(50+1)

#define	WHITE	'W'
#define	BLUE	'B'
#define	RED		'R'

#define	WHITE_INDEX			0
#define	BLUE_INDEX			1
#define	RED_INDEX			2
#define	MAX_NUM_OF_COLOR	3

int		N,M;
char	board[MAX_SIZE][MAX_SIZE+1],color[MAX_NUM_OF_COLOR];
int		table[MAX_SIZE][MAX_NUM_OF_COLOR],dp[MAX_SIZE][MAX_NUM_OF_COLOR];

int		get_num_of_color_at_row(int row,char color)
{
	int	cnt,i;
	
	for(i=1,cnt=0;i<=M;i++)
	{
		if( color == board[row][i] )
		{
			cnt++;
		}
	}

	return	cnt;
}

int		main(void)
{
	scanf("%d %d",&N,&M);
	
	color[WHITE_INDEX] = WHITE;
	color[BLUE_INDEX] = BLUE;
	color[RED_INDEX] = RED;
	
	for(int i=1;i<=N;i++)
	{
		scanf("%s",&board[i][1]);
		
		for(int j=WHITE_INDEX;j<=RED_INDEX;j++)
		{
			table[i][j] = M-get_num_of_color_at_row(i,color[j]);
			dp[i][j] = -1;
		}
	}
	
	dp[1][WHITE_INDEX] = table[1][WHITE_INDEX];
	dp[1][BLUE_INDEX] = dp[1][RED_INDEX] = 10000;
	
	for(int row=2;row<=N-1;row++)
	{
		dp[row][WHITE_INDEX] = dp[row-1][WHITE_INDEX]+table[row][WHITE_INDEX];
		dp[row][BLUE_INDEX] = min(dp[row-1][WHITE_INDEX],dp[row-1][BLUE_INDEX])+table[row][BLUE_INDEX];
		dp[row][RED_INDEX] = min(dp[row-1][BLUE_INDEX],dp[row-1][RED_INDEX])+table[row][RED_INDEX];
	}
	dp[N][RED_INDEX] = min(dp[N-1][BLUE_INDEX],dp[N-1][RED_INDEX])+table[N][RED_INDEX];
	
	printf("%d\n",dp[N][RED_INDEX]);
	
	return	0;
}
