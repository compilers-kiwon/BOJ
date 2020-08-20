#include	<cstdio>

#define	MOD(n)	((n)%10)

int		main(void)
{
	int	n1,n2,n3,n4,n5,check_sum;
	
	scanf("%d %d %d %d %d",&n1,&n2,&n3,&n4,&n5);
	check_sum = MOD(n1*n1+n2*n2+n3*n3+n4*n4+n5*n5);
	printf("%d\n",check_sum);
	
	return	0;
}
