#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_BASKET	(100+1)

int	main(void)
{
	int	N,M,b[MAX_NUM_OF_BASKET];
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		b[i] = i;
	}
	
	for(int m=1;m<=M;m++)
	{
		int	i,j;
		
		cin>>i>>j;
		
		for(int head=i,tail=j;head<tail;head++,tail--)
		{
			swap(b[head],b[tail]);
		}
	}
	
	for(int i=1;i<=N;i++)
	{
		cout<<b[i]<<' ';
	}
	cout<<endl;
	
	return	0;
}
