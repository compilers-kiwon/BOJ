#include	<iostream>
#include	<string>

using namespace	std;

bool	is_palindrome(string& number)
{
	bool	result;
	int		head,tail;
	
	for(result=true,head=0,tail=number.length()-1;head<tail;head++,tail--)
	{
		if( number[head] != number[tail] )
		{
			result = false;
			break;
		}
	}
	
	return	result;
}

int		main(void)
{
	while(1)
	{
		string	n;
		
		cin>>n;
		
		if( n == "0" )
		{
			break;
		}
		
		if( is_palindrome(n) == true )
		{
			cout<<"yes\n";
		}
		else
		{
			cout<<"no\n";
		}
	}
	
	return	0;
}
