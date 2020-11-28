#include	<iostream>

using namespace	std;

typedef	long long int	int64;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int64	N;
	int		score;
	
	cin>>N;
	
	for(score=0;N!=1;score++)
	{
		if( N%2 == 0 )
		{
			N >>= 1;
		}
		else
		{
			N = N*3+1;
		}
	}
	
	cout<<score<<'\n';
	
	return	0;
}
