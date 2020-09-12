#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

void	build_new_alphabet_table(map<char,string>& table)
{
	table['a'] = table['A'] = "@";
	table['b'] = table['B'] = "8";
	table['c'] = table['C'] = "(";
	table['d'] = table['D'] = "|)";
	table['e'] = table['E'] = "3";
	table['f'] = table['F'] = "#";
	table['g'] = table['G'] = "6";
	table['h'] = table['H'] = "[-]";
	table['i'] = table['I'] = "|";
	table['j'] = table['J'] = "_|";
	table['k'] = table['K'] = "|<";
	table['l'] = table['L'] = "1";
	table['m'] = table['M'] = "[]\\/[]";
	table['n'] = table['N'] = "[]\\[]";
	table['o'] = table['O'] = "0";
	table['p'] = table['P'] = "|D";
	table['q'] = table['Q'] = "(,)";
	table['r'] = table['R'] = "|Z";
	table['s'] = table['S'] = "$";
	table['t'] = table['T'] = "\'][\'";
	table['u'] = table['U'] = "|_|";
	table['v'] = table['V'] = "\\/";
	table['w'] = table['W'] = "\\/\\/";
	table['x'] = table['X'] = "}{";
	table['y'] = table['Y'] = "`/";
	table['z'] = table['Z'] = "2";
}

void	translate(string& src,map<char,string>& table,string& result)
{
	for(int i=0;i<src.length();i++)
	{
		char&	c = src[i];
		
		if( IN_RANGE('a',c,'z') || IN_RANGE('A',c,'Z') )
		{
			result += table[c];
		}
		else
		{
			result.push_back(c);
		}
	}
}

int		main(void)
{
	string				src,result;
	map<char,string>	table;
	
	build_new_alphabet_table(table);
	
	getline(cin,src);
	translate(src,table,result);
	
	cout<<result<<'\n';
	
	return	0;
}
