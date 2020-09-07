#include	<iostream>
#include	<queue>
#include	<cmath>

using namespace	std;

typedef	unsigned long long	uint64;

#define	MAX_MONEY	5000000

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		priority_queue<uint64>	price;
		
		while(1)
		{
			uint64	p;
			
			cin>>p;
			
			if( p == 0 )
			{
				break;
			}
			
			price.push(p);
		}
		
		int		i,to;
		uint64	sum;
		
		for(i=1,sum=0,to=price.size();i<=to;i++)
		{
			sum += 2*pow(price.top(),i);
			price.pop();
			
			if( sum > MAX_MONEY )
			{
				break;
			}
		}
		
		if( sum > MAX_MONEY )
		{
			cout<<"Too expensive\n";
		}
		else
		{
			cout<<sum<<endl;
		}
		
		T--;
	}
	
	return	0;
}
