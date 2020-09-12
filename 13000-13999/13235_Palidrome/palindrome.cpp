#include	<iostream>
#include	<string>

using namespace	std;

bool	is_palindrome(string& word)
{
	bool	result;
	int		head,tail;
	
	for(result=true,head=0,tail=word.length()-1;head<tail;head++,tail--)
	{
		if( word[head] != word[tail] )
		{
			result = false;
			break;
		}
	}
	
	return	result;
}

int		main(void)
{
	string	word;
	
	cin>>word;
	
	if( is_palindrome(word) == true )
	{
		cout<<"true\n";
	}
	else
	{
		cout<<"false\n";
	}
	
	return	0;
}
