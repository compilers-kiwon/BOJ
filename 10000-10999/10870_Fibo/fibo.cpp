#include	<iostream>

using namespace	std;

#define	NUMS	20

int	fibo[NUMS+1];

int	main(void)
{
	fibo[0] = 0;
	fibo[1] = 1;
	
	int n;
	
	cin>>n;
	
	for(int i=2;i<=n;i++)
	{
		fibo[i] = fibo[i-1]+fibo[i-2];
	}
	cout<<fibo[n]<<endl;
	
	return	0;
}
