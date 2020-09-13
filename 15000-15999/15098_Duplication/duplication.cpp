#include	<iostream>
#include	<string>
#include	<set>

using namespace	std;

int	main(void)
{
	set<string>	word_set;
	string		sentence,w;
	bool		no_repeat;
	
	getline(cin,sentence);
	sentence.push_back(' ');
	no_repeat = true;
	
	for(int i=0;i<sentence.length();i++)
	{
		if( sentence[i] == ' ' )
		{
			if( word_set.find(w) == word_set.end() )
			{
				word_set.insert(w);
				w.clear();
			}
			else
			{
				no_repeat = false;
				break;
			}
		}
		else
		{
			w.push_back(sentence[i]);
		}
	}
	
	if( no_repeat == true )
	{
		cout<<"yes\n";
	}
	else
	{
		cout<<"no\n";
	}
	
	return	0;
}
