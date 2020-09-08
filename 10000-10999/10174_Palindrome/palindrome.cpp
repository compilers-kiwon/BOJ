#include	<iostream>
#include	<string>

using namespace	std;

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))
#define	is_alphabet(c)		(IN_RANGE('a',(c),'z')||IN_RANGE('A',(c),'Z'))

bool	is_palindrome(string& str)
{
	bool	result;
	int		head,tail;
	
	for(result=true,head=0,tail=str.length()-1;result==true&&head<tail;head++,tail--)
	{
		if( str[head] != str[tail] )
		{
			if( is_alphabet(str[head]) && is_alphabet(str[tail]) )
			{
				char	big,small;
				
				big = max(str[head],str[tail]);
				small = min(str[head],str[tail]);
				
				if( (big-small) == ('a'-'A') )
				{
					continue;
				}
			}
			result = false;
		}
	}
	
	return	result;
}

int		main(void)
{
	int	n;
	
	cin>>n;getchar();
	
	while(n>0)
	{
		string	s;
		
		getline(cin,s);
		
		if( is_palindrome(s) == true )
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
		n--;
	}
	
	return	0;
}
