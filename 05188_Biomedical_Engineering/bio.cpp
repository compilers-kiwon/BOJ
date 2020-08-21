#include	<iostream>
#include	<string>
#include	<map>
#include	<vector>

using namespace	std;

#define	INF	10000

typedef	vector<string>	Assembly;

void	input(string& str,map<char,Assembly>& a)
{
	int	m;
	
	cin>>m>>str;
	
	for(int i=1;i<=m;i++)
	{
		string	s;
		
		cin>>s;
		a[s[s.length()-1]].push_back(s);
	}
}

int		get_dp(int idx,vector<int>& dp,string& str,map<char,Assembly>& a)
{
	int&	ret = dp[idx];
	
	if( ret != -1 )
	{
		return	ret;
	}
	
	ret = INF;
	
	Assembly&	candidate = a[str[idx]];
	
	for(int i=0;i<candidate.size();i++)
	{
		string&	c = candidate[i];
		
		if( c.length()<=idx && c==str.substr(idx-c.length()+1,c.length()) )
		{
			ret = min(ret,get_dp(idx-c.length(),dp,str,a)+1);
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		string				str;
		map<char,Assembly>	a;
		vector<int>			dp;
		int					ret;
		
		input(str,a);
		str.insert(str.begin(),' ');
		
		dp.resize(str.length(),-1);
		dp[0] = 0;
		
		ret = get_dp(str.length()-1,dp,str,a);
		cout<<"Data Set "<<k<<":\n";
		
		if( ret == INF )
		{
			cout<<"Impossible\n";
		}
		else
		{
			cout<<ret<<'\n';
		}
	}
	
	return	0;
}
