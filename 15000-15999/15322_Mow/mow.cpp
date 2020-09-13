#include	<iostream>

using namespace	std;

int	main(void)
{
	int	K;
	
	scanf("%d",&K);
	
	for(int i=1;i<=K;i++)
	{
		int	N,M;
		
		scanf("%d %d",&N,&M);
		printf("%d\n",2*(min(N,M)-1));
	}
	
	return	0;
}
