#include	<cstdio>
#include	<map>

using namespace	std;

map<int,int>	table;

#define	TRUE	1
#define	FALSE	0

int	main(void)
{
	int	N,M;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		int	n;
		
		scanf("%d",&n);
		table[n] = TRUE;
	}
	
	scanf("%d",&M);
	
	for(int i=1;i<=M;i++)
	{
		int	n;
		
		scanf("%d",&n);
		printf("%d\n",table[n]);
	}
	return	0;
}
