#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

int	main(void)
{
	while(1)
	{
		string	str;
		
		getline(cin,str);
		
		if( str == "#" )
		{
			break;
		}
		
		map<char,bool>	upper,lower;
		
		for(int i=0;i<str.length();i++)
		{
			if( str[i]>='A' && str[i]<='Z' )
			{
				upper[str[i]] = true;
			}
			else if( str[i]>='a' && str[i]<='z' )
			{
				lower[str[i]] = true;
			}
		}
		
		int	cnt = 0;
		
		for(char c='a',C='A';c<='z';c++,C++)
		{
			if( upper[C] == true || lower[c] == true )
			{
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return	0;
}
