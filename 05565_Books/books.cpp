#include	<iostream>

using namespace	std;

#define	NUM_OF_AVAILABLE_BOOKS	9

int	main(void)
{
	int	sum;
	
	cin>>sum;
	
	for(int i=1;i<=NUM_OF_AVAILABLE_BOOKS;i++)
	{
		int	price;
		
		cin>>price;
		sum -= price;
	}
	cout<<sum<<endl;
	
	return	0;
}
