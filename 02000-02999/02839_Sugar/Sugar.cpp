#include	<iostream>

using namespace std;

int	main(void)
{
	int	N;
	int	num_of_5_sacks,remaining_weight;
	int	result;
	
	cin>>N;
	
	num_of_5_sacks = N/5;
	remaining_weight = N%5;
	
	switch(remaining_weight)
	{
		case	0:
			result = num_of_5_sacks;
			break;
		case	1:
			if( num_of_5_sacks >= 1 )
			{
				result = num_of_5_sacks+1;
			}
			else
			{
				result = -1;
			}
			break;
		case	2:
			if( num_of_5_sacks >= 2 )
			{
				result = num_of_5_sacks+2;
			}
			else
			{
				result = -1;
			}
			break;
		case	3:
			result = num_of_5_sacks+1;
			break;
		case	4:
			if( num_of_5_sacks >= 1 )
			{
				result = num_of_5_sacks+2;
			}
			else
			{
				result = -1;
			}
			break;
		default:
			// do nothing
			break;
	}	
	cout<<result<<endl;
	
	return	0;
}
