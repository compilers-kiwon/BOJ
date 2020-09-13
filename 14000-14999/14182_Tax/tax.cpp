#include	<iostream>

using namespace	std;

int	main(void)
{
	cin.sync_with_stdio(false);
	
	while(1)
	{
		int	income,tax;
		
		cin>>income;
		
		if( income == 0 )
		{
			break;
		}
		
		if( income <= 1000000 )
		{
			tax = 0;
		}
		else if( 1000000<income && income<=5000000 )
		{
			tax = income/10;
		}
		else
		{
			tax = income/5;
		}
		
		cout<<income-tax<<'\n';
	}
	
	return	0;
}
