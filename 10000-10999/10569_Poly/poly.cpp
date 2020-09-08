#include	<iostream>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	V,E;
		
		cin>>V>>E;
		cout<<2-V+E<<endl;
		
		T--;
	}
	return	0;
}
