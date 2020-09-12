#include	<iostream>
#include	<string>

using namespace	std;

#define	NONE	0
#define	BIG		1
#define	SMALL	2

int	main(void)
{
	int		cup[4] = {SMALL,NONE,NONE,BIG};
	string	order;
	int		b,s;
	
	cin>>order;
	
	for(int i=0;i<order.length();i++)
	{
		switch(order[i])
		{
			case	'A':
				swap(cup[0],cup[1]);
				break;
			case	'B':
				swap(cup[0],cup[2]);
				break;
			case	'C':
				swap(cup[0],cup[3]);
				break;
			case	'D':
				swap(cup[1],cup[2]);
				break;
			case	'E':
				swap(cup[1],cup[3]);
				break;
			case	'F':
				swap(cup[2],cup[3]);
				break;
			default:
				// do nothing
				break;	
		}
	}
	
	for(int i=0;i<4;i++)
	{
		if( cup[i] == BIG )
		{
			b = i+1;
		}
		else if( cup[i] == SMALL )
		{
			s = i+1;
		}
	}
	cout<<s<<endl<<b<<endl;
	
	return	0;
}
