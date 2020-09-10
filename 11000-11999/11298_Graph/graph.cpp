#include	<iostream>

using namespace	std;

#define	GRAPH_SIZE		200
#define	WIDTH			10			
#define	get_height(a,b)	((a)*WIDTH+b)

char	graph[GRAPH_SIZE][GRAPH_SIZE];

void	graph_init(int h)
{
	for(int x=0;x<=WIDTH;x++)
	{
		graph[0][x] = '*';
	}
	graph[0][WIDTH+1] = '\0';
	
	for(int y=1;y<=h;y++)
	{
		graph[y][0] = '*';
		
		for(int x=1;x<=WIDTH;x++)
		{
			graph[y][x] = ' ';
		}
		graph[y][WIDTH+1] = '\0';
	}
}

void	draw_graph(int a,int b,int h)
{
	printf("y = %dx + %d\n",a,b);
	
	for(int x=1;x<=WIDTH;x++)
	{
		int y;
		
		y = a*x+b;
		graph[y][x] = '*';
	}
	
	for(int y=h;y>=0;y--)
	{
		puts(&graph[y][0]);
	}
}

int		main(void)
{
	int	N;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		int	A,B,max_h;
		
		scanf("%d %d",&A,&B);
		
		max_h = A*WIDTH+B;
		
		graph_init(max_h);
		draw_graph(A,B,max_h);
	}
	
	return	0;
}
