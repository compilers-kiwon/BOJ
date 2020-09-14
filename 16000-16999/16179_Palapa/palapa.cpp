#include	<iostream>

using namespace	std;

#define	MAX_SIZE	100
#define	MOD_VALUE	9973
#define	MOD(n)		((n)%MOD_VALUE)

int	get_num_of_primes(void)
{
	int		ret;
	bool	visited[MAX_SIZE];
	
	ret = 0;
	fill(&visited[2],&visited[MAX_SIZE],false);
	
	for(int i=2;i<MAX_SIZE;i++)
	{
		if( visited[i] == false )
		{
			visited[i] = true;
			ret++;
			
			for(int j=i+i;j<MAX_SIZE;j+=i)
			{
				visited[j] = true;
			}
		}
	}
	
	return	ret;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T,p,e;
	
	cin>>T;
	
	p = get_num_of_primes();
	e = MAX_SIZE/2-5;
	
	for(int t=1;t<=T;t++)
	{
		int	N,prime,even,intersection;
		
		cin>>N;
		
		prime = p*9;
		
		for(int d=1;d<=N-3;d++)
		{
			prime = MOD(prime*10);
		}
		
		even = e;
		
		for(int d=1;d<=N-2;d++)
		{
			even = MOD(even*10);
		}
		
		intersection = p*e;
		
		for(int d=1;d<=N-4;d++)
		{
			intersection = MOD(intersection*10);
		}
		
		cout<<MOD(MOD(prime+even-intersection)+MOD_VALUE)<<'\n';
	}
	
	return	0;
}
