#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(2000+1)

int	N,H[MAX_SIZE],dp[MAX_SIZE][MAX_SIZE];

int		get_dp(int left,int right,int day)
{
	if( left > right )
	{
		return	0;
	}
	
	int&	ret = dp[left][right];
	
	if( ret != 0 )
	{
		return	ret;
	}
	
	ret = max(get_dp(left+1,right,day+1)+H[left]*day,
			  get_dp(left,right-1,day+1)+H[right]*day);
	
	return	ret;
}

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>H[i];
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<get_dp(1,N,1)<<'\n';
	
	return	0;
}
