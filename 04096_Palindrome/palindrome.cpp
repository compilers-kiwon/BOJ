#include	<iostream>
#include	<string>

using namespace	std;

#define	char2int(c)	((int)((c)-'0'))
#define	int2char(i)	((char)((i)+(int)'0'))

typedef	long long int	int64;

int64	get_value(string& str)
{
	int64	value,i;
	
	for(i=value=0;i<str.length();i++)
	{
		value = value*10+char2int(str[i]);
	}
	
	return	value;
}

void	inc_str(string& str)
{
	int	c,i;
	
	for(c=1,i=str.length()-1;c!=0&&i>=0;i--)
	{
		char&	current = str[i];
		int		n;
		
		n = char2int(current)+c;
		current = int2char(n%10);
		c = n/10;
	}
}

void	build_palindrome(string& str,int tail)
{
	for(int i=tail;i>=0;i--)
	{
		str.push_back(str[i]);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
		
	for(;;)
	{
		string	number,half,palindrome;
		
		cin>>number;
		
		if( number == "0" )
		{
			break;
		}
		
		if( number.length()%2 == 0 )
		{
			half = palindrome = number.substr(0,number.length()/2);
			build_palindrome(palindrome,number.length()/2-1);
		}
		else
		{
			half = palindrome = number.substr(0,number.length()/2+1);
			build_palindrome(palindrome,number.length()/2-1);
		}
		
		int64	number_value,palindrome_value;
		
		number_value = get_value(number);
		palindrome_value = get_value(palindrome);
		
		if( palindrome_value < number_value )
		{
			inc_str(half);
			palindrome = half;
			build_palindrome(palindrome,number.length()/2-1);
			
			palindrome_value = get_value(palindrome);
		}
		
		cout<<palindrome_value-number_value<<'\n';
	}
	
	return	0;
}
