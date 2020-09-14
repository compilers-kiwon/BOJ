#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_FRUIT	(1000+1)

int	main(void)
{
	int	N,L,h[MAX_NUM_OF_FRUIT];
	
	cin.sync_with_stdio(false);
	
	cin>>N>>L;
	
	for(int i=1;i<=N;i++)
	{
		cin>>h[i];
	}
	
	for(;;)
	{
		bool	flag;
		
		flag = false;
		
		for(int i=1;i<=N;i++)
		{
			if( h[i]!=0 && L>=h[i] )
			{
				h[i] = 0;
				flag = true;
				L++;
			}
		}
		
		if( flag == false )
		{
			break;
		}
	}
	
	cout<<L<<'\n';
	
	return	0;
}
