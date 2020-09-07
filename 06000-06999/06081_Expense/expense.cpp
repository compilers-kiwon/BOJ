#include	<iostream>
#include	<vector>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N,Q;
	
	cin>>N>>Q;
	
	vector<int>	sum(N+1,0);
	
	for(int i=1;i<=N;i++)
	{
		int	H;
		
		cin>>H;
		sum[i] = sum[i-1]+H;
	}
	
	for(int i=1;i<=Q;i++)
	{
		int	S,E;
		
		cin>>S>>E;
		cout<<sum[E]-sum[S-1]<<'\n';
	}
	
	return	0;
}
