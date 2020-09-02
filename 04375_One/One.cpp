#include	<iostream>

using namespace	std;

int	solve(int n)
{
	int	a,d;
	
	for(a=0,d=1;(a=(a*10+1)%n)!=0;d++);

	return	d;
}

int		main(void)
{
	int	n;
	
	while( scanf("%d",&n) == 1 )
	{
		printf("%d\n",solve(n));
	}
	
	return	0;
}
