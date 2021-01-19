#include	<iostream>
#include	<string>

using namespace	std;

#define	char2int(c)	((int)((c)-'0'))

int	get_sum_of_digits(const string& str)
{
	int	ret;
	
	ret = 0;
	
	for(int i=0;i<str.length();i++)
	{
		ret += char2int(str[i]);
	}
	
	return	ret;
}

int	main(void)
{
	string	N,upper,lower;
	
	cin>>N;
	
	upper = N.substr(0,N.length()/2);
	lower = N.substr(N.length()/2,N.length()/2);
	
	if( get_sum_of_digits(upper) == get_sum_of_digits(lower) )
	{
		cout<<"LUCKY\n";
	}
	else
	{
		cout<<"READY\n";
	}
	
	return	0;
}
