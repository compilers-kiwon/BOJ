#include	<cstdio>

using namespace	std;

int	main(void)
{
	int	n1,n2;
	
	scanf("%d %d",&n1,&n2);
	
	for(int i=n2;i>0;i=i/10)
	{
		printf("%d\n",n1*(i%10));
	}
	printf("%d\n",n1*n2);
	
	return	0;
}
