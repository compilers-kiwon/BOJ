#include	<iostream>
#include	<cmath>

using namespace	std;

int	main(void)
{
	int	N,sum;
	
	cin>>N;
	sum = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	coin;
		
		cin>>coin;
		sum += abs(coin);
	}
	
	for(int i=1;i<=N;i++)
	{
		int	coin;
		
		cin>>coin;
		sum += abs(coin);
	}
	
	cout<<sum<<endl;
	
	return	0;
}
