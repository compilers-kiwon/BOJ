#include	<iostream>
#include	<map>

using namespace	std;

int	square(int n)
{
	int	result;
	
	result = 0;
	
	for(;n!=0;n/=10)
	{
		result += (n%10)*(n%10);
	}
	
	return	result;
}

int	is_happy(int n)
{
	map<int,bool>	s;
	
	while( n != 1 && s[n] == false )
	{
		s[n] = true;
		n = square(n);
	}
	
	return	n;
}

int	main(void)
{
	int	n;
	
	cin>>n;
	
	if( is_happy(n) == 1 )
	{
		cout<<"HAPPY\n";
	}
	else
	{
		cout<<"UNHAPPY\n";
	}
	
	return	0;
}
