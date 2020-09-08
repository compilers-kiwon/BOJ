#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_BASKET	(100+1)

int	main(void)
{
	int	basket[MAX_NUM_OF_BASKET];
	int	N,M;
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		basket[i] = i;
	}
	
	for(int k=1;k<=M;k++)
	{
		int	i,j;
		
		cin>>i>>j;
		swap(basket[i],basket[j]);
	}
	
	for(int i=1;i<=N;i++)
	{
		cout<<basket[i]<<' ';
	}
	cout<<endl;
	
	return	0;
}
