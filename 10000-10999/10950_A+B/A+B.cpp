#include	<iostream>

using namespace	std;

typedef	unsigned int	uint32;

int		main(void)
{
	uint32	T,A,B,i;
	
	cin>>T;
	
	for(i=1;i<=T;i++)
	{
		cin>>A>>B;
		cout<<A+B<<endl;
	}
	
	return	0;
}
