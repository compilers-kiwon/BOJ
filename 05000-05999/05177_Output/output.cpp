#include	<iostream>
#include	<string>

using namespace	std;

#define	in_range(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
#define	make_upper(c)		((c)-(char)32)

bool	is_special_character(char c)
{
	return	(c=='('||c==')'||c=='.'||c==','||c==':');
}

void	preprocessing(string& src,string& result)
{
	for(int i=0;i<src.length();i++)
	{
		char&	c = src[i];
		
		if( in_range('a',c,'z') == true )
		{
			c = make_upper(c);
			continue;
		}
		
		if( c=='(' || c=='[' || c=='{' )
		{
			c = '(';
			continue;
		}
		
		if( c==')' || c==']' || c=='}' )
		{
			c = ')';
			continue;
		}
		
		if( c == ';' )
		{
			c = ',';
			continue;
		}
	}
	
	string	sub,tmp;
	
	src.push_back(' ');
	
	for(int i=0;i<src.length();i++)
	{
		char&	c = src[i];
		
		if( c == ' ' )
		{
			if( sub.empty() != true )
			{
				tmp += sub+" ";
				sub.clear();
			}
		}
		else
		{
			sub.push_back(c);
		}
	}
	
	for(int i=0;i<tmp.length();i++)
	{
		char&	c = tmp[i];
		
		switch(c)
		{
			case	'(':
			case	')':
			case	'.':
			case	',':
			case	':':
				if( !result.empty() && result[result.length()-1]==' ' )
				{
					result[result.length()-1] = c;
				}
				else
				{
					result.push_back(c);
				}
				break;
			case	' ':
				if( is_special_character(result[result.length()-1]) == true )
				{
					// do nothing
				}
				else
				{
					result.push_back(c);
				}
				break;
			default:
				result.push_back(c);
				break;
		}
	}
	
	if( !result.empty() )
	{
		int	i,cnt;
		
		for(i=result.length()-1,cnt=0;i>=0;i--,cnt++)
		{
			if( result[i] != ' ' )
			{
				break;
			}
		}
		
		if( cnt > 0 )
		{
			result.erase(i+1,cnt);
		}
	}
}

int		main(void)
{
	int	N;
	
	cin>>N;getchar();
	
	for(int i=1;i<=N;i++)
	{
		string	s1,s2,r1,r2;
		
		getline(cin,s1);
		getline(cin,s2);
		
		preprocessing(s1,r1);
		preprocessing(s2,r2);
		
		cout<<"Data Set "<<i<<": ";
		
		if( r1 == r2 )
		{
			cout<<"equal\n\n";
		}
		else
		{
			cout<<"not equal\n\n";
		}
	}
	
	return	0;
}
