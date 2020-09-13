#include	<iostream>
#include	<string>

using namespace	std;

int	count[0x100];

int	main(void)
{
	string	line;
	
	getline(cin,line);
	
	for(int i=0;i<line.length();i++)
	{
		count[line[i]]++;
	}
	
	for(char upper='A',lower='a';upper<='Z';upper++,lower++)
	{
		string	s(count[upper]+count[lower],'*');
		
		cout<<upper<<" | "<<s<<'\n';
	}
	
	return	0;
}
