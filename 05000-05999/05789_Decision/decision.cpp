#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int	N;
	
	cin>>N;
	
	while(N>0)
	{
		string	str;
		
		cin>>str;
		
		if( str[str.length()/2] == str[str.length()/2-1] )
		{
			cout<<"Do-it\n";
		}
		else
		{
			cout<<"Do-it-Not\n";
		}
		
		N--;
	}
	return	0;
}
