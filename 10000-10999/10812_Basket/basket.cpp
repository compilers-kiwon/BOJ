#include	<iostream>

using namespace	std;

#define	MAX_LEN	(100+1)

int	main(void)
{
	int	N,M,basket_index;
	int	basket[2][MAX_LEN];
	
	cin>>N>>M;
	basket_index = 0;
	
	for(int i=1;i<=N;i++)
	{
		basket[basket_index][i] = i;
	}
	
	for(int m=1;m<=M;m++)
	{
		int	begin,end,mid;
		int	i,j;
		int	next_basket_index;
		
		cin>>begin>>end>>mid;
		next_basket_index = (basket_index+1)%2;
		
		for(i=1;i<begin;i++)
		{
			basket[next_basket_index][i] = basket[basket_index][i];
		}
		
		for(j=mid;j<=end;j++,i++)
		{
			basket[next_basket_index][i] = basket[basket_index][j];
		}
		
		for(j=begin;j<mid;j++,i++)
		{
			basket[next_basket_index][i] = basket[basket_index][j];
		}
		
		for(;i<=N;i++)
		{
			basket[next_basket_index][i] = basket[basket_index][i];
		}
		basket_index = next_basket_index;
	}
	
	for(int i=1;i<=N;i++)
	{
		cout<<basket[basket_index][i]<<' ';
	}
	cout<<endl;
	
	return	0;
}
