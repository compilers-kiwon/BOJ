#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	5000
#define	MOD(n)		((n)%1000000)
#define	TBD			-1

string	str;
int		dp[MAX_SIZE];

#define	char2int(c)			((int)((c)-'0'))
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int	get_dp(int idx)
{
	if( idx < 0 )
	{
		return	1;
	}
	
	int&	ret = dp[idx];
	
	if( ret != TBD )
	{
		return	ret;
	}
	
	ret = 0;
	
	if( IN_RANGE('1',str[idx],'9') )
	{
		ret = MOD(ret+get_dp(idx-1)); 
	}
	
	if( idx-1 >= 0 )
	{
		int	n;
		
		n = char2int(str[idx-1])*10+char2int(str[idx]);
		
		if( IN_RANGE(10,n,26) )
		{
			ret = MOD(ret+get_dp(idx-2));
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin>>str;
	fill(&dp[0],&dp[MAX_SIZE],TBD);
	
	cout<<get_dp(str.length()-1)<<'\n';
	
	return	0;
}
