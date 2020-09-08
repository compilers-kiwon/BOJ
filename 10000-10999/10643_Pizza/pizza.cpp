#include	<iostream>

using namespace	std;

#define	NUM_OF_PIECES	8
#define	GET_INDEX(N)	((N)%NUM_OF_PIECES)

int	get_num_of_mushrooms(int from,int* pizza)
{
	int	sum,i;
	
	for(i=sum=0;i<4;i++)
	{
		sum += pizza[GET_INDEX(from+i)];
	}
	
	return	sum;
}

int	main(void)
{
	int	pizza[NUM_OF_PIECES],max_num_of_mushrooms;
	
	for(int i=0;i<NUM_OF_PIECES;i++)
	{
		cin>>pizza[i];
	}
	
	max_num_of_mushrooms = 0;
	
	for(int i=0;i<NUM_OF_PIECES;i++)
	{
		max_num_of_mushrooms = max(max_num_of_mushrooms,get_num_of_mushrooms(i,pizza));
	}
	
	cout<<max_num_of_mushrooms<<'\n';
	
	return	0;
}
