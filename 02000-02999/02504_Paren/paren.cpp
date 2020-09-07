#include	<iostream>
#include	<string>
#include	<stack>

using namespace	std;

int	main(void)
{
	stack<char>	st;
	string		str;
	int			i;
	stack<int>	value;
	
	cin>>str;
	
	for(i=0;i<str.length();i++)
	{
		char	c,prev;
		int		sub;
		
		c = str[i];
		
		if( c == '(' || c == '[' )
		{
			st.push(c);
			value.push(1);
		}
		else if( c == ')' || c == ']' )
		{
			if( st.size() == 0 )
			{
				break;
			}
			
			prev = st.top();
			
			if( prev == '(' && c == ')' )
			{
				sub = 2;
			}
			else if( prev == '[' && c == ']' )
			{
				sub = 3;
			}
			else
			{
				break;
			}
			
			st.pop();
			
			int	v = 0;
			
			while( value.top() != 1 )
			{
				v += value.top();
				value.pop();
			}
			value.pop();
			
			if( v == 0 )
			{
			 	v = 1;
			}
			v *= sub;
			
			value.push(v); 
		}
		else
		{
			break;
		}
	}
	
	if( i != str.length() || st.size() != 0 )
	{
		cout<<"0\n";
	}
	else
	{
		int	sum = 0;
		
		while( value.size() != 0 )
		{
			sum += value.top();
			value.pop();
		}
		cout<<sum<<endl;
	}
	
	return	0;
}
