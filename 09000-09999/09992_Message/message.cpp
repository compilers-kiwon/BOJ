#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	MOD_N	2014
#define	MOD(n)	((n)%MOD_N)

int		get_dp(string& str,map<string,int>& dp)
{
	int&	ret = dp[str];
	
	if( ret != 0 )
	{
		return	ret;
	}
	
	ret = 1;
	
	for(int i=1;i<(str.length()+1)/2;i++)
	{
		string	s1,s2;
		
		//================================
		s1 = str.substr(0,i);
		s2 = str.substr(i,str.length()-i);
		//================================
		
		// head+(head+tail)
		if( s1 == s2.substr(0,i) )
		{
			ret += MOD(get_dp(s2,dp));
		}
		
		// tail+(head+tail)
		if( s1 == s2.substr(s2.length()-i,i) )
		{
			ret += MOD(get_dp(s2,dp));
		}
		
		//=================================
		s1 = str.substr(0,str.length()-i);
		s2 = str.substr(str.length()-i,i);
		//=================================
		
		// (head+tail)+head
		if( s1.substr(0,i) == s2 )
		{
			ret += MOD(get_dp(s1,dp));
		}
		
		// (head+tail)+tail
		if( s1.substr(s1.length()-i,i) == s2 )
		{
			ret += MOD(get_dp(s1,dp));
		}
	}
	
	ret = MOD(ret);
	return	ret;
}

int		main(void)
{
	string			str;
	map<string,int>	dp;
	
	cin>>str;
	cout<<get_dp(str,dp)-1<<'\n';
	
	return	0;
}
