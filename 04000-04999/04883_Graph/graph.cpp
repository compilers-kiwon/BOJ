#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100000+1)

typedef	long long int	int64;

int64	graph[MAX_SIZE][3];

void	build_graph(int size)
{
	for(int row=2;row<=size;row++)
	{
		graph[row][0] += min(graph[row-1][0],graph[row-1][1]);
		graph[row][1] += min(graph[row][0],min(graph[row-1][0],min(graph[row-1][1],graph[row-1][2])));
		graph[row][2] += min(graph[row][1],min(graph[row-1][1],graph[row-1][2]));
	}
}

int		main(void)
{
	for(int cnt=1;;cnt++)
	{
		int	N;
		
		scanf("%d",&N);
		
		if( N == 0 )
		{
			break;
		}
		
		for(int i=1;i<=N;i++)
		{
			scanf("%lld %lld %lld",&graph[i][0],&graph[i][1],&graph[i][2]);
		}
		
		graph[1][0] = 1000000;
		
		if( graph[1][2] < 0 )
		{
			graph[1][2] += graph[1][1];
		}
		else
		{
			graph[1][2] = 1000000;
		}
		
		build_graph(N);
		
		printf("%d. %lld\n",cnt,graph[N][1]);
	}
	
	return	0;
}
