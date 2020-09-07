#include	<iostream>

using namespace	std;

int	main(void)
{
	int	A,B,N,cnt;
	
	cin>>N;
	
	for(cnt=0,B=1;B<=500;B++)
	{
		for(A=B;A<=500;A++)
		{
			if( B*B+N == A*A )
			{
				++cnt;
			}
		}
	}
	cout<<cnt<<endl;
	
	return	0;
}
