#include	<iostream>

using namespace	std;

int	main(void)
{
	for(int u=1;;u++)
	{
		int	L,N;
		
		scanf("%d",&L);
		
		if( L == 0 )
		{
			break;
		}
		
		printf("User %d\n",u);
		scanf("%d",&N);
		
		for(int i=1;i<=N;i++)
		{
			int steps,walk;
			
			cin>>steps;
			walk = steps*L;
			
			printf("%d.%05d\n",walk/100000,walk%100000);
		}
	}
	
	return	0;
}
