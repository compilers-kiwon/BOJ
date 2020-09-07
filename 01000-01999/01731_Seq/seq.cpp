#include	<iostream>

using namespace	std;

typedef	unsigned long long	uint64;

int	main(void)
{
	uint64	N,a,b,c,last;
	
	cin>>N>>a>>b>>c;
	
	if( N == 3 )
	{
		last = c;
	}
	else
	{
		for(uint64 i=4;i<=N;i++)
		{
			cin>>last;
		}
	}
	
	if( 2*b == a+c )
	{
		cout<<last+(b-a)<<endl;
	}
	
	if( b*b == a*c )
	{
		cout<<last*(b/a)<<endl;
	}
	
	return	0;
}
