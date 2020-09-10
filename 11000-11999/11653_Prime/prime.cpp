#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM	10000000

vector<bool>	prime_table(MAX_NUM+1,false);
vector<int>		prime_numbers;

void	get_prime_numbers(int N)
{
	for(int i=2;i*i<=N;i++)
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

int		main(void)
{
	int	N;
	
	cin>>N;
	
	get_prime_numbers(N);
	
	int	i,to;
	
	for(i=0,to=prime_numbers.size();i<to;)
	{
		if( N%prime_numbers[i] == 0 )
		{
			N = N/prime_numbers[i];
			cout<<prime_numbers[i]<<endl;
		}
		else
		{
			if( N == 1 || prime_table[N] == false )
			{
				break;
			}
			i++;
		}
	}
	
	if( N != 1 )
	{
		cout<<N<<endl;
	}
	return	0;
}
