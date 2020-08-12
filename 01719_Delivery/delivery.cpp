#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_PLACES	(200+1)
#define	INF					200000

int	first_place[MAX_NUM_OF_PLACES][MAX_NUM_OF_PLACES];
int	dist[MAX_NUM_OF_PLACES][MAX_NUM_OF_PLACES];

int	main(void)
{
	int	n,m;
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dist[i][j] = INF;
		}
		dist[i][i] = 0;
	}
	
	for(int i=1;i<=m;i++)
	{
		int	p1,p2,d;
		
		cin>>p1>>p2>>d;
		dist[p1][p2] = dist[p2][p1] = d;
		first_place[p1][p2] = p2;
		first_place[p2][p1] = p1;
	}
	
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if( dist[i][j] > dist[i][k]+dist[k][j])
				{
					dist[i][j] = dist[i][k]+dist[k][j];
					first_place[i][j] = first_place[i][k];
				}				
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if( i == j )
			{
				cout<<"- ";
			}
			else
			{
				cout<<first_place[i][j]<<' ';
			}
		}
		cout<<endl;
	}
	
	return	0;
}
