#include	<stdio.h>

#define	MAX_N	50

#define	TRUE	1
#define	FALSE	0

int	main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	while(T>0)
	{
		int	K,i,j,k,result;
		int	t1,t2,t3,sum;
		
		scanf("%d",&K);
		
		result = FALSE;
		
		for(i=1;i<=MAX_N && result==FALSE;i++)
		{
			t1 = i*(i+1)/2;
			
			if( t1 >= K )
			{
				break;
			}
			
			for(j=1;j<=MAX_N && result==FALSE;j++)
			{
				t2 = j*(j+1)/2;
				
				if( t1+t2 >= K )
				{
					break;
				}
				
				for(k=1;k<=MAX_N && result==FALSE;k++)
				{
					t3 = k*(k+1)/2;
					
					if( t1+t2+t3 == K )
					{
						result = TRUE;
						break;
					}
					
					if( t1+t2+t3 > K )
					{
						break;
					}
				}
			}
		}
		printf("%d\n",result);
		T--;
	}
	return	0;
}
