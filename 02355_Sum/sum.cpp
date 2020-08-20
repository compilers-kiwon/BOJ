#include	<iostream>

using namespace	std;

#define	SUM(n)	((n)*((n)+1)/2)

typedef	long long int	int64;

int	main(void)
{
	int64	i,j;
	int64	s,e,sum;
	
	cin>>i>>j;
	
	s = min(i,j);
	e = max(i,j);
	
	if( s < 0 )
	{
		if( e < 0 )
		{
			s = -s;
			e = -e;
			sum = SUM(s)-SUM(e-1);
			sum = -sum;
		}
		else if( e == 0 )
		{
			s = -s;
			sum = SUM(s);
			sum = -sum;
		}
		else
		{
			s = -s;
			sum = SUM(e);
			sum = sum-SUM(s);
		}
	}
	else if( s == 0 )
	{
		if( e == 0 )
		{
			sum = 0;
		}
		else
		{
			sum = SUM(e);
		}
	}
	else
	{
		sum = SUM(e)-SUM(s-1);
	}
	cout<<sum<<endl;
	
	return	0;
}
