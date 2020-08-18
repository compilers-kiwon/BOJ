#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

#define	MAX_SIZE		(100+1)
#define	MAX_WORD_LEN	80

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int		N,M,K;
char	board[MAX_SIZE][MAX_SIZE+1];
string	word;
int		dp[MAX_SIZE][MAX_SIZE][MAX_WORD_LEN];

int		get_dp(int row,int col,int index)
{
	if( index == word.length()-1 )
	{
		return	1;
	}
	
	int&	ret = dp[row][col][index];
	
	if( ret != -1 )
	{
		return	ret;
	}
	
	ret = 0;
	
	for(int i=1;i<=K;i++)
	{
		for(int j=UP;j<=RIGHT;j++)
		{
			int	next_row,next_col;
			
			next_row = row+adj[j].d_row*i;
			next_col = col+adj[j].d_col*i;
			
			if( IN_RANGE(1,next_row,N) && IN_RANGE(1,next_col,M) )
			{
				if( board[next_row][next_col] == word[index+1] )
				{
					ret += get_dp(next_row,next_col,index+1);
				}
			}
		}
	}
	
	return	ret;
}

int	main(void)
{
	cin>>N>>M>>K;
	
	for(int i=1;i<=N;i++)
	{
		scanf("%s",&board[i][1]);
	}
	
	cin>>word;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			for(int k=0;k<word.length();k++)
			{
				dp[i][j][k] = -1;
			}
		}
	}
	
	int	cnt;
	
	cnt = 0;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if( board[i][j] == word[0] )
			{
				cnt += get_dp(i,j,0);
			}
		}
	}
	
	cout<<cnt<<endl;
	
	return	0;
}
