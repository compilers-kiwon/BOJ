#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM	(10000+1)

vector<bool>	prime_table(MAX_NUM,true);
int				M,N;

void	init_table(void)
{
	prime_table[1] = false;
	
	for(int i=2;i<=N;i++)
	{
		if( prime_table[i] == true )
		{
			for(int j=i+i;j<=N;j=j+i)
			{
				prime_table[j] = false;
			}
		}
	}
}

int		main(void)
{
	cin>>M>>N;
	
	init_table();
	
	int	min_prime,sum,i;
	
	for(i=N,min_prime=-1,sum=0;i>=M;i--)
	{
		if( prime_table[i] == true )
		{
			min_prime = i;
			sum += min_prime;
		}
	}
	
	if( sum == 0 )
	{
		cout<<"-1\n";
	}
	else
	{
		cout<<sum<<endl<<min_prime<<endl;
	}
	
	return	0;
}

