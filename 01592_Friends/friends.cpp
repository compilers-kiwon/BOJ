#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_PEOPLE	1000

int	main(void)
{
	int	p[MAX_NUM_OF_PEOPLE];
	int	N,M,L,R,current,cnt;
	
	cin>>N>>M>>R;
	L = N-R;
	
	for(int i=0;i<N;i++)
	{
		p[i] = 0;
	}
	
	current = 1;
	p[current] = 1;
	cnt = 0;
	
	while( p[current] < M )
	{
		if( p[current]%2 == 1 )
		{
			current = (current+R)%N;
		}
		else
		{
			current = (current+L)%N;
		}
		++p[current];
		++cnt;
	}
	cout<<cnt<<endl;
	
	return	0;
}
