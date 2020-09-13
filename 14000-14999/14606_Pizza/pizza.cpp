#include	<iostream>
#include	<vector>

using namespace	std;

typedef	long long int	int64;

#define	DP_SIZE	(1000000+1)

vector<int64>	dp(DP_SIZE,-1);

int64	get_pleasure(int64 p)
{
	if( p <= DP_SIZE && dp[p] != -1 )
	{
		return	dp[p];
	}
	
	int64	p1,p2,r;
	
	p1 = p/2;
	p2 = p-p1;
	
	r = p1*p2+get_pleasure(p1)+get_pleasure(p2);
	
	if( p <= DP_SIZE )
	{
		dp[p] = r;
	}
	
	return	r; 
}

int		main(void)
{
	int64	N;
	
	dp[1] = 0;
	
	cin>>N;
	cout<<get_pleasure(N)<<endl;
	
	return	0;
}
