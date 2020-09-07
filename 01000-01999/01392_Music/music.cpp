#include	<iostream>

using namespace	std;

#define	MAX_TIME	(100*100)

int	music_table[MAX_TIME];

int	main(void)
{
	int	N,Q;
	
	cin>>N>>Q;
	
	for(int i=1,current_time=0;i<=N;i++)
	{
		int	T;
		
		cin>>T;
		
		for(int j=0;j<T;j++)
		{
			music_table[current_time+j] = i;
		}
		current_time += T;
	}
	
	for(int i=1;i<=Q;i++)
	{
		int	T;
		
		cin>>T;
		cout<<music_table[T]<<endl;
	}
	
	return	0;
}
