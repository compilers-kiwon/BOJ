#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_CITY	16
#define	ALL_CITY(N)		((1<<(N))-1)
#define	INF				0x10000000
#define	is_visited(v,c)	(((v)&(1<<(c)))!=0)

int	N,W[MAX_NUM_OF_CITY][MAX_NUM_OF_CITY],dp[MAX_NUM_OF_CITY][1<<MAX_NUM_OF_CITY];

int	get_dp(int current_city,int visited_city)
{
	if( visited_city == ALL_CITY(N) )
	{
		int	ret;
		
		if( W[current_city][0] != 0 )
		{
			ret = W[current_city][0];
		}
		else
		{
			ret = INF;
		}
		
		return	ret;
	}
	
	int&	ret = dp[current_city][visited_city];
	
	if( ret != 0 )
	{
		return	ret;
	}
	
	ret = INF;
	
	for(int i=0;i<N;i++)
	{
		if( is_visited(visited_city,i)==false && W[current_city][i]!=0 )
		{
			ret = min(ret,get_dp(i,visited_city|(1<<i))+W[current_city][i]);
		}
	}
	
	return	ret;
}

int	main(void)
{
	cin>>N;
	
	for(int row=0;row<N;row++)
	{
		for(int col=0;col<N;col++)
		{
			cin>>W[row][col];
		}
	}
	
	cout<<get_dp(0,1)<<'\n';
	
	return	0;
}
