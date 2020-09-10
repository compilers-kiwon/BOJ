#include	<iostream>

using namespace	std;

#define	MAX_LEN	(100000+1)

int	sum[MAX_LEN];

int	main(void)
{
	int	N,M;
	
	cin>>N>>M;
	
	sum[0] = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	n;
		
		scanf("%d",&n);
		sum[i] = sum[i-1]+n;
	}
	
	for(int k=1;k<=M;k++)
	{
		int	i,j;
		
		scanf("%d %d",&i,&j);
		printf("%d\n",sum[j]-sum[i-1]);
	}
	return	0;
}
