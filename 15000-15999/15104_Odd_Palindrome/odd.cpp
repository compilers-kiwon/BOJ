#include	<iostream>
#include	<string>

using namespace	std;

bool	is_palindrome(string& str,int head,int tail)
{
	bool	flag;
	
	for(flag=true;head<tail;head++,tail--)
	{
		if( str[head] != str[tail] )
		{
			flag = false;
			break;
		}
	}
	
	return	flag;
}

int		main(void)
{
	string	str;
	bool	result;
	
	cin>>str;
	result = true;
	
	for(int i=0;i<str.length()&&result==true;i++)
	{
		for(int j=1;i+j<str.length()&&result==true;j+=2)
		{
			result = !(is_palindrome(str,i,i+j));
		}
	}
	
	if( result == true )
	{
		cout<<"Odd.\n";
	}
	else
	{
		cout<<"Or not.\n";
	}
	
	return	0;
}
