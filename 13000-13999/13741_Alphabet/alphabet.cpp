#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_LEN			50
#define	ALPHABET_LEN	26

int	main(void)
{
	string	s;
	int		dp[MAX_LEN],max_len;
	
	cin>>s;
	dp[0] = 1;
	max_len = 0;
	
	for(int i=1;i<s.length();i++)
	{
		int	prev_max_len;
		
		prev_max_len = 0;
		
		for(int j=0;j<i;j++)
		{
			if( s[j] < s[i] )
			{
				prev_max_len = max(prev_max_len,dp[j]);
			}
		}
		
		dp[i] = prev_max_len+1;
	}
	
	for(int i=0;i<s.length();i++)
	{
		max_len = max(max_len,dp[i]);
	}
	
	cout<<ALPHABET_LEN-max_len<<'\n';
	
	return	0;
}
