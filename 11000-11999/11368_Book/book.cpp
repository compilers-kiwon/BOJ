#include	<iostream>
#include	<cmath>

using namespace	std;


typedef	unsigned long long uint64;

int	main(void)
{
	for(;;)
	{
		uint64	C,W,L,P;
		
		cin>>C>>W>>L>>P;
		
		if( C==0 && W==0 && L==0 && P==0 )
		{
			break;
		}
		
		cout<<(uint64)pow(C,W*L*P)<<'\n';
	}
	
	return	0;
}
