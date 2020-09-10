#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	string	str;
	
	while(1)
	{
		getline(cin,str);
		
		if( str == "END" )
		{
			break;
		}
		
		for(int i=str.length()-1;i>=0;i--)
		{
			cout<<str[i];
		}
		cout<<endl;
	}
	return	0;
}
