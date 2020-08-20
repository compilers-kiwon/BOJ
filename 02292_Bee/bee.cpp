#include	<iostream>

using namespace std;

typedef	unsigned long long	uint64;

int	main(void)
{	
	uint64	N,i,prev;
	
	cin>>N;
	
	if( N == 1 )
	{
		i = 2;
	}
	else
	{
		for(prev=1,i=1;N>prev;i++)
		{
			prev = prev+(i-1)*6;
		}
	}
	cout<<i-1<<endl;
	
	return	0;
}
