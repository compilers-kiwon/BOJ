#include	<iostream>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	N,M;
		
		cin>>N>>M;
		cout<<M*2-N<<' '<<N-M<<endl;
		
		T--;
	}
	return	0;
}
