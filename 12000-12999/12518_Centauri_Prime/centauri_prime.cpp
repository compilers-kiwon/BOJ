#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		string	name;
		
		cin>>name;
		cout<<"Case #"<<i<<": "<<name<<" is ruled by ";
		
		char&	back = name[name.length()-1];
		
		switch(back)
		{
			case	'a':
			case	'e':
			case	'i':
			case	'o':
			case	'u':
			case	'A':
			case	'E':
			case	'I':
			case	'O':
			case	'U':
				cout<<"a queen.\n";
				break;
			case	'y':
			case	'Y':
				cout<<"nobody.\n";
				break;
			default:
				cout<<"a king.\n";
				break;	
		}
	}
	
	return	0;
}
