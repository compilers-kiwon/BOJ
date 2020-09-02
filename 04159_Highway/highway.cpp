#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	TRUE		1
#define	FALSE		0
#define	NOT_DEFINED	-1

#define	FINAL	1422

#define	MAX_ALLOWED_DISTANCE	200
#define	IN_RANGE(MIN,n,MAX)		((MIN)<=(n)&&(n)<=(MAX))

int	get_dp(int current_station,vector<int>& station_info,vector<int>& dp)
{
	int& ret = dp[current_station];
	
	if( ret != NOT_DEFINED )
	{
		return	ret;
	}
	
	ret = FALSE;
	
	for(int i=current_station-1;i>=1;i--)
	{
		if( !IN_RANGE(1,station_info[current_station]-station_info[i],MAX_ALLOWED_DISTANCE) )
		{
			break;
		}
		
		if( get_dp(i,station_info,dp) == TRUE )
		{
			ret = TRUE;
			break;
		}
	}
	
	return	ret;
}

int	main(void)
{
	cin.sync_with_stdio(false);
	
	while(1)
	{
		int	n;
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		vector<int>	station(n+1),dp(n+1,NOT_DEFINED);
		
		for(int i=1;i<=n;i++)
		{
			cin>>station[i];
		}
		
		sort(&station[1],&station[n+1]);
		
		dp[1] = TRUE;
		
		if( get_dp(n,station,dp) == TRUE && IN_RANGE(1,(FINAL-station[n])*2,MAX_ALLOWED_DISTANCE) )
		{
			cout<<"POSSIBLE\n";
		}
		else
		{
			cout<<"IMPOSSIBLE\n";
		}
	}
	
	return	0;
}
