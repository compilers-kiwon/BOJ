#include	<iostream>
#include	<string>

using namespace std;

int	main(void)
{
	string	name;
	
	cin>>name;
	
	for(int i=0,len=name.length();i<len;i++)
	{
		char	c = name[i];
		
		if( c>='A' && c<='Z' )
		{
			cout<<c;
		}
	}
	return	0;
}
