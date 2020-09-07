#include	<iostream>
#include	<string>

using namespace	std;

#define	CHAR2int(c)	((int)((c)-'A'))
#define	num2int(n)	((int)((n)-'0'))

#define	BASE_CHAR	26
#define	BASE_NUMBER	10

int	STRING2int(string& str)
{
	int	value,i;
	
	for(i=value=0;i<str.length();i++)
	{
		value = value*BASE_CHAR+CHAR2int(str[i]);
	}
	
	return	value;
}

int	number2int(string& num)
{
	int	value,i;
	
	for(i=value=0;i<num.length();i++)
	{
		value = value*BASE_NUMBER+num2int(num[i]);
	}
	
	return	value;
}

int	main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		string	car_number,f,b;
		int		front,back;
		
		cin>>car_number;
		
		f = car_number.substr(0,3);
		b = car_number.substr(4,4);
		
		front = STRING2int(f);
		back = number2int(b);
		
		if( max(front,back)-min(front,back) <= 100 )
		{
			cout<<"nice\n";
		}
		else
		{
			cout<<"not nice\n";
		}
	}
	return	0;
}
