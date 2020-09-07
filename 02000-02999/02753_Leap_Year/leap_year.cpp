#include	<iostream>

using namespace std;

bool	is_leap_year(int year)
{
	bool	result;
	
	if( (year%4==0) && (year%100!=0 || year%400==0) )
	{
		result = true;
	}
	else
	{
		result = false;
	}
	return	result;
}

int		main(void)
{
	int	year,result;
	
	cin>>year;
	
	if( is_leap_year(year) == true )
	{
		result = 1;
	}
	else
	{
		result = 0;
	}
	cout<<result<<endl;
	
	return	0;
}
