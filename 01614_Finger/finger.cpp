#include	<iostream>

using namespace	std;

typedef	long long int	int64;

int	main(void)
{
	int64	A,B,cnt;
	
	cin>>A>>B;
	
	if( A == 1 && B == 0 )
	{
		cout<<0<<'\n';
	
		return	0;
	}
	
	if( A == 1 || A == 5 )
	{
		
		cnt = B*8;
	}
	else
	{
		cnt = B/2*8+(B%2)*(8-(A-1)*2);
	}
	
	cout<<cnt+A-1<<'\n';
	
	return	0;
}
