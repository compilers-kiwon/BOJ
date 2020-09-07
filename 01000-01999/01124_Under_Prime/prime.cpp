#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM	100000

bool	prime_table[MAX_NUM+1];

void	build_prime_table(vector<int>& prime_list)
{
	fill_n(prime_table,MAX_NUM+1,true);
	
	prime_table[1] = false;
	
	for(int i=2;i<=MAX_NUM;i++)
	{
		if( prime_table[i] == true )
		{
			prime_list.push_back(i);
			
			for(int j=i+i;j<=MAX_NUM;j+=i)
			{
				prime_table[j] = false;
			}
		}
	}
}

int		get_num_of_primes(int n,vector<int>& prime_list)
{
	int	cnt;
	
	for(cnt=0;n>1;cnt++)
	{
		for(int i=0;i<prime_list.size();i++)
		{
			if( n%prime_list[i] == 0 )
			{
				n /= prime_list[i];
				break;
			}
		}
	}
	
	return	cnt;
}

int		main(void)
{
	vector<int>	primes;
	
	build_prime_table(primes);
	
	int	A,B,cnt;
	
	cin>>A>>B;
	cnt = 0;
	
	for(int i=A;i<=B;i++)
	{
		int	num_of_primes;
		
		num_of_primes = get_num_of_primes(i,primes);
		
		if( prime_table[num_of_primes] == true )
		{
			cnt++;
		}
	}
	
	cout<<cnt<<endl;
	
	return	0;
}
