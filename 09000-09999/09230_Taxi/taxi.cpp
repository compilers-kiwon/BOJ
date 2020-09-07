#include	<iostream>

using namespace	std;

#define	MAX_SIZE	30

int	dp[MAX_SIZE][MAX_SIZE];

bool	init(int& num_of_streets,int& num_of_avenues)
{
	cin>>num_of_streets>>num_of_avenues;
	
	if( num_of_streets==0 && num_of_avenues==0 )
	{
		return	false;
	}
	
	for(int av=0;av<num_of_avenues;av++)
	{
		for(int st=0;st<num_of_streets;st++)
		{
			dp[av][st] = -1;
		}
	}
	
	for(;;)
	{
		int	s,a;
		
		cin>>s>>a;
		
		if( s==0 && a==0 )
		{
			break;
		}
		
		dp[a][s] = 0;
	}
	
	dp[0][0] = 1;
	
	return	true;
}

int		get_dp(int avenue,int street)
{
	int&	ret = dp[avenue][street];
	
	if( ret != -1 )
	{
		return	ret;
	}
	
	ret = 0;
	
	// UP
	if( avenue-1 >= 0 )
	{
		ret += get_dp(avenue-1,street);
	}
	
	// LEFT
	if( street-1 >= 0 )
	{
		ret += get_dp(avenue,street-1);
	}
	
	return	ret;
}

int		main(void)
{
	for(int m=1;;m++)
	{
		int	num_of_strrets,num_of_avenues;
		
		if( init(num_of_strrets,num_of_avenues) == false )
		{
			break;
		}
		
		cout<<"Map "<<m<<": "<<get_dp(num_of_avenues-1,num_of_strrets-1)<<'\n';
	}
	
	return	0;
}
