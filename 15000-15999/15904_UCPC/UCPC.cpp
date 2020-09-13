#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	1000

const string	abbr = "UCPC";

void	check_str(vector<bool>&	state,string& str)
{
	for(int i=0;i<str.length();i++)
	{
		for(int j=0;j<abbr.length();j++)
		{
			if( str[i] == abbr[j] )
			{
				if( j==0 || state[j-1]==true )
				{
					state[j] = true;
				}
			}
		}
	}
}

int		main(void)
{
	string			str;
	vector<bool>	state;
	
	getline(cin,str);
	state.resize(abbr.length(),false);
	
	check_str(state,str);
	
	if( state.back() == true )
	{
		cout<<"I love UCPC\n";
	}
	else
	{
		cout<<"I hate UCPC\n";
	}
	
	return	0;
}
