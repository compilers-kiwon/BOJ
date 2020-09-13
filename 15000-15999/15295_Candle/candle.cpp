#include	<iostream>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	P;
	
	cin>>P;
	
	for(int i=1;i<=P;i++)
	{
		int	K,N;
		
		cin>>K>>N;
		cout<<K<<' '<<(N+1)*N/2+N<<'\n';
	}
	
	return	0;
}
