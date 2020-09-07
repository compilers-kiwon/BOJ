#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N,W,H;
	int	pow_max_len;
	
	cin>>N>>W>>H;
	pow_max_len = W*W+H*H;
	
	for(int i=1;i<=N;i++)
	{
		int	match;
		
		cin>>match;
		
		if( match*match <= pow_max_len )
		{
			cout<<"DA\n";
		}
		else
		{
			cout<<"NE\n";
		}
	}
	
	return	0;
}
