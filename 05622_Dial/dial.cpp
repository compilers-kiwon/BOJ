#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	FIXED_SECONDS	2

map<char,int>	time_table;

void	init_time_table(void)
{
	time_table['A'] = time_table['B'] = time_table['C'] = 1;
	time_table['D'] = time_table['E'] = time_table['F'] = 2;
	time_table['G'] = time_table['H'] = time_table['I'] = 3;
	time_table['J'] = time_table['K'] = time_table['L'] = 4;
	time_table['M'] = time_table['N'] = time_table['O'] = 5;
	time_table['P'] = time_table['Q'] = time_table['R'] = time_table['S'] = 6;
	time_table['T'] = time_table['U'] = time_table['V'] = 7;
	time_table['W'] = time_table['X'] = time_table['Y'] = time_table['Z'] = 8;
}

int		main(void)
{
	string	word;
	int		time,i;
	
	init_time_table();
	
	cin>>word;
	
	for(i=0,time=FIXED_SECONDS*word.length();i<word.length();i++)
	{
		time += time_table[word[i]];
	}
	cout<<time<<endl;
	
	return	0;
}
