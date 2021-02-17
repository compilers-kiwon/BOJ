#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM	1000000

int		N,cnt_of_odd_factors;
bool	prime_table[MAX_NUM+1];
bool	is_odd_factor[MAX_NUM+1];

#define	is_prime(n)		(prime_table[(n)]==false)
#define	non_prime(n)	prime_table[(n)]=true

void	get_prime_numbers(vector<int>& p)
{
	for(int i=2;i<=MAX_NUM;i++)
	{
		if( is_prime(i) == true )
		{
			p.push_back(i);
			
			for(int j=i+i;j<=MAX_NUM;j+=i)
			{
				non_prime(j);
			}
		}
	}
}

int		find_prime_factor(int n,const vector<int>& p)
{
	if( is_prime(n) == true )
	{
		return	n;
	}
	
	int	ret;
	
	for(int i=0;i<p.size();i++)
	{
		if( n%p[i] == 0 )
		{
			ret = p[i];
			break;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int			N;
	vector<int>	prime;
	
	cin>>N;
	get_prime_numbers(prime);
	
	for(int i=1;i<=N;i++)
	{
		int	a;
		
		cin>>a;
		
		for(;a!=1;)
		{
			int	f;
			
			f = find_prime_factor(a,prime);
			
			if( is_odd_factor[f] == true )
			{
				is_odd_factor[f] = false;
				cnt_of_odd_factors--;
			}
			else
			{
				is_odd_factor[f] = true;
				cnt_of_odd_factors++;
			}
			
			a /= f;
		}
		
		if( cnt_of_odd_factors == 0 )
		{
			cout<<"DA\n";
		}
		else
		{
			cout<<"NE\n";
		}
	}
	
	return	0;
}
