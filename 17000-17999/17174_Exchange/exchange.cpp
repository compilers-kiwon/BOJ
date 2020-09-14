#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N,M,ans;
	
	cin>>N>>M;
	
	for(ans=N;N>=M;ans+=N)
	{
		N /= M;
	}
	
	cout<<ans<<'\n';
	
	return	0;
}
