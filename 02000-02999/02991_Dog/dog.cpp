#include	<iostream>

using namespace	std;

#define	MAX_TIME	999

int	main(void)
{
	int	i,time_table[MAX_TIME*2];
	
	for(i=0;i<MAX_TIME*2;i++)
	{
		time_table[i] = 0;
	}
	
	int	A,B,C,D;
	
	cin>>A>>B>>C>>D;
	
	for(i=1;i<MAX_TIME;i+=(A+B))
	{
		for(int j=0;j<A;j++)
		{
			time_table[i+j]++;
		}
	}
	
	for(i=1;i<MAX_TIME;i+=(C+D))
	{
		for(int j=0;j<C;j++)
		{
			time_table[i+j]++;
		}
	}
	
	int	P,M,N;
	
	cin>>P>>M>>N;
	
	cout<<time_table[P]<<endl<<time_table[M]<<endl<<time_table[N]<<endl;
	
	return	0;
}
