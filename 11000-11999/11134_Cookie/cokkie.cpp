#include	<iostream>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	N,C;
		
		cin>>N>>C;
		cout<<N/C+((N%C==0)?0:1)<<endl;
		T--;
	}
	return	0;
}
