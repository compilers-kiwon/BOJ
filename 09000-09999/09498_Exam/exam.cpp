#include	<iostream>

using namespace	std;

int	main(void)
{
	int		n;
	char	grade;
	
	cin>>n;
	
	if( n>=90 )
	{
		grade = 'A';
	}
	else if( n>=80 )
	{
		grade = 'B';
	}
	else if( n>=70 )
	{
		grade = 'C';
	}
	else if( n>=60 )
	{
		grade = 'D';
	}
	else
	{
		grade = 'F';
	}
	
	cout<<grade<<endl;
	
	return	0;
}
