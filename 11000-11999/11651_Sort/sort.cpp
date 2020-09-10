#include	<iostream>
#include	<queue>
#include	<map>

using namespace	std;

typedef	priority_queue<int>	xSet;

map<int,xSet>	p;
int	N;

void	input(void)
{
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		int	x,y;
		
		scanf("%d %d",&x,&y);
		p[y].push(-x);
	}
}

void	output(void)
{
	map<int,xSet>::iterator	yi;
	
	for(yi=p.begin();yi!=p.end();yi++)
	{
		int	y = yi->first;
		
		while( p[y].size() != 0 )
		{
			printf("%d %d\n",-(p[y].top()),y);
			p[y].pop();
		}
	}
}

int		main(void)
{
	input();
	output();
	
	return	0;
}
