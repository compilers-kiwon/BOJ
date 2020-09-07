#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	string	str;
	int		b,t;
	
	cin>>str;
	b = t = 0;
	
	for(int i=0;i<str.length()-1;i++)
	{
		if( str[i]=='(' && str[i+1]=='(' )
		{
			b++;
		}
		
		if( str[i]==')' && str[i+1]==')' )
		{
			t += b;
		}
	}
	
	cout<<t<<'\n';
	
	return	0;
}
