#include	<iostream>

using namespace	std;

#define	MAX_LEN	(200+1)
#define	MOD(n)	((n)%1000007)

int	dp[MAX_LEN][MAX_LEN];
int	w,h,x,y;

int	get_dp(int row,int col)
{
	if( dp[row][col] != -1 )
	{
		return	dp[row][col];
	}
	
	dp[row][col] = MOD(get_dp(row-1,col)+get_dp(row,col-1));
	
	return	dp[row][col];
}

int	main(void)
{
	cin>>w>>h>>x>>y;
	
	for(int row=1;row<=h;row++)
	{
		for(int col=1;col<=w;col++)
		{
			dp[row][col] = -1;
		}
	}
	
	for(int row=1;row<=y;row++)
	{
		dp[row][1] = 1;
	}
	
	for(int col=1;col<=x;col++)
	{
		dp[1][col] = 1;
	}
	
	int	t;
	
	t = get_dp(y,x);
	
	for(int row=y+1;row<=h;row++)
	{
		dp[row][x] = t;
	}
	
	for(int col=x+1;col<=w;col++)
	{
		dp[y][col] = t;
	}
	
	cout<<get_dp(h,w)<<endl;
	
	return	0;
}
