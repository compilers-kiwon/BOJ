#include	<iostream>

using namespace	std;

#define	MAX_SIZE	6
#define	MAX_NUM		49

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	N;
		
		cin>>N;
		
		if( N == 0 )
		{
			break;
		}
		
		int		cnt;
		bool	appeared[MAX_NUM+1];
		
		cnt = 0;
		fill(&appeared[1],&appeared[MAX_NUM+1],false);
		
		for(int i=1;i<=N;i++)
		{
			for(int t=1;t<=MAX_SIZE;t++)
			{
				int	n;
				
				cin>>n;
				
				if( appeared[n] == false )
				{
					appeared[n] = true;
					cnt++;
				}
			}
		}
		
		if( cnt == MAX_NUM )
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
	}
	
	return	0;
}
