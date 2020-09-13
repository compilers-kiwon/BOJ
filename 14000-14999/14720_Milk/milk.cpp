#include	<iostream>

using namespace	std;

#define	BERRY		0
#define	CHOCO		1
#define	BANANA		2
#define	MAX_MILK	3

#define	MAX_NUM_OF_STORES	(1000+1)

int	main(void)
{
	int	store[MAX_NUM_OF_STORES],dp[MAX_NUM_OF_STORES];
	int	N,max_num_of_drinking_milk,first_berry;
	int	prev;
	
	cin>>N;
	max_num_of_drinking_milk = first_berry = 0;
	
	for(int i=1;i<=N;i++)
	{
		cin>>store[i];
		
		if( first_berry == 0 && store[i] == BERRY )
		{
			first_berry = i;
		}
		
		dp[i] = 0;
	}
	
	dp[first_berry] = 1;
	
	for(int i=first_berry+1;i<=N;i++)
	{
		int	prev_max;
		
		prev = (store[i]+MAX_MILK-1)%MAX_MILK;
		prev_max = 0;
		
		for(int j=1;j<i;j++)
		{
			if( store[j] == prev )
			{
				prev_max = max(prev_max,dp[j]);
			}
		}
		
		if( prev_max != 0 )
		{
			dp[i] = prev_max+1;
			max_num_of_drinking_milk = max(max_num_of_drinking_milk,dp[i]);
		}
	}
	
	cout<<max_num_of_drinking_milk<<endl;
	
	return	0;
}
