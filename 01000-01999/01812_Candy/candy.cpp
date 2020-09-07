#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_NUMS	(999+1)

int	main(void)
{
	int	N,sum[MAX_NUM_OF_NUMS],candy[MAX_NUM_OF_NUMS];
	int	sign,constant;
	
	cin>>N;
	sign = 1;
	constant = 0;
	
	for(int i=1;i<=N;i++)
	{
		cin>>sum[i];
		constant += sign*sum[i];
		sign *= -1;
	}
	
	candy[1] = constant/2;
	cout<<candy[1]<<endl;
	
	for(int i=2;i<=N;i++)
	{
		candy[i] = sum[i-1]-candy[i-1];
		cout<<candy[i]<<endl;
	}
	
	return	0;
}
