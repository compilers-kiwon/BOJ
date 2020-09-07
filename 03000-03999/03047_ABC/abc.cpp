#include	<iostream>
#include	<algorithm>
#include	<string>
#include	<map>

using namespace	std;

#define	NUMBERS	3

int	main(void)
{
	int				n[NUMBERS];
	map<char,int>	table;
	string			str;
	
	for(int i=0;i<NUMBERS;i++)
	{
		cin>>n[i];
	}
	sort(&n[0],&n[NUMBERS]);
	
	for(int i=0;i<NUMBERS;i++)
	{
		table['A'+(char)i] = n[i];
	}
	
	cin>>str;
	
	for(int i=0;i<NUMBERS;i++)
	{
		cout<<table[str[i]]<<' ';
	}
	cout<<endl;
	
	return	0;
}
