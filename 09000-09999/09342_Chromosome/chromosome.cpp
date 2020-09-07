#include	<iostream>
#include	<string>

using namespace	std;

bool	check_head(char c)
{
	bool	ret;
	
	switch(c)
	{
		case	'A':
		case	'B':
		case	'C':
		case	'D':
		case	'E':
		case	'F':
			ret = true;
			break;
		default:
			ret = false;
			break;
	}
	
	return	ret;
}

bool	check_tail(char c)
{
	return	check_head(c);
}

int		count(string& str,int& ptr,char c)
{
	int	cnt;
	
	for(cnt=0;ptr<str.length()&&str[ptr]==c;ptr++,cnt++);
	
	return	cnt;
}

bool	check_str(string& str,int& ptr)
{
	if( count(str,ptr,'A')==0 || count(str,ptr,'F')==0 || count(str,ptr,'C')==0 )
	{
		return	false;
	}
	
	return	true;
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		string	str;
		int		s_ptr,ptr;
		
		cin>>str;
		ptr = (str[0]=='A')?0:1;
		
		if( check_str(str,ptr) == false )
		{
			cout<<"Good\n";
			continue;
		}
		
		if( check_head(str[0]) == false )
		{
			cout<<"Good\n";
			continue;
		}
		
		if( (str.length()-ptr) > 1 )
		{
			cout<<"Good\n";
			continue;
		}
		
		if( str.length()!=ptr && check_tail(str[str.length()-1])==false )
		{
			cout<<"Good\n";
			continue;
		}
		
		cout<<"Infected!\n";
	}
	
	return	0;
}
