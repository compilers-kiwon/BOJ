#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N,r,i;
	
	cin>>N;
	
	for(r=0,i=1;i<=N;i++)
	{
		int	s,a;
		
		cin>>s>>a;
		r += a%s;
	}
	cout<<r<<endl;
	
	return	0;
}
