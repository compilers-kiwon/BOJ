#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N,X,A,i;
	
	cin>>N>>X;
	
	for(i=1;i<=N;i++)
	{
		cin>>A;
		if( A<X )
		{
			cout<<A<<' ';
		}
	}
	cout<<endl;
	
	return	0;	
}
