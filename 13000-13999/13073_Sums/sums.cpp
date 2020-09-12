#include	<iostream>

using namespace	std;

#define	MAX_SIZE	10000

int	int_sum[MAX_SIZE+1],odd_sum[MAX_SIZE+1],even_sum[MAX_SIZE+1];

int	main(void)
{
	int	i,odd,even,t;
	
	for(i=1,odd=1,even=2;i<=MAX_SIZE;i++,odd+=2,even+=2)
	{
		int_sum[i] = int_sum[i-1]+i;
		odd_sum[i] = odd_sum[i-1]+odd;
		even_sum[i] = even_sum[i-1]+even;
	}
	
	cin.sync_with_stdio(false);
	
	cin>>t;
	
	for(int i=1;i<=t;i++)
	{
		int	N;
		
		cin>>N;
		cout<<int_sum[N]<<' '<<odd_sum[N]<<' '<<even_sum[N]<<'\n';
	}
	
	return	0;
}
