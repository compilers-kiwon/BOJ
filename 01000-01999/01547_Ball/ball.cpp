#include	<iostream>

using namespace	std;

#define	NUM_OF_CUPS	3

int	main(void)
{
	int	cup[NUM_OF_CUPS+1];
	
	cup[1] = 1;
	cup[2] = 2;
	cup[3] = 3;
	
	int	M;
	
	cin>>M;
	
	for(int i=1;i<=M;i++)
	{
		int	X,Y;
		
		cin>>X>>Y;
		swap(cup[X],cup[Y]);
	}
	
	int result;
	
	if( cup[1] == 1 )
	{
		result = 1;
	}
	else if( cup[2] == 1 )
	{
		result = 2;
	}
	else
	{
		result = 3;
	}
	cout<<result<<endl;
	
	return	0;
}
