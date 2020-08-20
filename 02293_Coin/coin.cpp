#include	<iostream>

using namespace std;

#define	MAX_NUM_OF_COIN	(100+1)
#define	MAX_VALUE		(10000+1)

int	coin[MAX_NUM_OF_COIN];
int	money[MAX_VALUE];


int	main(void)
{	
	int	n,k;
	
	cin>>n>>k;
	
	for(int i=1;i<=n;i++)
	{
		cin>>coin[i];
	}
	
	money[0] = 1;
	
	for(int coin_index=1;coin_index<=n;coin_index++)
	{
		for(int money_value=1;money_value<=k;money_value++)
		{
			if( money_value-coin[coin_index] >= 0 )
			{
				money[money_value] = money[money_value]+money[money_value-coin[coin_index]];
			}
		}
	}
	cout<<money[k]<<endl;
	
	return	0;
}
