#include	<iostream>
#include	<string>
#include	<stack>

using namespace	std;

#define	WAIT_OPENING	0
#define	WAIT_CLOSING	1

void	get_tag(string& src,string& dst)
{
	for(int i=0;i<src.length()&&src[i]!=' ';i++)
	{
		dst.push_back(src[i]);
	}
}

bool	parse(string& str)
{
	stack<string>	st;
	string			s;
	
	for(int i=0,state=WAIT_OPENING;i<str.length();i++)
	{
		char&	c = str[i];
		
		if( state == WAIT_OPENING )
		{
			if( c == '<' )
			{
				state = WAIT_CLOSING;
			}
		}
		else
		{
			if( c == '>' )
			{
				state = WAIT_OPENING;
				
				if( s[0]!='/' && s[s.length()-1]=='/' )
				{
					s.clear();
					continue;
				}
				
				string	t;
				
				get_tag(s,t);
				s.clear();
				
				if( t[0] == '/' )
				{
					t.erase(t.begin());
					
					if( st.empty()==true || t!=st.top() )
					{
						return	false;
					}
					
					st.pop();
				}
				else
				{
					st.push(t);
				}
			}
			else
			{
				s.push_back(c);
			}
		}
	}
	
	if( !st.empty() )
	{
		return	false;
	}
	
	return	true;
}

int		main(void)
{
	for(;;)
	{
		string	str;
		
		getline(cin,str);
		
		if( str == "#" )
		{
			break;
		}
		
		if( parse(str) == true )
		{
			cout<<"legal\n";
		}
		else
		{
			cout<<"illegal\n";
		}
	}
	
	return	0;
}
