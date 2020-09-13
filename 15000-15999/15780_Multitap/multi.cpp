#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(100+1)

int	main(void)
{
	int	N,K,sum;
	
	sum = 0;
	cin>>N>>K;
	
	for(int i=1;i<=K;i++)
	{
		int	A;
		
		cin>>A;
		sum += (A+1)/2;
	}
	
	if( sum >= N )
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
	
	return	0;
}
