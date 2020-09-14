#include	<iostream>
#include	<string>

using namespace	std;

#define	NUMBERS	10
#define	CHARS	26

typedef	unsigned long long	uint64;

int	main(void)
{
	string	format;
	uint64	cnt;
	
	cin>>format;
	format.insert(format.begin(),' ');
	
	cnt = 1;
	
	for(int i=1;i<format.length();i++)
	{
		uint64	n;
		
		if( format[i] == 'c' )
		{
			n = CHARS;
		}
		else
		{
			n = NUMBERS;
		}
		
		if( format[i-1] == format[i] )
		{
			n--;
		}
		
		cnt = (cnt*n)%1000000009;
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
