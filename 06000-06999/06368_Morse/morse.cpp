#include	<iostream>
#include	<string>
#include	<map>
#include	<vector>

using namespace	std;

map<char,string>	table;

void	init(void)
{
	table['A'] = ".-";
	table['H'] = "....";
	table['O'] = "---";
	table['V'] = "...-";
	table['B'] = "-...";
	table['I'] = "..";
	table['P'] = ".--.";
	table['W'] = ".--";
	table['C'] = "-.-.";
	table['J'] = ".---";
	table['Q'] = "--.-";
	table['X'] = "-..-";
	table['D'] = "-..";
	table['K'] = "-.-";
	table['R'] = ".-.";
	table['Y'] = "-.--";
	table['E'] = ".";
	table['L'] = ".-..";
	table['S'] = "...";
	table['Z'] = "--..";
	table['F'] = "..-.";
	table['M'] = "--";
	table['T'] = "-";
	table['G'] = "--.";
	table['N'] = "-.";
	table['U'] = "..-";
	table['_'] = "..--";
	table['.'] = "---.";
	table[','] = ".-.-";
	table['?'] = "----";
}

void	build_length_table(const string& str,vector<int>& length_table,string& m)
{
	for(int i=0;i<str.length();i++)
	{
		m += table[str[i]];
		length_table.push_back(table[str[i]].length());
	}
	
	for(int h=0,t=length_table.size()-1;h<t;h++,t--)
	{
		swap(length_table[h],length_table[t]);
	}
}

void	build_new_string(const string& m,vector<int>& length_table,string& str)
{
	for(int i=0,ptr=0;i<length_table.size();i++)
	{
		string						m_code;
		map<char,string>::iterator	it;
		
		m_code = m.substr(ptr,length_table[i]);
	
		for(it=table.begin();it!=table.end();it++)
		{
			if( it->second == m_code )
			{
				str.push_back(it->first);
			}
		}
		
		ptr += length_table[i];
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N;
	
	init();
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		string		str,morse;
		vector<int>	len;
		
		cin>>str;
		build_length_table(str,len,morse);
		
		str.clear();
		build_new_string(morse,len,str);
		
		cout<<i<<": "<<str<<'\n';
	}
	
	return	0;
}
