#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_ARTIST	15
#define	MAX_PRICE			9

#define	prev_owned(prev_owners,new_owner)	((prev_owners)&(1<<new_owner))
	
int	N;
int	price_table[MAX_NUM_OF_ARTIST][MAX_NUM_OF_ARTIST];
int	dp[1<<MAX_NUM_OF_ARTIST][MAX_NUM_OF_ARTIST][MAX_PRICE+1];

int	find_max_num_of_owner(int prev_owners,int current_owner,int current_price,int current_num_of_owner)
{	
	if( dp[prev_owners][current_owner][current_price] != 0 )
	{
		return	dp[prev_owners][current_owner][current_price];
	}
	
	dp[prev_owners][current_owner][current_price] = current_num_of_owner;
	
	for(int i=0;i<N;i++)
	{
		if( prev_owned(prev_owners,i) == false && price_table[current_owner][i] >= current_price )
		{
			int	tmp;
			
			tmp = find_max_num_of_owner(prev_owners|(1<<i),i,price_table[current_owner][i],current_num_of_owner+1);
			dp[prev_owners][current_owner][current_price] = max(dp[prev_owners][current_owner][current_price],tmp);
		}
	}
	
	return	dp[prev_owners][current_owner][current_price];
}

int		main(void)
{
	scanf("%d",&N);
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%1d",&price_table[i][j]);
		}
	}
	
	printf("%d\n",find_max_num_of_owner(1<<0,0,0,1));
	
	return	0;
}
