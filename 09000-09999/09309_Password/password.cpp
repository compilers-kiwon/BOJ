#include	<iostream>
#include	<string>

using namespace	std;

#define	LEN_OF_CONSECUTIVE	3
#define	NUM_FORBIDDEN_WORD	4

#define	NUMBER			(1<<0)
#define	LOWERCASE		(1<<1)
#define	UPPERCASE		(1<<2)
#define	NONALPHANUMERIC	(1<<3)
#define	ALPHANUMERIC	(NUMBER|LOWERCASE|UPPERCASE)

const string	nonalphanumeric = "!@#$%^&*.,;/?";
const string	alphanumeric = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const string	forbidden_word[NUM_FORBIDDEN_WORD] = {"password","virginia","cavalier","code"};

#define	MIN_LEN	9
#define	MAX_LEN	20
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	OFFSET	('a'-'A')

void	make_lower(string& str)
{
	for(int i=0;i<str.length();i++)
	{
		if( IN_RANGE('A',str[i],'Z') == true )
		{
			str[i] += OFFSET;
		}
	}
}

void	check_attr(string& str,int* attr)
{
	for(int i=0;i<str.length();i++)
	{
		char&	c = str[i];
		int		a;
		
		if( IN_RANGE('0',c,'9') )
		{
			a = NUMBER;
		}
		else if( IN_RANGE('a',c,'z') )
		{
			a = LOWERCASE;
		}
		else if( IN_RANGE('A',c,'Z') )
		{
			a = UPPERCASE;
		}
		else
		{
			a = NONALPHANUMERIC;
		}
		
		attr[i] = a;
	}
}

bool	is_consecutive(string& str)
{
	char	prev;
	int		i,cnt;
	bool	ret;
	
	for(ret=false,i=cnt=0,prev='\0';i<str.length()&&ret!=true;i++)
	{
		if( str[i] == prev )
		{
			cnt++;
		}
		else
		{
			prev = str[i];
			cnt = 1;
		}
		
		if( cnt == LEN_OF_CONSECUTIVE )
		{
			ret = true;
		}
	}
	
	return	ret;
}

bool	is_palindrome(string& str)
{
	int		h,t;
	bool	ret;
	
	for(h=0,t=str.length()-1;h<=t;h++,t--)
	{
		if(str[h] != str[t] )
		{
			break;
		}
	}
	
	if( h > t )
	{
		ret = true;
	}
	else
	{
		ret = false;
	}
	
	return	ret;
}

bool	is_forbidden_word_found(string& str)
{
	bool	ret;
	
	ret = false;
	
	for(int i=0;i<NUM_FORBIDDEN_WORD&&ret!=true;i++)
	{
		int		ptr;
		
		ptr = 0;
		
		for(int j=0;j<str.length()&&ptr<forbidden_word[i].length();j++)
		{
			if( str[j] == forbidden_word[i][ptr] )
			{
				ptr++;
			}
		}
		
		if( ptr == forbidden_word[i].length() )
		{
			ret = true;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		string		password;
		
		cin>>password;
		
		if( !IN_RANGE(MIN_LEN,password.length(),MAX_LEN) )
		{
			cout<<"Invalid Password\n";
			continue;
		}
		
		int		attr[password.length()];
		int		num_of_numbers,num_of_lowers,num_of_uppers,num_of_nonalphanumeric;
		string	alphanumeric_str,reverse_alphanumeric_str;
		
		check_attr(password,attr);
		
		num_of_numbers = num_of_lowers = 
			num_of_uppers = num_of_nonalphanumeric = 0;
			
		for(int i=0;i<password.length();i++)
		{
			switch(attr[i])
			{
				case	NUMBER:
					num_of_numbers++;
					break;
				case	LOWERCASE:
					num_of_lowers++;
					break;
				case	UPPERCASE:
					num_of_uppers++;
					break;
				case	NONALPHANUMERIC:
					num_of_nonalphanumeric++;
					break;
				default:
					// do nothing
					break;
			}
			
			if( (attr[i]&ALPHANUMERIC) != 0 )
			{
				alphanumeric_str.push_back(password[i]);
			}
		}
		
		if( !(num_of_lowers>=2) || !(num_of_uppers>=2) || 
			!(num_of_numbers>=1) || !(num_of_nonalphanumeric>=2) )
		{
			cout<<"Invalid Password\n";
			continue;
		}
		
		if( is_consecutive(password) == true )
		{
			cout<<"Invalid Password\n";
			continue;	
		}
		
		make_lower(alphanumeric_str);
		
		for(int i=alphanumeric_str.length()-1;i>=0;i--)
		{
			reverse_alphanumeric_str.push_back(alphanumeric_str[i]);
		}
		
		if( is_palindrome(alphanumeric_str) == true )
		{
			cout<<"Invalid Password\n";
			continue;
		}
		
		if( is_forbidden_word_found(alphanumeric_str)==true || 
			is_forbidden_word_found(reverse_alphanumeric_str)==true )
		{
			cout<<"Invalid Password\n";
			continue;	
		}
		
		cout<<"Valid Password\n";		
	}
	
	return	0;	
}
