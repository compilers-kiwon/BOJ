#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N,cute,not_cute,i;
	
	cin>>N;
	
	for(i=1,cute=not_cute=0;i<=N;i++)
	{
		int	v;
		
		cin>>v;
		
		if( v == 0 )
		{
			++not_cute;
		}
		else
		{
			++cute;
		}
	}
	cout<<"Junhee is "<<((cute>not_cute)?"cute":"not cute")<<"!\n";
	
	return	0;
}
