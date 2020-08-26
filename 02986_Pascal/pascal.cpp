#include	<iostream>
#include	<cmath>

using namespace	std;

int	get_biggest_divisor(int n)
{
	int	to,ret;
	
	to = sqrt(n);
	ret = 1;
	
	for(int i=2;i<=to;i++)
	{
		if( n%i == 0 )
		{
			ret = n/i;
			break;
		}
	}
	
	return	ret;
}

int	main(void)
{
	int	N;
	
	cin>>N;
	cout<<N-get_biggest_divisor(N)<<'\n';
	
	return	0;
}
