#include	<iostream>
#include	<string>

using namespace	std;

int	count_vowel(string& str)
{
	int	cnt,i;
	
	for(cnt=i=0;i<str.length();i++)
	{
		if( str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
			str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' )
		{
			cnt++;
		}
	}
	
	return	cnt;
}

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
		
		cout<<count_vowel(str)<<endl;
	}
	
	return	0;
}
