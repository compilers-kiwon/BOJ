#include	<iostream>
#include	<vector>
#include	<cmath>

using namespace	std;

#define	MAX_SIZE	31622

typedef	long long int	int64;

bool	prime_table[MAX_SIZE+1];

void	get_prime(vector<int>& p)
{
	fill(&prime_table[1],&prime_table[MAX_SIZE+1],true);
	
	prime_table[1] = false;
	
	for(int i=2;i<=MAX_SIZE;i++)
	{
		if( prime_table[i] == true )
		{
			p.push_back(i);
			
			for(int j=i+i;j<=MAX_SIZE;j+=i)
			{
				prime_table[j] = false;
			}
		}
	}
}

bool	is_prime(int n)
{
	int	d;
	
	d = sqrt(n);
	
	if( d*d == n )
	{
		return	false;
	}
	
	for(int i=2;i<=d;i++)
	{
		if( n%i == 0 )
		{
			return	false;
		}
	}
	
	return	true;
}

bool	is_pow_of_prime(int64 n,vector<int>& p)
{
	for(int i=0;i<p.size();i++)
	{
		for(int64 j=(int64)p[i];j<=n;j*=(int64)p[i])
		{
			if( j == n )
			{
				return	true;
			}
		}
	}
	
	return	false;
}

int		main(void)
{
	int			n;
	vector<int>	prime;
	
	cin>>n;
	get_prime(prime);
	
	if( is_prime(n)==true || is_pow_of_prime((int64)n,prime)==true )
	{
		cout<<"yes\n";
	}
	else
	{
		cout<<"no\n";
	}
	
	return	0;
}
