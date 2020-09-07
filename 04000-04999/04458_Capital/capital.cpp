#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

void	init_table(map<char,char>& table)
{
	for(char c='a',C='A';c<='z';c++,C++)
	{
		table[c] = C;
	}
}

int		main(void)
{
	map<char,char>	capital;
	int				N;
	string			str;
	
	init_table(capital);
	
	cin>>N;getchar();
	
	for(int i=1;i<=N;i++)
	{
		getline(cin,str);
		
		if( !('A'<=str[0] && str[0]<='Z') )
		{
			str[0] = capital[str[0]];
		}
		cout<<str<<endl;
	}
	
	return	0;
}
