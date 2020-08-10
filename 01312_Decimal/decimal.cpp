#include	<iostream>

using namespace	std;

int	main(void)
{
	int	A,B,N,d;
	
	cin>>A>>B>>N;
	
	A %= B;
	A *= 10;
	
	for(int i=1;i<=N;i++)
	{
		if( A == 0 )
		{
			d = 0;
			break;
		}
		
		d = A/B;
		A = (A%B)*10;
	}
	cout<<d<<endl;
	
	return	0;
}
