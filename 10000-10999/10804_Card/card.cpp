#include	<iostream>

using namespace	std;

#define	NUM_OF_CARDS	20
#define	NUM_OF_INPUTS	10

int	main(void)
{
	int	card[NUM_OF_CARDS+1];
	
	for(int i=1;i<=NUM_OF_CARDS;i++)
	{
		card[i] = i;
	}
	
	for(int i=1;i<=NUM_OF_INPUTS;i++)
	{
		int	a,b;
		
		cin>>a>>b;
		
		for(;a<b;a++,b--)
		{
			swap(card[a],card[b]);
		}
	}
	
	for(int i=1;i<=NUM_OF_CARDS;i++)
	{
		cout<<card[i]<<' ';
	}
	cout<<endl;
	
	return	0;
}
