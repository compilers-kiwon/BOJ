#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N,f1,i;
	
	cin>>N;
	
	for(i=1,f1=0;i<=N;i++)
	{
		int	C,K;
		
		cin>>C>>K;
		f1 += C*K;
	}
	cout<<f1<<endl;
	
	return	0;
}
