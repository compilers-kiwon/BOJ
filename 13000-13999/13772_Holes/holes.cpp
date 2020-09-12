#include	<iostream>
#include	<string>

using namespace	std;

#define	TABLE_SIZE	0x100 

void	init(int* table)
{
	for(int i=0;i<TABLE_SIZE;i++)
	{
		table[i] = 0;
	}
	
	table['A'] = 1;
	table['B'] = 2;
	table['D'] = 1;
	table['O'] = 1;
	table['P'] = 1;
	table['Q'] = 1;
	table['R'] = 1;
}

int		main(void)
{
	int	N,table[TABLE_SIZE];
	
	init(table);
	cin>>N;getchar();
	
	for(int i=1;i<=N;i++)
	{
		string	str;
		int		cnt;
		
		cnt = 0;
		getline(cin,str);
		
		for(int j=0;j<str.length();j++)
		{
			cnt += table[str[j]];
		}
		
		cout<<cnt<<'\n';
	}
	
	return	0;
}
