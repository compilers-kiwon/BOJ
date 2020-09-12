#include	<iostream>

using namespace	std;

#define	NUM_OF_PEOPLE	4

int	main(void)
{
	int	person[NUM_OF_PEOPLE+1];
	int	x,y,r,answer;
	
	for(int i=1;i<=NUM_OF_PEOPLE;i++)
	{
		cin>>person[i];
	}
	cin>>x>>y>>r;
	
	answer = 0;
	
	for(int i=1;i<=NUM_OF_PEOPLE;i++)
	{
		if( x == person[i] )
		{
			answer = i;
			break;
		}
	}
	
	cout<<answer<<endl;
	
	return	0;
}
