#include	<iostream>

using namespace	std;

#define	MARRY		0
#define	JOHN		1
#define	MAX_PLAYER	2

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	N,win[MAX_PLAYER];
		
		cin>>N;
		
		if( N == 0 )
		{
			break;
		}
		
		fill(&win[0],&win[MAX_PLAYER],0);
		
		for(int i=1;i<=N;i++)
		{
			int	R;
			
			cin>>R;
			win[R]++;
		}
		
		cout<<"Mary won "<<win[MARRY]<<" times and John won "<<win[JOHN]<<" times\n";
	}
	
	return	0;
}
