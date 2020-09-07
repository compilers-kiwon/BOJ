#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM	1000000

bool		prime_table[MAX_NUM+1];	// visited
vector<int>	is_prime(MAX_NUM+1,-1);	// next_prime

void	init_prime_table(void)
{
	int	prev_prime = 0;
	
	for(int i=3;i<=MAX_NUM;i=i+2)
	{
		if( i%2 == 1 && prime_table[i] == false )
		{
			is_prime[prev_prime] = i;
			prev_prime = i;
			
			for(int j=i+2*i;j<=MAX_NUM;j=j+2*i)
			{
				prime_table[j] = true;
			}
		}
	}
	is_prime[prev_prime] = 0;
}

int		main(void)
{
	init_prime_table();
	
	while(1)
	{
		int	n;
		
		scanf("%d",&n);
		
		if( n == 0 )
		{
			break;
		}
		
		bool	found = false;
		int		a,b;
		
		a = 3;
		b = n-3;
		
		while( b >= a )
		{
			if( is_prime[b] != -1 )
			{
				found = true;
				break;
			}
			a = is_prime[a];
			b = n-a;
		}
		
		if( found == true )
		{
			printf("%d = %d + %d\n",n,a,b);
		}
		else
		{
			puts("Goldbach's conjecture is wrong.");
		}
	}
	
	return	0;
}
