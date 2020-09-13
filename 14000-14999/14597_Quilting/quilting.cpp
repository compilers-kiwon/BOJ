#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100+1)
#define	INF			0x7FFFFFFFFFFFFFFF

typedef	long long int	int64;

int		H,W;
int64	B1[MAX_SIZE][MAX_SIZE],B2[MAX_SIZE][MAX_SIZE],dp[MAX_SIZE][MAX_SIZE+1];

void	init(void)
{
	cin>>H>>W;
	
	for(int row=1;row<=H;row++)
	{
		for(int col=1;col<=W;col++)
		{
			cin>>B1[row][col];
		}
	}
	
	for(int row=1;row<=H;row++)
	{
		for(int col=1;col<=W;col++)
		{
			cin>>B2[row][col];
		}
	}
	
	for(int row=1;row<=H;row++)
	{
		for(int col=1;col<=W;col++)
		{
			dp[row][col] = -1;
		}
		dp[row][0] = dp[row][W+1] = INF;
	}
}

int64	get_dp(int row,int col)
{
	int64&	ret = dp[row][col];
	
	if( ret != -1 )
	{
		return	ret;
	}
	
	int64	left,mid,right,diff;
	
	left = get_dp(row-1,col-1);
	mid = get_dp(row-1,col);
	right = get_dp(row-1,col+1);
	diff = B1[row][col]-B2[row][col];
	
	ret = min(left,min(mid,right))+diff*diff;
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	init();
	
	for(int col=1;col<=W;col++)
	{
		dp[1][col] = (B1[1][col]-B2[1][col])*(B1[1][col]-B2[1][col]);
	}
	
	int64	E;
	
	E = INF;
	
	for(int col=1;col<=W;col++)
	{
		E = min(E,get_dp(H,col));
	}
	
	cout<<E<<'\n';
	
	return	0;
}
