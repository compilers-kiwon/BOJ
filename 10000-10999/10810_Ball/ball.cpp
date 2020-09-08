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
		basket[i] = 0;
	}
	
	for(int m=1;m<=M;m++)
	{
		int i,j,k;
		
		cin>>i>>j>>k;
		
		for(int n=i;n<=j;n++)
		{
			basket[n] = k;
		}
	}
	
	for(int i=1;i<=N;i++)
	{
		cout<<basket[i]<<' ';
	}
	cout<<endl;
	
	return	0;
}
