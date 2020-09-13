#include	<iostream>
#include	<string>

using namespace	std;

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
#define	MIN_LEN				12

const string	symbol_str = "+_)(*&^%$#@!./,;{}";

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N;
	
	cin>>N;
	
	while(N-->0)
	{
		bool	lowercase,uppercase,digit,symbol;
		int		S;
		string	password;
		
		cin>>S>>password;
		
		if( S < MIN_LEN )
		{
			cout<<"invalid\n";
			continue;
		}
		
		lowercase = uppercase = digit = symbol = false;
		
		for(int i=0;i<S;i++)
		{
			char&	c = password[i];
			
			if( IN_RANGE('a',c,'z') )
			{
				lowercase = true;
			}
			else if( IN_RANGE('A',c,'Z') )
			{
				uppercase = true;
			}
			else if( IN_RANGE('0',c,'9') )
			{
				digit = true;
			}
			else
			{
				bool	flag;
				int		j;
				
				for(j=0,flag=false;j<symbol_str.length();j++)
				{
					if( c == symbol_str[j] )
					{
						flag = true;
						break;
					}
				}
				symbol = flag;
			}
		}
		
		if( lowercase && uppercase && digit && symbol )
		{
			cout<<"valid\n";
		}
		else
		{
			cout<<"invalid\n";
		}
	}
	
	return	0;	
}
