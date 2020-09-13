#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		int	a,b,c;
		
		scanf("%d %d %d",&a,&b,&c);
		printf("%d %d %d ",a,b,c);
		
		if( a+b+c==180 )
		{
			puts("Seems OK");
		}
		else
		{
			puts("Check");
		}
	}
	
	return	0;
}
