#include	<iostream>

using namespace	std;

int	main(void)
{
	unsigned int	S,N,i;
	
	cin>>S;
	
	for(i=1,N=1;S-i>i;i++,N++)
	{
		S -= i;
	}
	cout<<N<<endl;
	
	return	0;
}
