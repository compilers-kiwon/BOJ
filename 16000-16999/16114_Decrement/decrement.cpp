#include	<iostream>

using namespace	std;

int	main(void)
{
	int	X,N,decrement;
	
	cin>>X>>N;
	
	if( N != 1 && N%2 != 0 )
	{
		cout<<"ERROR\n";
	}
	else
	{
		if( N == 1 )
		{
			X = -X;
		}
		
		decrement = N/2;
		X -= decrement;
	
		int	cnt;
		
		if( X <= 0 )
		{
			cout<<0<<endl;
		}
		else
		{
			if( decrement == 0 )
			{
				cout<<"INFINITE\n";
			}
			else
			{
				for(cnt=0;X>0;cnt++,X-=decrement);
				
				cout<<cnt<<endl;
			}
		}
	}
	
	return	0;
}
