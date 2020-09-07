#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(500+1)

#define	OFF			0
#define	ON			1
#define	MAX_STATE	2

#define	TOGGLE(l)	(((l)+1)%MAX_STATE)

void	toggle(int from,int to,int* lights)
{
	for(int i=from;i<=to;i++)
	{
		lights[i] = TOGGLE(lights[i]);
	}
}

int		count_on(int from,int to,int* lights)
{
	int	ret;
	
	ret = 0;
	
	for(int i=from;i<=to;i++)
	{
		ret += lights[i];
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N,M,lights[MAX_SIZE];
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		lights[i] = OFF;
	}
	
	for(int i=1;i<=M;i++)
	{
		int	op,S,E;
		
		cin>>op>>S>>E;
		
		if( op == 0 )
		{
			toggle(S,E,lights);
		}
		else
		{
			cout<<count_on(S,E,lights)<<'\n';
		}
	}
	
	return	0;
}
