#include	<iostream>
#include	<vector>
#include	<map>

using namespace	std;

#define	MAX_NUM	(100000+1)

void	init_prime_table(vector<int>& primes)
{
	vector<bool>	prime_table(MAX_NUM,true);
	
	for(int i=2;i<MAX_NUM;i++)
	{
		if( prime_table[i] == true )
		{
			primes.push_back(i);
			
			for(int j=i+i;j<MAX_NUM;j+=i)
			{
				prime_table[j] = false;
			}
		}
	}
}

void	find_prime_factors(map<int,int>& prime_factor_table,vector<int>& primes,int N)
{
	for(int i=0;i<primes.size();i++)
	{
		while( N%primes[i] == 0 )
		{
			N /= primes[i];
			prime_factor_table[primes[i]]++;
		}
		
		if( N == 1 )
		{
			break;
		}
	}
}

int		main(void)
{
	vector<int>		primes;
	int				T;
	
	cin>>T;
	init_prime_table(primes);
	
	while(T>0)
	{
		map<int,int>	prime_factors;
		int				N;
				
		cin>>N;
		
		find_prime_factors(prime_factors,primes,N);
		
		map<int,int>::iterator	it;
		
		for(it=prime_factors.begin();it!=prime_factors.end();it++)
		{
			cout<<it->first<<' '<<it->second<<endl;
		}
		
		T--;
	}
	
	return	0;
}
