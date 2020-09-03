#include	<iostream>
#include	<string>

using namespace	std;

#define	char2int(c)	((int)(c-'0'))

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		string	n;
	
		cin>>n;
	
		if( char2int(n[n.length()-1])%2 == 1 )
		{
			cout<<"odd\n";
		}
		else
		{
			cout<<"even\n";
		}
		T--;
	}
	return	0;
}
