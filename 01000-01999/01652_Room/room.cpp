#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100+1)

char	room[MAX_SIZE+1][MAX_SIZE+1];

int		move_h(int row,int& col,int size)
{
	int	cnt;
	
	for(cnt=0;room[row][col]=='.';++col)
	{
		++cnt;
	}
	return	cnt;
}

int		move_v(int col,int& row,int size)
{
	int	cnt;
	
	for(cnt=0;room[row][col]=='.';++row)
	{
		++cnt;
	}
	return	cnt;
}

int		main(void)
{
	int	N;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%s",&room[i][1]);
		room[i][N+1] = 'X';
	}
	
	for(int i=1;i<=N;i++)
	{
		room[N+1][i] = 'X';
	}
	
	int	h_cnt=0,v_cnt=0;
	
	for(int row=1;row<=N;row++)
	{
		for(int j=1;j<=N;j++)
		{
			if( move_h(row,j,N) >= 2 )
			{
				++h_cnt;
			}
		}
	}
	
	for(int col=1;col<=N;col++)
	{
		for(int j=1;j<=N;j++)
		{
			if( move_v(col,j,N) >=2 )
			{
				++v_cnt;
			}
		}
	}
	printf("%d %d\n",h_cnt,v_cnt);
	
	return	0;
}
