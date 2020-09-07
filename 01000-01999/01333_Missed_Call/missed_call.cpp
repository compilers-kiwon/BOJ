#include	<iostream>

using namespace	std;

#define	MAX_TIME	2000000

bool	play_table[MAX_TIME];

int		main(void)
{
	int	N,L,D,current_time;
	
	cin>>N>>L>>D;
	
	current_time = 1;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<L;j++,current_time++)
		{
			play_table[current_time] = true;
		}
		current_time += 5;
	}
	
	current_time = D+1;
	
	while( play_table[current_time] != false )
	{
		current_time += D;
	}
	cout<<current_time-1<<endl;
	
	return	0;
}
