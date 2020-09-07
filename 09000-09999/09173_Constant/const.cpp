#include	<iostream>
#include	<string>

using namespace	std;

#define	HEX	16
#define	OCT	8
#define	BIN	2
#define	DEC	10

#define	BYTE	0
#define	WORD	1
#define	LONG	2
#define	QUAD	3
#define	MAX_DIR	4

const string	directive[MAX_DIR] = {".byte\t",".word\t",".long\t",".quad\t"};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int		get_base(string& d)
{
	char&	c = d[d.length()-1];
	int		ret;
	
	if( c == 'h' )
	{
		ret = HEX;
	}
	else if( c == 'b' )
	{
		ret = BIN;
	}
	else if( c == 'o' )
	{
		ret = OCT;
	}
	else	// c=='d' || nothing
	{
		ret = DEC;
	}
	
	return	ret;
}

int		get_directive(string& d)
{
	int	ret;
	
	if( d == "db" )
	{
		ret = BYTE;
	}
	else if( d == "dw" )
	{
		ret = WORD;
	}
	else if( d == "dd" )
	{
		ret = LONG;
	}
	else
	{
		ret = QUAD;
	}
	
	return	ret;
}

void	bin2hex(string& in,string& out)
{
	if( in.length()%4 != 0 )
	{
		int	t;
		
		t = 4-(in.length()%4);
		
		for(int i=1;i<=t;i++)
		{
			in.insert(in.begin(),'0');
		}
	}
	
	for(int i=0;i<in.length();i+=4)
	{
		string	f;
		char	c;
		
		f = in.substr(i,4);
		
		if( f == "0000")
		{
			c = '0';
		}
		else if( f == "0001" )
		{
			c = '1';
		}
		else if( f == "0010" )
		{
			c = '2';
		}
		else if( f == "0011" )
		{
			c = '3';
		}
		else if( f == "0100" )
		{
			c = '4';
		}
		else if( f == "0101" )
		{
			c = '5';
		}
		else if( f == "0110" )
		{
			c = '6';
		}
		else if( f == "0111" )
		{
			c = '7';
		}
		else if( f == "1000" )
		{
			c = '8';
		}
		else if( f == "1001" )
		{
			c = '9';
		}
		else if( f == "1010" )
		{
			c = 'a';
		}
		else if( f == "1011" )
		{
			c = 'b';
		}
		else if( f == "1100" )
		{
			c = 'c';
		}
		else if( f == "1101" )
		{
			c = 'd';
		}
		else if( f == "1110" )
		{
			c = 'e';
		}
		else // f == "1111"
		{
			c = 'f';
		}
		
		out.push_back(c);
	}
}

void	parse(string& in,string& out)
{
	int		i;
	string	t;
	
	for(i=0;in[i]!='d';i++);
	
	t.push_back(in[i++]);
	t.push_back(in[i++]);
	
	out += directive[get_directive(t)];
	t.clear();
	
	in.push_back(' ');
	
	for(;i<in.length();i++)
	{
		char&	c = in[i];
		
		if( !IN_RANGE('0',c,'9') && !IN_RANGE('a',c,'z') )
		{
			if( t.length() != 0 )
			{
				int	b;
				
				b = get_base(t);
				
				if( b == HEX )
				{
					out += "0x";
					
					for(int j=0;j<t.length()-1;j++)
					{
						out.push_back(t[j]);
					}
					out += ", ";
				}
				else if( b == OCT )
				{
					out += "0";
					
					for(int j=0;j<t.length()-1;j++)
					{
						out.push_back(t[j]);
					}
					out += ", ";
				}
				else if( b == BIN )
				{
					string tmp;
					
					tmp = "0x";
					t.erase(t.length()-1,1);
					bin2hex(t,tmp);
					
					out += tmp+", ";
				}
				else
				{
					int to;
					
					if( t[t.length()-1] == 'd' )
					{
						to = t.length()-1;
					}
					else
					{
						to = t.length();
					}
					
					for(int i=0;i<to;i++)
					{
						out.push_back(t[i]);
					}
					
					out += ", ";
				}
				
				t.clear();
			}
		}
		else
		{
			t.push_back(c);
		}
	}
	
	out.erase(out.size()-2,2);
}

int		main(void)
{	
	for(;;)
	{
		string A,B;
		
		getline(cin,A);
		
		if( A.length() < 3 )
		{
			break;
		}
		
		parse(A,B);
		cout<<'\t'<<B<<'\n';
	}
	
	return	0;
}
