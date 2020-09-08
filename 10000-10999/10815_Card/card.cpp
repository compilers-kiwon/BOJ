#include	<cstdio>

using namespace std;

#define	COMPLEMENT		10000000
#define	MAX_NUM			(2*COMPLEMENT+1)
#define	GET_INDEX(n)	((n)+COMPLEMENT)

#define	TRUE	1
#define	FALSE	0

bool	card[MAX_NUM];

int		main(void)
{
	int	N,M;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		int	n;
		
		scanf("%d",&n);
		card[GET_INDEX(n)] = true;
	}
	
	scanf("%d",&M);
	
	for(int i=1;i<=M;i++)
	{
		int	m;
		
		scanf("%d",&m);
		printf("%d ",card[GET_INDEX(m)]);
	}
	
	return	0;
}

