#include	<iostream>
#include	<string>

using namespace	std;

char	rot13(char c)
{
	if( !('a'<=c && c<='z') && !('A'<=c && c<='Z') )
	{
		return	c;
	}
	
	char	r;
	
	if( 'a'<=c && c<='z' )
	{
		r = 'a';
	}
	else
	{
		r = 'A';
	}
	
	return	((c-r+13)%26)+r;
}

int		main(void)
{
	string	str;
	
	getline(cin,str);
	
	for(int i=0;i<str.length();i++)
	{
		cout<<rot13(str[i]);
	}
	return	0;
}
