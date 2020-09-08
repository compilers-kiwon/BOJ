#include	<iostream>

using namespace	std;

#define	NUM_OF_CARS	5

char	day;
string	car[NUM_OF_CARS+1];

int		main(void)
{
	cin>>day;
	
	for(int i=1;i<=NUM_OF_CARS;i++)
	{
		cin>>car[i];
	}
	
	int	num_of_violation_cars = 0;
	
	for(int i=1;i<=NUM_OF_CARS;i++)
	{
		if( day == car[i][car[i].length()-1] )
		{
			++num_of_violation_cars;
		}
	}
	cout<<num_of_violation_cars<<endl;
	
	return	0;
}
