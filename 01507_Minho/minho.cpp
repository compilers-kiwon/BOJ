#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_CITY	(20+1)

int	main(void)
{
	int	N,map[MAX_NUM_OF_CITY][MAX_NUM_OF_CITY],optimized[MAX_NUM_OF_CITY][MAX_NUM_OF_CITY];
	
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cin>>map[i][j];
			optimized[i][j] = map[i][j];
		}
	}
	
	for(int k=1;k<=N;k++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if( map[i][j]==0 || (i==k||j==k) )
				{
					continue;
				}
				
				if( map[i][j] == map[i][k]+map[k][j] )
				{
					optimized[i][j] = 0;
				}
				else if( map[i][j] > map[i][k]+map[k][j] )
				{
					cout<<-1<<'\n';
					
					return	0;
				}
			}
		}
	}
	
	int	sum;
	
	sum = 0;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=i+1;j<=N;j++)
		{
			sum += optimized[i][j];
		}
	}
	
	cout<<sum<<'\n';
	
	return	0;
}
