#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int	k;
	
	cin>>k;

	string	one(k,'1');
	string	zero(k-1,'0');
	
	cout<<one<<zero<<endl;
	
	return	0;	
}
