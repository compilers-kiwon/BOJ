#include	<iostream>
#include	<string>

using namespace	std;

#define	NUM_OF_USELESS	10

const string	useless[NUM_OF_USELESS] = {"i","pa","te","ni","niti","a","ali","nego","no","ili"};
const string	upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

#define	get_index(c)	((int)((c)-'a'))

bool	is_useless(string& str)
{
	for(int i=0;i<NUM_OF_USELESS;i++)
	{
		if( str == useless[i] )
		{
			return	true;
		}
	}
	
	return	false;
}

int		main(void)
{
	string	abb;
	
	for(int i=1;;i++)
	{
		string	word;
		
		cin>>word;
		
		if( word == "" )
		{
			break;
		}
		
		if( i == 1 )
		{
			abb.push_back(upper[get_index(word[0])]);
		}
		else
		{
			if( is_useless(word) == false )
			{
				abb.push_back(upper[get_index(word[0])]);
			}
		}
	}
	
	cout<<abb<<'\n';
	
	return	0;
}
