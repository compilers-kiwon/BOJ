#include	<iostream>

using namespace	std;

#define	SPECIAL_MONTH	2
#define	SPECIAL_DAY		18

int	main(void)
{
	int	m,d;
	
	cin>>m>>d;
	
	if( m < SPECIAL_MONTH )
	{
		cout<<"Before\n";
	}
	else if( m > SPECIAL_MONTH )
	{
		cout<<"After\n";
	}
	else
	{
		if( d < SPECIAL_DAY )
		{
			cout<<"Before\n";
		}
		else if( d > SPECIAL_DAY )
		{
			cout<<"After\n";
		}
		else
		{
			cout<<"Special\n";
		}
	}
	
	return	0;
}
