#include	<iostream>

using namespace	std;

typedef	unsigned long long	uint64;

int	main(void)
{
	uint64	N,num_of_spots;
	
	cin>>N;
	num_of_spots = 0;
	
	for(uint64 i=0;i<=N;i++)
	{
		for(int j=i;j<=N;j++)
		{
			num_of_spots += i+j;
		}
	}
	
	cout<<num_of_spots<<'\n';
	
	return	0;
}
