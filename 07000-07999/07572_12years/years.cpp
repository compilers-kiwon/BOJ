#include	<iostream>

using namespace	std;

int		ten[] = {6,7,8,9,0,1,2,3,4,5};
char	twelve[] = {'I','J','K','L','A','B','C','D','E','F','G','H'};

int	main(void)
{
	int	N;
	
	cin>>N;
	cout<<twelve[N%12]<<ten[N%10]<<endl;
	
	return	0;		
}
