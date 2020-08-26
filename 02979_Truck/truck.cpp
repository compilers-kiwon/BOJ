#include	<iostream>

using namespace	std;

#define	MAX_TIME			100
#define	NUM_OF_KINDS_FEE	3
#define	NUM_OF_TRUCKS		3

int	main(void)
{
	int	time_table[MAX_TIME+1],fee[NUM_OF_KINDS_FEE+1];
	
	for(int i=1;i<=MAX_TIME;i++)
	{
		time_table[i] = 0;
	}
	
	for(int i=1;i<=NUM_OF_KINDS_FEE;i++)
	{
		cin>>fee[i];
	}
	fee[0] = 0;
	
	for(int i=1;i<=NUM_OF_TRUCKS;i++)
	{
		int	arrive,leave;
		
		cin>>arrive>>leave;
		
		for(int t=arrive;t<leave;t++)
		{
			time_table[t]++;
		}
	}
	
	int	sum,i;
	
	for(sum=0,i=1;i<=MAX_TIME;i++)
	{
		sum += fee[time_table[i]]*time_table[i];
	}
	cout<<sum<<endl;
	
	return	0;
}
