#include	<iostream>

using namespace	std;

#define	MAX_MONEY	(10000+1)
#define	MAX_COIN	(20+1)

int	money[MAX_MONEY];
int	coin[MAX_COIN];

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	N,M;
		
		cin>>N;
		
		for(int i=1;i<=N;i++)
		{
			cin>>coin[i];
		}
		
		cin>>M;
		money[0] = 1;
		
		for(int i=1;i<=M;i++)
		{
			money[i] = 0;
		}
		
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=M;j++)
			{
				if( j-coin[i] >= 0 )
				{
					money[j] = money[j]+money[j-coin[i]];
				}
			}
		}
		cout<<money[M]<<endl;
		
		T--;
	}
	return	0;
}
