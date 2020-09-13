#include	<iostream>

using namespace	std;

#define	MOD(n)	((n)%1000000009)

typedef	unsigned int	uint32;

int	main(void)
{
	uint32	N,answer;
	
	cin>>N;
	
	if( N == 1 )
	{
		answer = 0;
	}
	else if( N == 2 )
	{
		answer = 2;
	}
	else
	{
		answer = 6;
		
		for(uint32 i=1;i<=N-3;i++)
		{
			answer = MOD(answer*3);
		}
	}
	
	cout<<answer<<endl;
	
	return	0;
}
