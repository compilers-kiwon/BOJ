#include	<cstdio>

int	main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	while(T>0)
	{
		int	H,W,N;
		int	f,r;
		
		scanf("%d %d %d",&H,&W,&N);
		
		f = N%H;
		
		if( f == 0 )
		{
			f = H;
			r = N/H;
		}
		else
		{
			r = N/H+1;
		}
		printf("%d%02d\n",f,r);
		
		T--;
	}
	return	0;
}
