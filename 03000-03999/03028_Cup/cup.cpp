#include	<iostream>
#include	<string>

using namespace	std;

#define	NUM_OF_CUPS	3

int	main(void)
{
	int		cup[NUM_OF_CUPS+1];
	string	mix;
	
	cup[1] = 1;
	cup[2] = cup[3] = 0;
	
	cin>>mix;
	
	for(int i=0;i<mix.length();i++)
	{
		switch(mix[i])
		{
			case	'A':
				swap(cup[1],cup[2]);
				break;
			case	'B':
				swap(cup[2],cup[3]);
				break;
			case	'C':
				swap(cup[1],cup[3]);
				break;
			default:
				// do nothing
				break;
		}
	}
	
	for(int i=1;i<=NUM_OF_CUPS;i++)
	{
		if( cup[i] == 1 )
		{
			cout<<i<<endl;
			break;
		}
	}
	return	0;
}
