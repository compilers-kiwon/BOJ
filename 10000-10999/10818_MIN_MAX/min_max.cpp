#include	<cstdio>
#include	<algorithm>

using namespace	std;

#define	MAX_LEN	1000000

int	number[MAX_LEN],N;

int	main(void)
{
	scanf("%d",&N);
	
	for(int i=0;i<N;i++)
	{
		scanf("%d",&number[i]);
	}
	
	sort(&number[0],&number[N]);
	
	printf("%d %d",number[0],number[N-1]);
	
	return	0;
}
