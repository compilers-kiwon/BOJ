#include	<iostream>

using namespace	std;

typedef	unsigned long long	uint64;

int	main(void)
{
	uint64	N,f,i;
	
	cin>>N;
	
	if( N == 0 )
	{
		cout<<"1\n";
		return	0;
	}
	
	for(i=1,f=1;i<=N;i++)
	{
		f = f*i;
	}
	cout<<f<<endl;
	
	return	0;
}
