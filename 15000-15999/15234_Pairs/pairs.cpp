#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1000000+1)

#define	TRUE	1
#define	FALSE	0

int	N,K,number[MAX_SIZE];

int	main(void)
{
	int	cnt;
	
	scanf("%d %d",&N,&K);
	
	for(int i=1;i<=N;i++)
	{
		int	n;
		
		scanf("%d",&n);
		number[n] = TRUE;
	}
	
	cnt = 0;
	
	for(int i=1;i<=K/2;i++)
	{
		if( number[i]==TRUE && number[K-i]==TRUE )
		{
			cnt++;
		}
	}
	
	if( ((K/2)+(K/2))==K && number[K/2]==TRUE )
	{
		cnt--;
	}
	
	printf("%d\n",cnt);
	
	return	0;
}
