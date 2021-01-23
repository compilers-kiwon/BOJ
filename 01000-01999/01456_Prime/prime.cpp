#include	<iostream>
#include	<vector>
#include	<set>
#include	<cmath>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM		10000000
#define	LOG_LIMIT	14.0

typedef	long long int	int64;

int64			A,B;
bool			non_prime[MAX_NUM+1];
vector<int64>	prime_numbers,almost_primes;

void	get_prime_numbers(void)
{
	for(int i=2;i<=MAX_NUM;i++)
	{
		if( non_prime[i] == false )
		{
			prime_numbers.push_back((int64)i);
			
			for(int j=i+i;j<=MAX_NUM;j+=i)
			{
				non_prime[j] = true;
			}
		}
	}
}

void	get_almost_prime_numbers(void)
{
	set<int64>	tmp;
	
	for(int i=0;i<prime_numbers.size();i++)
	{
		int64&	p = prime_numbers[i];
		
		for(int64 n=p;;)
		{
			if( log10(n)+log10(p) > LOG_LIMIT )
			{
				break;
			}
			
			n *= p;
			tmp.insert(n);
		}
	}
	
	set<int64>::iterator	it;
	
	for(it=tmp.begin();it!=tmp.end();it++)
	{
		almost_primes.push_back(*it);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>A>>B;
	
	get_prime_numbers();
	get_almost_prime_numbers();
	
	vector<int64>::iterator	lower,upper;
	
	lower = lower_bound(almost_primes.begin(),almost_primes.end(),A);
	upper = upper_bound(almost_primes.begin(),almost_primes.end(),B);
	
	cout<<upper-lower<<'\n';
	
	return	0;
}
