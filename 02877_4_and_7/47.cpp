#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_NUM	1000000000

int	main(void)
{
	string		number;
	int			K;
	
	cin>>K;
	K--;
	
	for(int i=2;;i*=2)
	{
		if( K%i < i/2 )
		{
			number.insert(0,"4");
		}
		else
		{
			number.insert(0,"7");
		}
		
		K -= i;
		
		if( K < 0 )
		{
			break;
		}
	}
	
	cout<<number<<endl;
	return	0;
}
