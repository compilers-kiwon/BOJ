#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	string	str;
	
	getline(cin,str);
	
	for(int i=0;i<str.length()-2;i++)
	{
		char&	c1 = str[i];
		
		if( c1 == '\0' )
		{
			continue;
		}
		
		char&	c2 = str[i+1];
		char&	c3 = str[i+2];
		
		if( c1=='a' || c1=='e' || c1=='i' || c1=='o' || c1=='u' )
		{
			if( c2 == 'p' && c3 == c1 )
			{
				c2 = c3 = '\0';
			}
		}
		cout<<c1;
	}
	
	if( str[str.length()-2] != '\0' )
	{
		cout<<str[str.length()-2];
	}
	
	if( str[str.length()-1] != '\0' )
	{
		cout<<str[str.length()-1];
	}
	
	return	0;
}
