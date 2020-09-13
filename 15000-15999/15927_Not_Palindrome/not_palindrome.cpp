#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	MAX_SIZE	50

#define	TRUE	1
#define	FALSE	-1
#define	UNKNOWN	0

typedef	pair<int,int>	HT;

map<HT,int>	dp;

int		get_dp(string& str,int from,int to)
{
	if( from >= to )
	{
		return	TRUE;
	}
	
	int&	ret = dp[make_pair(from,to)];
	
	if( ret != UNKNOWN )
	{
		return	ret;
	}
	
	if( str[from] != str[to] )
	{
		ret = FALSE;
	}
	else
	{
		ret = get_dp(str,from+1,to-1);
	}
	
	return	ret;
}

bool	find_non_palindrome_sub_str(string& str,int len)
{
	bool	found;
	int		i;
	
	for(i=0,found=false;i<=str.length()-len&&found!=true;i++)
	{
		if( get_dp(str,i,i+len-1) == FALSE )
		{
			found = true;
		}
	}
	
	return	found;
}

int		main(void)
{
	string	str;
	int		i;
	
	cin>>str;
	
	for(i=str.length();i>1;i--)
	{
		if( find_non_palindrome_sub_str(str,i) == true )
		{
			break;
		}
	}
	
	if( i == 1 )
	{
		i = -1;
	}
	
	cout<<i<<'\n';
	
	return	0;
}
