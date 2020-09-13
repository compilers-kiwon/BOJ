#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_STR_LEN	15000
#define	MAX_SIZE	26

#define	char2int(c)	((int)((c)-'A'))

const string	table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void	divide(string& src,string& a,string& b)
{
	a = src.substr(0,src.length()/2);
	b = src.substr(src.length()/2,src.length()/2);
}

void	rotate(string& str)
{
	int	r,i;
	
	for(i=r=0;i<str.length();i++)
	{
		r += char2int(str[i]);
	}
	
	for(i=0;i<str.length();i++)
	{
		str[i] = table[(char2int(str[i])+r)%MAX_SIZE];
	}
}

void	merge(string& a,string& b)
{
	for(int i=0;i<a.length();i++)
	{
		char&	c = a[i];
		char&	d = b[i];
		
		c = table[(char2int(c)+char2int(d))%MAX_SIZE];
	}
}

int		main(void)
{
	string	message,first_half,second_half;
	
	cin>>message;
	
	divide(message,first_half,second_half);
	
	rotate(first_half);
	rotate(second_half);
	
	merge(first_half,second_half);
	
	cout<<first_half<<'\n';
	
	return	0;
}
