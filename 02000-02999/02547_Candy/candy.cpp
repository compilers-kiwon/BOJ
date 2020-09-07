#include	<iostream>

using namespace	std;

typedef	unsigned long long	uint64;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int		N,i;
		uint64	sum;
		
		cin>>N;
		
		for(i=1,sum=0;i<=N;i++)
		{
			uint64	candy;
			
			cin>>candy;
			sum = (sum+candy)%N;
		}
		
		if( sum == 0 )
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
		
		T--;
	}
	
	return	0;
}
