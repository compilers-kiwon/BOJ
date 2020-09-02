#include	<iostream>
#include	<string>
#include	<stack>

using namespace	std;

bool	is_balanced(string& str)
{
	bool		result;
	stack<char>	st;
	
	result = true;
	
	for(int i=0;i<str.length()&&result==true;i++)
	{
		char&	c = str[i];
		
		switch(c)
		{
			case	'(':
			case	'[':
				st.push(c);
				break;
			case	')':
				if( !st.empty() && st.top() == '(' )
				{
					st.pop();
				}
				else
				{
					result = false;
				}
				break;
			case	']':
				if( !st.empty() && st.top() == '[' )
				{
					st.pop();
				}
				else
				{
					result = false;
				}
				break;
			default:
				// do nothing
				break;
		}
	}
	
	if( result == true && st.size() != 0 )
	{
		result = false;
	}
	
	return	result;
}

int		main(void)
{
	while(1)
	{
		string	str;
		
		getline(cin,str);
		
		if( str == "." )
		{
			break;
		}
		
		if( is_balanced(str) == true )
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
