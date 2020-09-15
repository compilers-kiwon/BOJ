#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N,M,cnt;
	
	cin>>N>>M;
	cnt = 1;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<M;col++)
		{
			cout<<cnt++<<' ';
		}
		cout<<cnt++<<'\n';
	}
	
	return	0;
}
