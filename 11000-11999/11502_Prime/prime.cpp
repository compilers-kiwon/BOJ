#include	<iostream>

using namespace	std;

#define	MAX_NUM	1000

void	init_prime_table(bool table[])
{
	table[1] = false;
	
	for(int i=2;i<MAX_NUM;i++)
	{
		if( table[i] == true )
		{
			for(int j=i+i;j<MAX_NUM;j+=i)
			{
				table[j] = false;
			}
		}
	}
}

void	check_sum_of_three_primes(int n,bool prime_table[])
{
	for(int i=2;i<MAX_NUM;i++)
	{
		if( prime_table[i] == true && i <= n/3 )
		{
			for(int j=i;j<MAX_NUM;j++)
			{
				if( prime_table[j] == true && (n-i-j) >= j )
				{
					for(int k=j;k<MAX_NUM;k++)
					{
						if( prime_table[k] == true && i+j+k == n )
						{
							printf("%d %d %d\n",i,j,k);
							return;
						}
					}
				}
			}
		}
	}
	puts("0");
}

int		main(void)
{
	bool	prime_table[MAX_NUM];
	int		i;
	
	for(i=0;i+10<MAX_NUM;i+=10)
	{
		prime_table[i] = prime_table[i+1] = prime_table[i+2] = prime_table[i+3] = prime_table[i+4] =
		prime_table[i+5] = prime_table[i+6] = prime_table[i+7] = prime_table[i+8] = prime_table[i+9] = true;
	}
	
	for(;i<MAX_NUM;i++)
	{
		prime_table[i] = true;
	}
	
	init_prime_table(prime_table);
	
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	K;
		
		cin>>K;
		check_sum_of_three_primes(K,prime_table);
		T--;
	}
	return	0;
}
