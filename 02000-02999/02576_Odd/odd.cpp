#include	<iostream>

using namespace	std;

#define	NUM_OF_INPUTS	7

int	main(void)
{
	int	min_odd,sum,i;
	
	for(i=1,min_odd=0x7FFFFFFF,sum=0;i<=NUM_OF_INPUTS;i++)
	{
		int	n;
		
		cin>>n;
		if( n%2 == 1 )
		{
			min_odd = min(min_odd,n);
			sum += n;
		}
	}
	
	if( min_odd == 0x7FFFFFFF )
	{
		cout<<"-1\n";
	}
	else
	{
		cout<<sum<<endl<<min_odd<<endl;
	}
	return	0;
}
