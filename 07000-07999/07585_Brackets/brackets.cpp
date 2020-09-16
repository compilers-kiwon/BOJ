#include	<iostream>
#include	<string>
#include	<stack>
#include	<map>

using namespace	std;

map<char,char>	bracket;

void	init_bracket(void)
{
	bracket[']'] = '[';
	bracket[')'] = '(';
	bracket['}'] = '{';
}

int		main(void)
{
	init_bracket();
	
	while(1)
	{
		stack<char>	st;
		string		line;
		int			i;
		char		c;
		
		getline(cin,line);
		
		if( line == "#" )
		{
			break;
		}
		
		for(i=0;i<line.length();i++)
		{
			c = line[i];
			
			if( c=='(' || c=='[' || c=='{' )
			{
				st.push(c);
				continue;
			}
			
			if( c==')' || c==']' || c=='}' )
			{
				char	prev_bracket;
				
				prev_bracket = st.top();
				st.pop();
				
				if( prev_bracket != bracket[c] )
				{
					break;
				}
			}
		}
		
		if( i == line.length() && st.size() == 0 )
		{
			cout<<"Legal\n";
		}
		else
		{
			cout<<"Illegal\n";
		}
	}
	return	0;
}
