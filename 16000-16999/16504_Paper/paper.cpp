#include	<iostream>

using namespace	std;

typedef	unsigned long long	uint64;

int	main(void)
{
	int		N;
	uint64	sum;
	
	cin.sync_with_stdio(false);
	
	cin>>N;
	sum = 0;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			uint64	n;
			
			cin>>n;
			sum += n;
		}
	}
	
	cout<<sum<<'\n';
	
	return	0;
}
