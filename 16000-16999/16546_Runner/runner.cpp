#include	<iostream>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N,sum;
	
	cin>>N;
	sum = N*(N+1)/2;
	
	for(int i=1;i<N;i++)
	{
		int	p;
		
		cin>>p;
		sum -= p;
	}
	
	cout<<sum<<'\n';
	
	return	0;
}
