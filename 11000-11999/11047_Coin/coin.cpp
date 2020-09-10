#include	<cstdio>

using namespace std;

#define	MAX_NUM_OF_COINS	(10+1)

int	coin[MAX_NUM_OF_COINS];
int	N,K,num_of_used_coins;

int	main(void)
{
	scanf("%d %d",&N,&K);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&coin[i]);
	}
	
	num_of_used_coins = 0;
	
	for(int i=N;i>=1 && K>0;i--)
	{
		num_of_used_coins += K/coin[i];
		K %= coin[i]; 
	}
	
	printf("%d\n",num_of_used_coins);
	
	return	0;
}
