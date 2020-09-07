#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_LAWMAKERS	(1000+1)
#define	is_relevant(T,t)		(((T)-(t))>=0&&((T)-(t))<1000)
#define	counts(D)				(1.0/(1.0+((D)/10000.0)))

int		n,m,T;
double	donation[MAX_NUM_OF_LAWMAKERS];

void	input(void)
{
	scanf("%d %d %d",&n,&m,&T);
	fill(&donation[1],&donation[n+1],0.0);
	
	for(int k=1;k<=m;k++)
	{
		int		i,t;
		double	d;
		
		scanf("%d %d %lf",&i,&t,&d);
		
		if( is_relevant(T,t) == true )
		{
			donation[i] += d;
		}
	}
}

void	vote(void)
{
	double	v1,v2;
	
	v1 = v2 = 0.0;
	getchar();
	
	for(int i=1;i<=n;i++)
	{
		char	c;
		
		scanf("%c",&c);
		getchar();
		
		if( c == 'Y' )
		{
			v1 += 1.0;
		}
		else
		{
			v2 += counts(donation[i]);
		}
	}
	
	printf("%.02f %.02f\n\n",v1,v2);
}

int		main(void)
{
	int	K;
	
	scanf("%d",&K);
	
	for(int k=1;k<=K;k++)
	{
		input();
		printf("Data Set %d:\n",k);
		vote();
	}
	
	return	0;
}
