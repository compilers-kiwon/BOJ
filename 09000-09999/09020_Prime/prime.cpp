#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM	10000

vector<bool>	prime_table(MAX_NUM+1,true);

void	init_prime_table(void)
{
	prime_table[1] = false;
	
	for(int i=2;i<=MAX_NUM;i++)
	{
		if( prime_table[i] == false )
		{
			continue;
		}
		
		for(int j=i+i;j<=MAX_NUM;j=j+i)
		{
			prime_table[j] = false;
		}
	}
}

int		main(void)
{
	int	T;
	
	cin>>T;
	init_prime_table();
	
	
	while(T>0)
	{
		int	n,a,b;
		
		cin>>n;
						
		for(a = b = n/2;a<=b;a--,b++)
		{
			if( prime_table[a] == true && prime_table[b] == true )
			{
				printf("%d %d\n",a,b);
				break;
			}
		}
		T--;
	}
	return	0;
}
