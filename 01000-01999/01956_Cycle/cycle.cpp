#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_V	(400+1)
#define	MAX_DISTANCE	4000000

int	d[MAX_NUM_OF_V][MAX_NUM_OF_V];

int		main(void)
{
	int	V,E;
	
	scanf("%d %d",&V,&E);
	
	for(int i=1;i<=V;i++)
	{
		for(int j=1;j<=V;j++)
		{
			d[i][j] = MAX_DISTANCE;
		}
	}
	
	for(int i=1;i<=E;i++)
	{
		int	a,b,c;
		
		scanf("%d %d %d",&a,&b,&c);
		d[a][b] = c;
	}
	
	for(int k=1;k<=V;k++)
	{
		for(int i=1;i<=V;i++)
		{
			for(int j=1;j<=V;j++)
			{
				if( d[i][j] > d[i][k]+d[k][j] )
				{
					d[i][j] = d[i][k]+d[k][j];
				}
			}
		}
	}
	
	int	min_cycle = d[1][1];
	
	for(int i=2;i<=V;i++)
	{
		min_cycle = min(min_cycle,d[i][i]);
	}
	
	if( min_cycle == MAX_DISTANCE )
	{
		min_cycle = -1;
	}
	
	cout<<min_cycle<<endl;
	
	return	0;
}
