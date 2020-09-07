#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	char2int(C)	((int)((C)-'A'))

int	main(void)
{
	vector<bool>	table(char2int('Z')+1,false);
	
	table[char2int('C')] = table[char2int('A')] = table[char2int('M')] = table[char2int('B')]
	= table[char2int('R')] = table[char2int('I')] = table[char2int('D')] = table[char2int('G')]
	= table[char2int('E')] = true;
	
	string	str;
	
	cin>>str;
	
	for(int i=0;i<str.length();i++)
	{
		if( table[char2int(str[i])] == false )
		{
			cout<<str[i];	
		}	
	}
	cout<<endl;
	
	return	0;	
}
