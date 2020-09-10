#include	<iostream>
#include	<cmath>

using namespace	std;

int	main(void)
{
	int	N,X,i;
	
	cin>>N;
	
	for(i=1,X=0;i<=N;i++)
	{
		int	P;
		
		cin>>P;
		X += pow(P/10,P%10);
	}
	
	cout<<X<<endl;
	
	return	0;
}
