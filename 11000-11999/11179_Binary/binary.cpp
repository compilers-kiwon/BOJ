#include	<iostream>

using namespace	std;

typedef	unsigned int	uint32;

int	main(void)
{
	uint32	N,R;
	
	cin>>N;
	
	for(R=0;N>0;N>>=1)
	{
		R = (R<<1)+(N&0x1);
	}
	cout<<R<<endl;
	
	return	0;
}
