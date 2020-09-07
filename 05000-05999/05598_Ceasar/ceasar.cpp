#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

map<char,char>	table;

void	init_table(void)
{
	for(char c='D';c<='Z';c++)
	{
		table[c] = c-3;
	}
	table['A'] = 'X';table['B'] = 'Y';table['C'] = 'Z';
}

int		main(void)
{
	string	str;
	
	cin>>str;
	init_table();
	
	for(int i=0;i<str.length();i++)
	{
		cout<<table[str[i]];
	}
	cout<<endl;
	
	return	0;
}
