#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_SIGNAL	(100+1)

int	main(void)
{
	int		N,L,time,current;
		
	cin>>N>>L;
	
	current = time = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	D,R,G,tmp;
		
		cin>>D>>R>>G;
		
		time += D-current;
		current = D;
		
		tmp = time%(R+G);
		
		if( tmp < R )
		{
			time += R-tmp;
		}
	}
	
	cout<<time+L-current<<endl;
	
	return	0;	
}
