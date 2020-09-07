#include	<iostream>

using namespace	std;

#define	MAX_TIME	(2000000+1)

#define	TRUE	1
#define	FALSE	0

int		N,C,fire[MAX_TIME];

void	simulate(int p)
{
	for(int i=p;i<=C;i+=p)
	{
		fire[i] = TRUE;
	}
}

int		count_fire(void)
{
	int	ret,i;
	
	for(ret=0,i=1;i<=C;i++)
	{
		ret += fire[i];
	}
	
	return	ret;
}

int		main(void)
{
	cin>>N>>C;
	
	for(int i=1;i<=N;i++)
	{
		int	time;
		
		cin>>time;
		simulate(time);
	}
	
	cout<<count_fire()<<'\n';
	
	return	0;
}
