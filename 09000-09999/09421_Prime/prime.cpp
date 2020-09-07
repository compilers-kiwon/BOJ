#include	<iostream>
#include	<vector>
#include	<map>

using namespace	std;

#define	MAX_NUM	(1000000+1)

bool	table[MAX_NUM];

void	get_prime(vector<int>& primes,int n)
{
	for(int i=2;i<=n;i++)
	{
		if( table[i] == false )
		{
			primes.push_back(i);
			
			for(int j=i;j<=n;j+=i)
			{
				table[j] = true;
			}
		}
	}
}

bool	do_operation(int n,map<int,bool>& visited)
{
	if( n == 1 )
	{
		return	true;
	}
	
	if( visited[n] == true )
	{
		return	false;
	}
	
	visited[n] = true;
	
	int	next_num;
	
	for(next_num=0;n>0;n/=10)
	{
		next_num += (n%10)*(n%10);
	}
	
	return	do_operation(next_num,visited);
}

int		main(void)
{
	vector<int>	prime;
	int			n;
	
	cin>>n;
	
	get_prime(prime,n);
	
	for(int i=0;i<prime.size();i++)
	{
		map<int,bool>	visited;
		
		if( do_operation(prime[i],visited) == true )
		{
			cout<<prime[i]<<endl;
		}
	}
	
	return	0;
}
