#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N,prev,i;
	
	cin>>N;
	
	for(i=1,prev=0;i<=N;i++)
	{
		int	A,B;
		
		cin>>B;
		A = B*i-prev;
		cout<<A<<' ';
		prev += A;
	}
	cout<<endl;
	
	return	0;
}
