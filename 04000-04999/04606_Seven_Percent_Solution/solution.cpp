#include	<iostream>
#include	<map>
#include	<string>

using namespace	std;

int	main(void)
{
	map<char,string>	table;
	char				c;
	
	table[' '] = "%20";
	table['!'] = "%21";
	table['$'] = "%24";
	table['%'] = "%25";
	table['('] = "%28";
	table[')'] = "%29";
	table['*'] = "%2a";
	
	while( scanf("%c",&c) != EOF )
	{
		if( c == '#' )
		{
			break;
		}
		
		if( table[c] != "" )
		{
			cout<<table[c];
		}
		else
		{
			cout<<c;
		}
	}
	
	return	0;
}
