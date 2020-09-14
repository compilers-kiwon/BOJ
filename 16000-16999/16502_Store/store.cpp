#include	<iostream>

using namespace	std;

#define	MAX_SIZE	0x100

double	probability[MAX_SIZE][MAX_SIZE],answer[MAX_SIZE];

void	dfs(int current_store,int time,double current_probability)
{
	if( time == 0 )
	{
		answer[current_store] += current_probability;
		return;
	}
	
	for(int next_store=(int)'A';next_store<=(int)'D';next_store++)
	{
		if( probability[current_store][next_store] != 0.0 )
		{
			dfs(next_store,time-1,current_probability*probability[current_store][next_store]);
		}
	}
}

void	init(int& time)
{
	int	M;
	
	cin>>time>>M;
	
	for(int i=1;i<=M;i++)
	{
		char	from,to;
		double	p;
		
		cin>>from>>to>>p;
		probability[(int)from][(int)to] = p;
	}
}

int		main(void)
{
	int	t;
	
	init(t);
	
	for(int i=(int)'A';i<=(int)'D';i++)
	{
		dfs(i,t,0.25);
	}
	
	for(int i=(int)'A';i<=(int)'D';i++)
	{
		printf("%.2f\n",answer[i]*100.0);
	}
	
	return	0;
}
