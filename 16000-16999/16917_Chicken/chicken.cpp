#include	<iostream>

using namespace	std;

int	main(void)
{
	int A,B,C,X,Y,cost;
	
	cin>>A>>B>>C>>X>>Y;
	
	for(cost=0;X!=0||Y!=0;)
	{
		if( X!=0 && Y!=0 )
		{
			cost += min(2*C,A+B);
			X--;Y--;
		}
		else if( X != 0 )
		{
			cost += min(2*C,A);
			X--;
		}
		else // Y != 0
		{
			cost += min(2*C,B);
			Y--;
		}
	}
	
	cout<<cost<<'\n';
	
	return	0;
}
