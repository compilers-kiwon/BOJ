#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	10000
#define	TBD			-1

string	s,p;
int		dp[MAX_SIZE];

int	get_dp(int idx)
{
	if( idx < 0 )
	{
		return	0;
	}
	
	int&	ret = dp[idx];
	
	if( ret != TBD )
	{
		return	ret;
	}
	
	ret = get_dp(idx-1)+1;
	
	if( idx+1>=p.length() && s.substr((idx+1)-p.length(),p.length())==p )
	{
		ret = min(ret,get_dp(idx-p.length())+1);
	}
	
	return	ret;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		cin>>s>>p;
		
		fill(&dp[0],&dp[s.length()],TBD);
		
		cout<<get_dp(s.length()-1)<<'\n';
	}
	
	return	0;
}
