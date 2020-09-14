#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(10+1)

void	get_max_energy(int* balls,int current_num_of_balls,int current_energy,int& max_energy)
{
	if( current_num_of_balls == 2 )
	{
		max_energy = max(max_energy,current_energy);
		return;
	}
	
	for(int i=2;i<current_num_of_balls;i++)
	{
		int	next_balls[MAX_SIZE],index;
		
		index = 1;
		
		for(int j=1;j<=current_num_of_balls;j++)
		{
			if( j != i )
			{
				next_balls[index++] = balls[j];
			}
		}
		
		get_max_energy(next_balls,current_num_of_balls-1,current_energy+balls[i-1]*balls[i+1],max_energy);
	}
}

int		main(void)
{
	int	N,balls[MAX_SIZE],max_energy;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>balls[i];
	}
	
	max_energy = 0;
	
	get_max_energy(balls,N,0,max_energy);
	
	cout<<max_energy<<'\n';
	
	return	0;
}
