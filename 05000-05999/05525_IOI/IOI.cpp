#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_LEN	1000000

int			N,M;
string		ioi;
vector<int>	dp(MAX_LEN,-1);

int		get_dp(int index)
{
	int&	ret = dp[index];
	
	if( ret != -1 )
	{
		return	ret;
	}
	
	if( ioi[index]=='I' && ioi[index-1]=='O' && ioi[index-2]=='I' )
	{
		ret = get_dp(index-2)+1;
	}
	else
	{
		ret = 0;
	}
	
	return	ret;
}

void	init(void)
{
	cin>>N>>M>>ioi;
	
	dp[0] = dp[1] = 0;
	
	for(int i=M-1;i>=2;i--)
	{
		get_dp(i);
	}
}

int		main(void)
{
	init();
	
	int	cnt,i;
	
	for(i=0,cnt=0;i<M;i++)
	{
		if( dp[i] >= N )
		{
			cnt++;
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
