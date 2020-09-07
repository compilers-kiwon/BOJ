#include	<iostream>

using namespace	std;

typedef	long long	int64;

int	main(void)
{
	int64	N,M,diff;
	
	cin>>N>>M;
	diff = N-M;
	if( diff < 0 )
	{
		diff = -diff;
	}
	cout<<diff<<endl;
	
	return	0;
}
