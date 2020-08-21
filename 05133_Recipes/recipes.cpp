#include	<iostream>

using namespace	std;

void	multiply(int C,int& w,int& n,int& d)
{
	w *= C;
	n *= C;
	
	w += n/d;
	n %= d;
}

int		get_gcd(int a,int b)
{
	int	big,small,mod;
	
	big = max(a,b);
	small = min(a,b);
	
	for(mod=big%small;mod!=0;mod=big%small)
	{
		big = small;
		small = mod;
	}
	
	return	small;
}

int		main(void)
{
	int	K;
	
	scanf("%d",&K);
	
	for(int k=1;k<=K;k++)
	{
		int	I,C;
		
		scanf("%d %d",&I,&C);
		printf("Data Set %d:\n",k);
		
		for(int i=1;i<=I;i++)
		{
			int	w,n,d;
			
			scanf("%d %d/%d",&w,&n,&d);
			multiply(C,w,n,d);
			
			if( n != 0 )
			{
				int	gcd;
				
				gcd = get_gcd(n,d);
				printf("%d %d/%d\n",w,n/gcd,d/gcd);
			}
			else
			{
				printf("%d\n",w);
			}
		}
		puts("");
	}
	
	return	0;
}
