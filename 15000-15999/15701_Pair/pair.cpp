#include	<iostream>
#include	<cmath>

using namespace	std;

int	main(void)
{
	int	N,cnt,r;
	
	cin>>N;
	
	cnt = 0;
	r = sqrt(N);
	
	for(int i=1;i<=r;i++)
	{
		if( N%i == 0 )
		{
			cnt += 2;
		}
	}
	
	if( r*r == N )
	{
		cnt--;
	}
	
	cout<<cnt<<endl;
	
	return	0;
}
