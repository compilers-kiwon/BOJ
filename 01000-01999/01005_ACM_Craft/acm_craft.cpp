#include	<iostream>
#include	<vector>

using namespace	std;

#define	NOT_COMPLETE			-1
#define	MAX_NUM_OF_BUILDINGS	(1000+1)
#define	INF						0x7FFFFFFF

int	N,K,D[MAX_NUM_OF_BUILDINGS],W;

void	input(vector<int>* required)
{
	cin>>N>>K;
	
	for(int i=1;i<=N;i++)
	{
		cin>>D[i];
	}
	
	for(int i=1;i<=K;i++)
	{
		int	X,Y;
		
		cin>>X>>Y;
		required[Y].push_back(X);
	}
	
	cin>>W;
}

int		get_dp(vector<int>& dp,vector<int>* required,int b)
{
	int&	ret = dp[b];
	
	if( ret != NOT_COMPLETE )
	{
		return	ret;
	}
	
	ret = 0;
		
	for(int i=0;i<required[b].size();i++)
	{
		ret = max(ret,get_dp(dp,required,required[b][i]));
	}
	
	ret += D[b];
	
	return	ret;
}

int		get_complete_time(vector<int>* required)
{
	vector<int>	dp(N+1,NOT_COMPLETE);
	
	return	get_dp(dp,required,W);
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		vector<int>	required[MAX_NUM_OF_BUILDINGS];
		
		input(required);
		cout<<get_complete_time(required)<<'\n';
	}
	
	return	0;
}
