#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100+1)

void	reverse_bottom_up(char mirror[][MAX_SIZE+1],int size)
{
	int	head,tail;
	
	for(int i=1;i<=size;i++)
	{
		for(head=1,tail=size;head<tail;head++,tail--)
		{
			swap(mirror[head][i],mirror[tail][i]);
		}
	}
}

void	reverse_left_right(char mirror[][MAX_SIZE+1],int size)
{
	int	head,tail;
	
	for(int i=1;i<=size;i++)
	{
		for(head=1,tail=size;head<tail;head++,tail--)
		{
			swap(mirror[i][head],mirror[i][tail]);
		}
	}
}

int		main(void)
{
	char	mirror[MAX_SIZE][MAX_SIZE+1];
	int		N,K;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%s",&mirror[i][1]);
	}
	
	scanf("%d",&K);
	
	switch(K)
	{
		case	2:
			reverse_left_right(mirror,N);
			break;
		case	3:
			reverse_bottom_up(mirror,N);
			break;
		case	1:
		default:
			break;
	}
	
	for(int i=1;i<=N;i++)
	{
		printf("%s\n",&mirror[i][1]);
	}
	
	return	0;
}
