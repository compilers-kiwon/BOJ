#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	bool	cup[3+1];
	string	str;
	
	cup[1] = true;
	cup[2] = cup[3] = false;
	
	cin>>str;
	
	for(int i=0;i<str.length();i++)
	{
		char&	c = str[i];
		
		switch(c)
		{
			case	'A':
				swap(cup[1],cup[2]);
				break;
			case	'B':
				swap(cup[2],cup[3]);
				break;
			case	'C':
				swap(cup[3],cup[1]);
				break;
		}
	}
	
	for(int i=1;i<=3;i++)
	{
		if( cup[i] == true )
		{
			cout<<i<<'\n';
			break;
		}
	}
	
	return	0;
}
