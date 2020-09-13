#include	<iostream>

using namespace	std;

int	main(void)
{
	int	n,m,i;
	
	cin>>n>>m;
	
	for(i=1;m>0;i++,m--)
	{
		cout<<0<<' '<<i<<'\n';
	}
	
	for(;i<n;i++)
	{
		cout<<i-1<<' '<<i<<'\n';
	}
	
	return	0;
}
