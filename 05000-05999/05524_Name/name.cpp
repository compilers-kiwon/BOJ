#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

int	main(void)
{
	map<char,char>	convert;
	
	for(char C='A',c='a';C<='Z';C++,c++)
	{
		convert[C] = c;
	}
	
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		string name;
		
		cin>>name;
		
		for(int j=0;j<name.length();j++)
		{
			if( convert[name[j]] != 0 )
			{
				cout<<convert[name[j]];
			}
			else
			{
				cout<<name[j];
			}
		}
		cout<<endl;
	}
	
	return	0;
}
