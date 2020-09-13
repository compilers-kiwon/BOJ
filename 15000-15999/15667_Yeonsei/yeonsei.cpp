#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N,K;
	
	cin>>N;
	
	for(K=1;;K++)
	{
		if( 1+K+K*K == N )
		{
			cout<<K<<'\n';
			break;
		}
	}
	
	return	0;
}
