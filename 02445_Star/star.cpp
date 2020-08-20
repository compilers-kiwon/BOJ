#include	<cstdio>

void	print(int n,char c)
{
	int	i;
	
	for(i=1;i<=n;i++)
	{
		putchar(c);
	}
}

int		main(void)
{
	int	N,i;
	
	scanf("%d",&N);
	
	for(i=1;i<=N;i++)
	{
		print(i,'*');
		print(2*(N-i),' ');
		print(i,'*');
		putchar('\n');
	}
	
	for(i=N-1;i>=1;i--)
	{
		print(i,'*');
		print(2*(N-i),' ');
		print(i,'*');
		putchar('\n');
	}
	
	return	0;
}
