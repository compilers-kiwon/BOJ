#include	<cstdio>

int	main(void)
{
	int	N,i,j;
	
	scanf("%d",&N);
	
	for(i=2*N-1,j=0;i>=1;i=i-2,j++)
	{
		int k;
		
		for(k=1;k<=j;k++)
		{
			putchar(' ');
		}
		
		for(k=1;k<=i;k++)
		{
			putchar('*');
		}
		
		putchar('\n');
	}
	
	for(i=3,j=N-2;i<=2*N-1;i=i+2,j--)
	{
		int k;
		
		for(k=1;k<=j;k++)
		{
			putchar(' ');
		}
		
		for(k=1;k<=i;k++)
		{
			putchar('*');
		}
		
		putchar('\n');
	}
	
	return	0;
}
