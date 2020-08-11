#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_PEOPLE	(20+1)

#define	INIT_FITNESS	100
#define	INIT_PLEASURE	0

int	N,f[MAX_NUM_OF_PEOPLE],p[MAX_NUM_OF_PEOPLE],max_pleasure;

void	say_hello(int person,int current_fitness,int current_pleasure)
{
	if( current_fitness <= 0 )
	{
		return;
	}
	
	if( person > N )
	{
		max_pleasure = max(max_pleasure,current_pleasure);
		return;
	}
	
	say_hello(person+1,current_fitness-f[person],current_pleasure+p[person]);
	say_hello(person+1,current_fitness,current_pleasure);
}

int		main(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>f[i];
	}
	
	for(int i=1;i<=N;i++)
	{
		cin>>p[i];
	}
	
	say_hello(1,INIT_FITNESS,INIT_PLEASURE);
	
	cout<<max_pleasure<<endl;
	
	return	0;
}
