#include	<iostream>
#include	<map>
#include	<string>

using namespace	std;

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

void	init(map<char,char>& table)
{
	int		k,s;
	string	lower = "abcdefghijklmnopqrstuvwxyz";
	string	upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	cin>>k>>s;getchar();
	
	k %= 26;
	
	for(int i=0;i<26;i++)
	{
		table[lower[i]] = lower[(i+k)%26];
		table[upper[i]] = upper[(i+k)%26];
	}
}

int		main(void)
{
	map<char,char>	table;
	string			str,cipher;
	
	init(table);
	getline(cin,str);
	
	for(int i=0;i<str.length();i++)
	{
		char	c;
		
		if( IN_RANGE('a',str[i],'z') || IN_RANGE('A',str[i],'Z') )
		{
			c = table[str[i]];
		}
		else
		{
			c = str[i];
		}
		
		cipher.push_back(c);
	}
	
	cout<<cipher<<'\n';
	
	return	0;
}
