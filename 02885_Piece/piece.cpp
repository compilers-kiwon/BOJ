#include	<iostream>

using namespace	std;

int	main(void)
{
	int	K,cnt,a,b;
	
	cin>>K;
	
	for(a=0;(1<<a)<K;a++);
	a = 1<<a;
	
	cout<<a;
	
	if( a == K )
	{
		cout<<" 0\n";
		return	0;
	}
	
	for(b=cnt=0;b!=K;a=a>>1,cnt++)
	{
		if( b+(a>>1) <= K )
		{
			b += a>>1;
		}
	}
	
	cout<<' '<<cnt<<'\n';
	
	return	0;
}
