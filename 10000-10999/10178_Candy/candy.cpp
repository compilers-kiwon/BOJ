#include	<iostream>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	c,b;
		
		cin>>c>>b;
		printf("You get %d piece(s) and your dad gets %d piece(s).\n",c/b,c%b);
		T--;
	}
	return	0;
}
