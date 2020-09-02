#include	<iostream>

using namespace	std;

int	main(void)
{
	for(int i=1;;i++)
	{
		int	L,P,V;
		
		cin>>L>>P>>V;
		
		if( L==0 && P==0 && V==0 )
		{
			break;
		}
		
		printf("Case %d: %d\n",i,(V/P)*L+min(V%P,L));
	}
	
	return	0;
}
