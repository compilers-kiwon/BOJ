#include	<iostream>
#include	<vector>
#include	<cmath>

using namespace	std;

typedef	unsigned long long	uint64;

void	build_prime_table(int n,vector<bool>& prime_table,vector<int>& prime_vec)
{
	prime_table[1] = false;
	
	for(int i=2;i<=n;i++)
	{
		if( prime_table[i] == true )
		{
			prime_vec.push_back(i);
			
			for(int j=i+i;j<=n;j+=i)
			{
				prime_table[j] = false;
			}
		}
	}
}

void	build_div_table(int n,vector<bool>& div_table,vector<int>& div_vec)
{
	for(int i=1;i<=n;i++)
	{
		if( n%i == 0 )
		{
			div_table[i] = true;
			div_vec.push_back(i);	
		}	
	}	
}

void	count_equation(int n,uint64& a,uint64& b,uint64& c,
					   vector<bool>& is_prime,vector<int>& prime_vec,
					   vector<bool>& is_div,vector<int>& div_vec)
{
	for(int Z=2;Z<=n;Z++)
	{
		if( Z%2 == 0 )
		{
			a += (uint64)((Z-1)/2);
		}
		else
		{
			a += (uint64)(Z/2);
		}
	}
	
	for(int i=0;i<div_vec.size();i++)
	{
		for(int j=i;j<div_vec.size();j++)
		{
			int	Z = div_vec[i]+div_vec[j];
			
			if( Z > n )
			{
				break;
			}
			
			if( is_div[Z] == true )
			{
				b++;
			}
		}
	}
	
	for(int i=0;i<prime_vec.size();i++)
	{
		int	Z = prime_vec[i]+2;
		
		if( Z > n )
		{
			break;
		}
		
		if( is_prime[Z] == true )
		{
			c++;
		}
	}
}

int		main(void)
{
	int		N;
	uint64	A,B,C;
	
	cin>>N;
	A=B=C=0;
	
	vector<bool>	is_prime(N+1,true),is_div(N+1,false);
	vector<int>		prime,div;
	
	build_prime_table(N,is_prime,prime);
	build_div_table(N,is_div,div);
	
	count_equation(N,A,B,C,is_prime,prime,is_div,div);
	
	cout<<A<<'\n'<<B<<'\n'<<C<<'\n';
	
	return	0;
}
