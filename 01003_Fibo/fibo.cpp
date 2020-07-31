/*
	f(n) = f(n-1)*f(n-2)
		 = f(n-1-1)*f(n-1-2)*f(n-2-1)*f(n-2-2)
		 = f(n-1-1-1)*f(n-1-1-2)*f(n-1-2-1)*f(n-1-2-2)*f(n-2-1-1)*f(n-2-1-2)*f(n-2-2-1)*f(n-2-2-2)
		 = ....
		 
	How many times are f(0) and f(1) called?
	f(0) and f(1) are leaf function so that they will just return without any recursion.  
*/

#include	<iostream>

using namespace	std;

typedef	long long int		int64;
typedef	pair<int64,int64>	NumOfCall;

#define	MAX_NUM	40

NumOfCall	get_dp(int n,NumOfCall* dp)
{
	NumOfCall&	ret = dp[n];
	
	if( ret.first != -1 && ret.second != -1 )
	{
		return	ret;
	}
	
	NumOfCall	tmp1,tmp2;
	
	tmp1 = get_dp(n-2,dp);
	tmp2 = get_dp(n-1,dp);
	
	ret.first = tmp1.first+tmp2.first;
	ret.second = tmp1.second+tmp2.second;
	
	return	ret;
}

int			main(void)
{
	NumOfCall	dp[MAX_NUM+1];
	int			T;
	
	dp[0] = make_pair(1,0);
	dp[1] = make_pair(0,1);
	
	for(int i=2;i<=MAX_NUM;i++)
	{
		dp[i] = make_pair(-1,-1);
	}
	
	cin>>T;
	
	while(T>0)
	{
		int			n;
		NumOfCall	a;
		
		cin>>n;
		a = get_dp(n,dp);
		cout<<a.first<<' '<<a.second<<'\n';
		
		T--;
	}
	return	0;
}
