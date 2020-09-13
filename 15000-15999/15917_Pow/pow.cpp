#include	<iostream>

using namespace	std;

#define	TRUE	1
#define	FALSE	0

int	main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	while(T>0)
	{
		int	Q,result,i;
		
		scanf("%d",&Q);
		
		for(i=0,result=FALSE;i<32;i++)
		{
			if( Q == 1<<i )
			{
				result = TRUE;
				break;
			}
		}
		
		printf("%d\n",result);
		
		T--;
	}
}
