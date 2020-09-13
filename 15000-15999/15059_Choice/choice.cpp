#include	<iostream>

using namespace	std;

int	main(void)
{
	int	Ca,Ba,Pa,Cr,Br,Pr;
	
	cin>>Ca>>Ba>>Pa>>Cr>>Br>>Pr;
	cout<<max(0,Cr-Ca)+max(0,Br-Ba)+max(0,Pr-Pa)<<'\n';
	
	return	0;
}
