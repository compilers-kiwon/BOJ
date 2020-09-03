#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_SEAT	(500+1)

int	main(void)
{
	int	K;
	
	cin>>K;
	
	while(K>0)
	{
		int		P,M,cnt;
		bool	seat[MAX_NUM_OF_SEAT];
		
		cin>>P>>M;
		
		for(int i=1;i<=M;i++)
		{
			seat[i] = false;
		}
		
		cnt = 0;
		
		for(int i=1;i<=P;i++)
		{
			int	m;
			
			cin>>m;
			
			if( seat[m] == false )
			{
				seat[m] = true;
			}
			else
			{
				++cnt;
			}
		}
		cout<<cnt<<endl;
		
		K--;
	}
	return	0;
}
