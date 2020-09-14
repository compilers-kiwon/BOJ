#include	<iostream>

using namespace	std;

#define	MAX_DAYS	(100000+1)
#define	MAX_DESSERT	(10+1)

int	N,M,V[MAX_DESSERT][MAX_DAYS],dp[MAX_DESSERT][MAX_DAYS];

void	input(void)
{
	cin>>N>>M;
	
	for(int dessert=1;dessert<=M;dessert++)
	{
		for(int day=1;day<=N;day++)
		{
			cin>>V[dessert][day];
			dp[dessert][day] = -1;
		}
	}
	
	for(int dessert=1;dessert<=M;dessert++)
	{
		dp[dessert][1] = V[dessert][1];
	}
}

int		get_dp(int dessert,int day)
{
	int&	ret = dp[dessert][day];
	
	if( ret != -1 )
	{
		return	ret;
	}
	
	ret = 0;
	
	for(int i=1;i<=M;i++)
	{
		int	s;
		
		s = get_dp(i,day-1);
		
		if( i == dessert )
		{
			s += V[dessert][day]/2;
		}
		else
		{
			s += V[dessert][day];
		}
		
		ret = max(ret,s);
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	int	max_satisfication;
	
	max_satisfication = 0;
	
	for(int d=1;d<=M;d++)
	{
		max_satisfication = max(max_satisfication,get_dp(d,N));
	}
	
	cout<<max_satisfication<<'\n';
	
	return	0;
}
