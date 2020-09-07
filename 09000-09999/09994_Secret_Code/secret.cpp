#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

int		get_dp(string& str,map<string,int>& dp)
{
	int&	ret = dp[str];
	
	if( ret != 0 )
	{
		return	ret;
	}
	
	ret = 1;
	
	if( str.length()%2 == 0 )
	{
		return	ret;
	}
	
	string	s1,s2;
		
	//================================
	s1 = str.substr(0,str.length()/2);
	s2 = str.substr(str.length()/2,str.length()/2+1);
	//================================
	
	// s1+(s1+c)
	if( s1 == s2.substr(0,str.length()/2) )
	{
		ret += get_dp(s2,dp);
	}
	
	// s1+(c+s1)
	if( s1 == s2.substr(1,str.length()/2) )
	{
		ret += get_dp(s2,dp);
	}
	
	//=================================
	s1 = str.substr(0,str.length()/2+1);
	s2 = str.substr(str.length()/2+1,str.length()/2);
	//=================================
	
	// (s1+c)+s1
	if( s1.substr(0,str.length()/2) == s2 )
	{
		ret += get_dp(s1,dp);
	}
	
	// (c+s1)+s1
	if( s1.substr(1,str.length()/2) == s2 )
	{
		ret += get_dp(s1,dp);
	}
	
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
