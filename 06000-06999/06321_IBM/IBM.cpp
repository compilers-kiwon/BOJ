#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

int	main(void)
{
	map<char,char>	table;
	
	for(char c1='A',c2='B';c1<'Z';c1++,c2++)
	{
		table[c1] = c2;
	}
	table['Z'] = 'A';
	
	int	n;
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		string	name;
		
		cin>>name;
		
		cout<<"String #"<<i<<endl;
		
		for(int i=0;i<name.length();i++)
		{
			cout<<table[name[i]];
		}
		cout<<endl<<endl;
	}
	
	return	0;
}
