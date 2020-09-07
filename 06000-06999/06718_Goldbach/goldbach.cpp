#include	<iostream>
#include	<cmath>
#include	<vector>

using namespace	std;

#define	MAX_NUM	32768

bool	is_prime(int n)
{
	bool	result;
	
	result = true;
	
	for(int i=2,to=sqrt(n);i<=to;i++)
	{
		if( n%i == 0 )
		{
			result = false;
			break;
		}
	}
	
	return	result;
}

void	find_primes(vector<int>& primes)
{
	for(int i=2;i<MAX_NUM;i++)
	{
		if( is_prime(i) == true )
		{
			primes.push_back(i);
		}
	}
}

int		get_count_of_pair(int n,vector<int>& primes)
{
	int	cnt,h,t;
	
	for(cnt=0,h=0,t=primes.size()-1;h<=t;)
	{
		int	sum;
		
		sum = primes[h]+primes[t];
		
		if( sum == n )
		{
			cnt++;
			h++;
		}
		else if( sum > n )
		{
			t--;
		}
		else
		{
			h++;
		}
	}
	
	return	cnt;
}

int		main(void)
{
	vector<int>	p;
	
	find_primes(p);
	
	cin.sync_with_stdio(false);
	
	while(1)
	{
		int	n;
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		cout<<get_count_of_pair(n,p)<<'\n';
	}
	
	return	0;
}
