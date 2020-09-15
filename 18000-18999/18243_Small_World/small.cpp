#include	<iostream>

using namespace	std;

#define	MAX_SIZE				(100+1)
#define	INF						MAX_SIZE
#define	MAX_ALLOWED_DISTANCE	6

int	N,K,d[MAX_SIZE][MAX_SIZE];

void	init(void)
{
	cin>>N>>K;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			d[i][j] = INF;
		}
		d[i][i] = 0;
	}
	
	for(int i=1;i<=K;i++)
	{
		int	A,B;
		
		cin>>A>>B;
		d[A][B] = d[B][A] = 1;
	}
}

bool	travel_network(void)
{	
	for(int k=1;k<=N;k++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if( d[i][j] > d[i][k]+d[k][j] )
				{
					d[i][j] = d[j][i] = d[i][k]+d[k][j];
				}
			}
		}
	}
	
	for(int i=1;i<=N-1;i++)
	{
		for(int j=i+1;j<=N;j++)
		{
			if( d[i][j] > MAX_ALLOWED_DISTANCE )
			{
				return	false;
			}
		}
	}
	return	true;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	init();
	
	if( travel_network() == true )
	{
		cout<<"Small World!\n";
	}
	else
	{
		cout<<"Big World!\n";
	}
	
	return	0;
}
