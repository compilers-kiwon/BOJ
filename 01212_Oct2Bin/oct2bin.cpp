#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

map<char,string>	Oct2Bin_table;

void	init_table(void)
{
	Oct2Bin_table['0'] = "000";
	Oct2Bin_table['1'] = "001";
	Oct2Bin_table['2'] = "010";
	Oct2Bin_table['3'] = "011";
	Oct2Bin_table['4'] = "100";
	Oct2Bin_table['5'] = "101";
	Oct2Bin_table['6'] = "110";
	Oct2Bin_table['7'] = "111";
}

int		main(void)
{
	init_table();
	
	string	oct,bin;
	
	cin>>oct;
	
	if( oct[0] == '0' )
	{
		bin = "0";
	}
	else if( oct[0] == '1' )
	{
		bin = "1";
	}
	else if( oct[0] == '2' )
	{
		bin = "10";
	}
	else if( oct[0] == '3' )
	{
		bin = "11";
	}
	else
	{
		bin = Oct2Bin_table[oct[0]];
	}
	
	if( oct.length() == 1 )
	{
		cout<<bin<<endl;
		return	0;
	}
	
	for(int i=1;i<oct.length();i++)
	{
		bin += Oct2Bin_table[oct[i]];
	}
	cout<<bin<<endl;
	
	return	0;
}
