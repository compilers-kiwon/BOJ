#include	<iostream>
#include	<string>

using namespace	std;

#define	get_index(c)	((int)((c)-'A'))
#define	NUM_OF_CHARS	26

int	main(void)
{
	int		S,ptr;
	bool	appeared[NUM_OF_CHARS];
	string	assigned;
	
	cin>>S;getchar();
	
	for(char c='A';c<='Z';c++)
	{
		appeared[get_index(c)] = false;
	}
	
	for(int row=1;row<=S;row++)
	{
		string	str;
		
		getline(cin,str);
		
		for(int i=0;i<str.length();i++)
		{
			char&	c = str[i];
			
			if( str[i]!=' ' && appeared[get_index(c)]==false )
			{
				appeared[get_index(c)] = true;
				assigned.push_back(c);
			}
		}
	}
	
	cout<<assigned<<'\n';
	
	return	0;
}
