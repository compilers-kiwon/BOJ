#include	<iostream>

using namespace	std;

bool	is_palindrome(string& str)
{
	bool	ret;
	int		head,tail;
	
	for(ret=true,head=0,tail=str.length()-1;head<tail;head++,tail--)
	{
		if( str[head] != str[tail] )
		{
			ret = false;
			break;
		}
	}
	
	return	ret;
}

int		main(void)
{
	for(;;)
	{
		string	str;
		
		cin>>str;
		
		if( str == "#" )
		{
			break;
		}
		
		bool	found;
		
		found = false;
		
		for(int i=0;i<str.length();i++)
		{
			char	c;
			
			c = str[i];
			str.erase(i,1);
			
			if( is_palindrome(str) == true )
			{
				found = true;
				break;
			}
			
			str.insert(i,1,c);
		}
		
		if( found == true )
		{
			cout<<str<<'\n';
		}
		else
		{
			cout<<"not possible\n";
		}
	}
	
	return	0;
}
