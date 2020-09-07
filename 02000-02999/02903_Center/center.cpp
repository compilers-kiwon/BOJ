#include	<iostream>
#include	<cmath>

using namespace	std;

int	main(void)
{
	int	N,num_of_points_at_a_line;
	
	cin>>N;
	num_of_points_at_a_line = pow(2,N)+1;
	cout<<num_of_points_at_a_line*num_of_points_at_a_line<<endl;
	
	return	0;
}
