#include	<iostream>
#include	<string>
#include	<map>
#include	<vector>

using namespace	std;

void	build_alphabet_table(string& str,map<char,int>& table)
{
	for(int i=0;i<str.length();i++)
	{
		table[str[i]]++;
	}
}

void	build_str(vector<char>& str,map<char,int>& table,int len,int& cnt)
{
	if( str.size() > len )
	{
		cnt++;
		return;
	}
	
	map<char,int>::iterator	iter;
	
	for(iter=table.begin();iter!=table.end();iter++)
	{
		if( iter->first != str.back() && iter->second > 0 )
		{
			iter->second--;
			str.push_back(iter->first);
			
			build_str(str,table,len,cnt);
			
			str.pop_back();
			iter->second++;
		}
	}
}

int		main(void)
{
	string			word;
	vector<char>	str;
	map<char,int>	table;
	int				cnt;
	
	cin>>word;
	build_alphabet_table(word,table);
	
	cnt = 0;
	str.push_back(' ');
	build_str(str,table,word.length(),cnt);
	
	cout<<cnt<<endl;
	
	return	0;
}
