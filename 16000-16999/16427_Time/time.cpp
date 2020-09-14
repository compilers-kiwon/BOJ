#include	<iostream>

using namespace	std;

int	main(void)
{
	int	n,s,slowest;
	
	cin>>n>>s;
	slowest = 0;
	
	for(int i=1;i<=n;i++)
	{
		int	t;
		
		cin>>t;
		slowest = max(slowest,t);
	}
	
	slowest *= s;
	cout<<slowest/1000+((slowest%1000)?1:0)<<'\n';
	
	return	0;
}
