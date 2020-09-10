#include	<iostream>
#include	<string>

using namespace	std;

bool	is_valid(char c,string& behind,string& msg)
{
	bool	ret,used[0x100];
	
	for(char i='A';i<='Z';i++)
	{
		used[i] = false;
	}
	
	for(int i=0;i<behind.length();i++)
	{
		used[behind[i]] = true;
	}
	
	ret = false;
	
	for(int i=0;i<msg.length();i++)
	{
		char&	n = msg[i];
		
		if( n == c )
		{
			ret = true;
			msg.erase(0,i+1);
			
			break;
		}
		
		if( used[n] == true )
		{
			break;
		}
	}
	
	return	ret;
}

int	main(void)
{
	string	password,message;
	bool	result;
	
	cin>>password>>message;
	result = true;
	
	for(;result==true&&password.length()!=0;)
	{
		char	c;
		
		c = password[0];
		password.erase(0,1);
		result = is_valid(c,password,message);
	}
	
	if( result == true )
	{
		cout<<"PASS\n";
	}
	else
	{
		cout<<"FAIL\n";
	}
	
	return	0;
}
