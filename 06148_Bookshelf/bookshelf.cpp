#include	<iostream>

using namespace	std;

#define	MAX_SIZE	20

int	N,B,H[MAX_SIZE];

int	main(void)
{
	cin>>N>>B;
	
	for(int i=0;i<N;i++)
	{
		cin>>H[i];
	}
	
	int	min_diff,to;
	
	to = 1<<N;
	min_diff = 0x7FFFFFFF;
	
	for(int i=1;i<to;i++)
	{
		int	sum;
		
		sum = 0;
		
		for(int j=0;j<N;j++)
		{
			if( ((1<<j)&i) != 0 )
			{
				sum += H[j];
			}
		}
		
		if( sum >= B )
		{
			min_diff = min(min_diff,sum-B);
		}
	}
	
	cout<<min_diff<<'\n';
	
	return	0;
}
