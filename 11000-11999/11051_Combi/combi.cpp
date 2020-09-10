#include	<iostream>
#include	<cmath>
#include	<vector>

using namespace	std;

#define	MAX_NUM	1000
#define	MOD(n)	((n)%10007)

typedef	unsigned long long uint64;

int	N_table[MAX_NUM+1];
int	K_table[MAX_NUM+1];

vector<bool>	prime_table(MAX_NUM+1,false);
vector<int>		prime_numbers;

void	get_prime_numbers(int N)
{
	for(int i=2;i<=N;i++)
	{
		if( prime_table[i] == false )
		{
			prime_numbers.push_back(i);
			
			for(int j=i*2;j<=N;j=j+i)
			{
				prime_table[j] = true;
			}
		}
	}
}

void	factorization(int n,int* table)
{
	int	to;
	
	to = prime_numbers.size();
	
	for(int i=2;i<=n;i++)
	{
		int tmp = i;
		
		while( tmp != 1 )
		{
			for(int j=0;j<to && prime_numbers[j]<=tmp;j++)
			{
				if( tmp%prime_numbers[j] == 0 )
				{
					table[prime_numbers[j]]++;
					tmp = tmp/prime_numbers[j];
					break;
				}
			}
		}
	}
}

int	main(void)
{
	int	N,K;
	
	cin>>N>>K;
	
	get_prime_numbers(N);
	factorization(N,N_table);
	factorization(K,K_table);
	factorization(N-K,K_table);
	
	int value = 1;
	
	for(int i=2;i<=N;i++)
	{
		if( N_table[i]-K_table[i] > 0 )
		{
			int	tmp;
			
			tmp = pow(i,N_table[i]-K_table[i]);
			value = MOD(value*MOD(tmp));	
		}
		else if( N_table[i]-K_table[i] < 0 )
		{
			cout<<"Error:"<<i<<","<<N_table[i]<<","<<K_table[i]<<endl;	
		}	
	}
	cout<<value<<endl;
			
	return	0;
}
