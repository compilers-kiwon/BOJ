#include	<iostream>
	
using namespace	std;

int	main(void)
{
	int	N,n1,n2;
	
	cin>>N;
	n1 = n2 = 1;
	
	n1 += (N/2);
	n2 += (N/2)+(N%2);
	
	cout<<n1*n2<<'\n';
	
	return	0;
}
