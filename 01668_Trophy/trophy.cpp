#include	<iostream>

using namespace	std;

#define	TO_LEFT		-1
#define	TO_RIGHT	1

#define	MAX_NUM_OF_TROPHY	(50+1)

int	count_visible_trophy(int* trophy,int from,int to,int direction)
{
	int	high,cnt;
	
	high = cnt = 0;
	
	for(int i=from;i!=to;i+=direction)
	{
		if( trophy[i] > high )
		{
			high = trophy[i];
			cnt++;
		}
	}
	
	return	cnt;
}

int	main(void)
{
	int	N,trophy[MAX_NUM_OF_TROPHY];
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>trophy[i];
	}
	
	cout<<count_visible_trophy(trophy,1,N+1,TO_RIGHT)<<endl;
	cout<<count_visible_trophy(trophy,N,0,TO_LEFT)<<endl;
	
	return	0;
}
