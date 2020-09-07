#include	<iostream>

using namespace	std;

#define	MAX_VALUE		(10000+1)
#define	MAX_NUM_OF_COIN	(20+1)

int		coin_value_table[MAX_NUM_OF_COIN];
int		dp[MAX_NUM_OF_COIN][MAX_VALUE];
int		N,M;

int		get_dp(int index,int value)
{
	if( value == 0 )
	{
		return	1;
	}
	
	if( dp[index][value] != -1 )
	{
		return	dp[index][value];
	}
	
	dp[index][value] = 0;
	
	for(int i=index;i<=N;i++)
	{
		int	tmp;
		
		if( (tmp=value-coin_value_table[i]) >= 0 )
		{
			dp[index][value] += get_dp(i,tmp);
		}
	}

	return	dp[index][value];
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		cin>>N;
		
		for(int i=1;i<=N;i++)
		{
			cin>>coin_value_table[i];
		}
		
		cin>>M;
		
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=M;j++)
			{
				dp[i][j] = -1;
			}
		}
		
		cout<<get_dp(1,M)<<endl;
	
		T--;
	}
	
	return	0;	
}	
