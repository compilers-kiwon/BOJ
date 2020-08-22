#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_NUM	34
#define	MAX_LEN	40

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))
#define	char2int(c)			((int)((c)-'0'))

int	main(void)
{
	string	number;
	int		dp[MAX_LEN+2],n[MAX_LEN+2];
	
	cin>>number;
	
	for(int i=0;i<number.length();i++)
	{
		n[i] = char2int(number[i]);
		dp[i] = 0;
	}
	
	for(int i=number.length();i<MAX_LEN+2;i++)
	{
		n[i] = dp[i] = 0;
	}
	
	dp[0] = 1;
	
	for(int i=0;i<number.length();i++)
	{
		if( n[i] != 0 )
		{
			dp[i+1] += dp[i];
			
			if( IN_RANGE(10,n[i]*10+n[i+1],MAX_NUM) )
			{
				dp[i+2] += dp[i];
			}
		}
	}
	
	cout<<dp[number.length()]<<endl;
	
	return	0;
}
