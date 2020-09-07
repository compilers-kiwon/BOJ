#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_CABLES	(100+1)

bool	is_less(pair<int,int>& a,pair<int,int>& b)
{
	return	a.first<b.first;
}

bool	is_greater(pair<int,int>& a,pair<int,int>& b)
{
	return	a.first>b.first;
}

int		main(void)
{
	pair<int,int>	cable[MAX_NUM_OF_CABLES];
	int				dp1[MAX_NUM_OF_CABLES],dp2[MAX_NUM_OF_CABLES];
	int				dp3[MAX_NUM_OF_CABLES],dp4[MAX_NUM_OF_CABLES];
	int				N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>cable[i].first>>cable[i].second;
	}
	
	//==============================================
	
	sort(&cable[1],&cable[N+1],is_less);
	
	dp1[1] = 1;
	
	for(int i=2;i<=N;i++)
	{
		int	max_prev_dp,B;
		
		max_prev_dp = 0;
		B = cable[i].second;
		
		for(int j=1;j<=i-1;j++)
		{
			if( cable[j].second < B )
			{
				max_prev_dp = max(max_prev_dp,dp1[j]);
			}
		}
		dp1[i] = max_prev_dp+1;		
	}
	
	dp2[1] = 1;
	
	for(int i=2;i<=N;i++)
	{
		int	max_prev_dp,B;
		
		max_prev_dp = 0;
		B = cable[i].second;
		
		for(int j=1;j<=i-1;j++)
		{
			if( cable[j].second > B )
			{
				max_prev_dp = max(max_prev_dp,dp2[j]);
			}
		}
		dp2[i] = max_prev_dp+1;		
	}
	
	sort(&cable[1],&cable[N+1],is_greater);
	
	dp3[1] = 1;
	
	for(int i=2;i<=N;i++)
	{
		int	max_prev_dp,B;
		
		max_prev_dp = 0;
		B = cable[i].second;
		
		for(int j=1;j<=i-1;j++)
		{
			if( cable[j].second < B )
			{
				max_prev_dp = max(max_prev_dp,dp3[j]);
			}
		}
		dp3[i] = max_prev_dp+1;		
	}
	
	dp4[1] = 1;
	
	for(int i=2;i<=N;i++)
	{
		int	max_prev_dp,B;
		
		max_prev_dp = 0;
		B = cable[i].second;
		
		for(int j=1;j<=i-1;j++)
		{
			if( cable[j].second > B )
			{
				max_prev_dp = max(max_prev_dp,dp4[j]);
			}
		}
		dp4[i] = max_prev_dp+1;		
	}
	
	cout<<N-max(max(dp1[N],dp2[N]),max(dp3[N],dp4[N]))<<endl;
	
	return	0;
}
