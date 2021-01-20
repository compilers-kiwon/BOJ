#include	<iostream>
#include	<string>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	0x100

#define	char2int(c)				((int)((c)-'0'))
#define	IN_RANGE(MIN,n,MAX)		((MIN)<=(n)&&(n)<=(MAX))

#define	is_lower_alphabet(c)	(IN_RANGE('a',(c),'z'))
#define	is_upper_alphabet(c)	(IN_RANGE('A',(c),'Z'))

int	num_of_digits[MAX_SIZE];

int		get_pin_length_from_pattern(const string& pattern)
{
	int	ret,i;
	
	for(i=ret=0;i<pattern.length();i++)
	{
		ret += num_of_digits[pattern[i]];
	}
	
	return	ret;
}

bool	extract_digits(const string& pin,const string& pattern,string& extracted)
{
	int	ptr,i;
	
	if( get_pin_length_from_pattern(pattern) != pin.length() )
	{
		return	false;
	}
	
	for(ptr=i=0;i<pattern.length();i++)
	{
		int		d;
		
		d = num_of_digits[pattern[i]];
		
		if( is_lower_alphabet(pattern[i]) == true )
		{
			extracted += pin.substr(ptr,d);
		}

		ptr += d;		
	}
	
	return	true;
}

int		get_sum_of_digits(const string& str)
{
	int	ret,i;
	
	for(i=ret=0;i<str.length();i++)
	{
		ret += char2int(str[i]);
	}
	
	return	ret;
}

void	init(string& pin,string& pattern)
{
	cin>>pin>>pattern;
	
	int		i;
	char	c,C;
	
	for(c='a',C='A',i=1;c<='z';c++,C++,i++)
	{
		num_of_digits[c] = num_of_digits[C] = i;
	}
}

int		main(void)
{
	string	pin,pattern,extracted;
	
	init(pin,pattern);
	
	if( extract_digits(pin,pattern,extracted) == false )
	{
		cout<<"non sequitur\n";
	}
	else
	{
		cout<<get_sum_of_digits(extracted)<<'\n';
	}
	
	return	0;
}
