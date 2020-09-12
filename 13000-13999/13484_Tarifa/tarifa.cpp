#include	<iostream>

using namespace	std;

int	main(void)
{
	int	X,N,rest;
	
	cin>>X>>N;
	rest = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	P;
		
		cin>>P;
		rest = max(0,rest+X-P);
	}
	
	cout<<rest+X<<endl;
	
	return	0;
}
