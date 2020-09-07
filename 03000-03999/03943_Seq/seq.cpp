#include	<iostream>

using namespace	std;

#define	MAX_NUM	(100000+1)

int	dp[MAX_NUM];

int	get_dp(int n)
{
	if( n < MAX_NUM && dp[n] != 0 )
	{
		return	dp[n];
	}
	
	int	max_num;
	
	for(max_num=n;n!=1;)
	{
		if( n%2 == 0 )
		{
			n = n/2;
		}
		else
		{
			n = n*3+1;
		}
		
		max_num = max(max_num,n);
	}
	
	if( n < MAX_NUM )
	{
		dp[n] = max_num;
	}
	
	return	max_num;
}

int	main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	dp[1] = 1;
	
	while(T>0)
	{
		int	n;
		
		scanf("%d",&n);
		printf("%d\n",get_dp(n));
		
		T--;
	}
	
	return	0;
}
