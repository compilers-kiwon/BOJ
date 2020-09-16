#include	<iostream>

using namespace	std;

typedef	long long int	int64;

#define	GET_NEGATIVE_SUM(n)	((n)*((n)-1)/-2)
#define	GET_POSITIVE_SUM(n)	((n)*((n)+1)/2)

int	main(void)
{
	int	t;
	
	cin>>t;
	
	for(int i=1;i<=t;i++)
	{
		int64	n,m,sum;
		
		cin>>n>>m;
		
		if( n<0 )
		{
			sum = GET_NEGATIVE_SUM(n);
			
			if( m<0 )
			{
				sum -= GET_NEGATIVE_SUM(m+1);
			}
			else
			{
				sum += GET_POSITIVE_SUM(m);
			}
		}
		else
		{
			sum = GET_POSITIVE_SUM(m);
			
			if( n != 0 )
			{
				sum -= GET_POSITIVE_SUM(n-1);
			}
		}
		
		cout<<"Scenario #"<<i<<":\n"<<sum<<"\n\n";
	}
	return	0;
}
