#include	<cstdio>

using namespace std;

int	main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	while(T>0)
	{
		int	N,sum,i;
		
		scanf("%d",&N);
		
		for(i=1,sum=0;i<=N;i++)
		{
			int	n;
			
			scanf("%d",&n);
			sum += n;
		}
		printf("%d\n",sum);
		
		T--;
	}
	return	0;
}
