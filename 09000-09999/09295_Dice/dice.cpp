#include	<iostream>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		int	d1,d2;
		
		cin>>d1>>d2;
		cout<<"Case "<<i<<": "<<d1+d2<<endl;
	}
	return	0;
}
