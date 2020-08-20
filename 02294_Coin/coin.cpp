#include	<cstdio>
#include	<algorithm>

using namespace std;

#define	MAX_NUM_OF_COIN	(100+1)
#define	MAX_VALUE		(10000+1)

int	coin[MAX_NUM_OF_COIN];
int	min_num_of_used_coins[MAX_VALUE];

int	main(void)
{	
	int	n,k;
	
	scanf("%d %d",&n,&k);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&coin[i]);
	}
		
	min_num_of_used_coins[0] = 0;
	
	for(int i=1;i<=k;i++)
	{
		min_num_of_used_coins[i] = 0x7FFFFFFF;
	}
	
	for(int money_value=1;money_value<=k;money_value++)
	{
		int	min = 0x7FFFFFFF;
			
		for(int coin_index=1;coin_index<=n;coin_index++)
		{
			int	current_coin_value,rest_value;
			int	num_of_used_coins;
				
			current_coin_value = coin[coin_index];
			rest_value = money_value-current_coin_value;
				
			if( coin[coin_index]<=money_value && min_num_of_used_coins[rest_value] != 0x7FFFFFFF )
			{
				min_num_of_used_coins[money_value] = 
					min_num_of_used_coins[money_value]<1+min_num_of_used_coins[rest_value]?min_num_of_used_coins[money_value]:1+min_num_of_used_coins[rest_value];
			}
		}
	}
	
	if( min_num_of_used_coins[k] == 0x7FFFFFFF )
	{
		min_num_of_used_coins[k] = -1;
	}
	
	printf("%d\n",min_num_of_used_coins[k]);
	
	return	0;
}
