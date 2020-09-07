#include	<iostream>

using namespace	std;

#define	MAX_BUF_SIZE	100

void	remove_bug(string& code)
{
	int	i,to;
	
	for(i=2,to=code.length();i<to;i++)
	{
		if( code[i] == 'G' && code[i-1] == 'U' && code[i-2] == 'B' )
		{
			code.erase(i-2,3);
			to -= 3;
			i -= 3;
		}
	}
}

int		main(void)
{
	while(!cin.eof())
	{
		string	code;
		
		getline(cin,code);
		
		if( code.length() >= 3 )
		{
			remove_bug(code);
		}
		cout<<code<<'\n';
	}
	
	return	0;
}
