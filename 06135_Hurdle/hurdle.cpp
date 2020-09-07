#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_ROOMS	(300+1)
#define	NONE				0

int	N,M,T;
int	connected[MAX_NUM_OF_ROOMS][MAX_NUM_OF_ROOMS];

void	init(void)
{
	cin>>N>>M>>T;
	
	for(int i=1;i<=M;i++)
	{
		int	S,E,H;
		
		cin>>S>>E>>H;
		connected[S][E] = H;
	}
}

void	do_query(void)
{
	for(int i=1;i<=T;i++)
	{
		int	A,B;
		
		cin>>A>>B;
		
		if( connected[A][B] == 0 )
		{
			cout<<"-1\n";
		}
		else
		{
			cout<<connected[A][B]<<'\n';
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	init();
	
	for(int k=1;k<=N;k++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if( connected[i][k]!=NONE && connected[k][j]!=NONE )
				{
					int	tallest;
					
					tallest = max(connected[i][k],connected[k][j]);
					
					if( connected[i][j]==NONE || tallest<connected[i][j] )
					{
						connected[i][j] = tallest;
					}
				}
			}
		}
	}
	
	do_query();
	
	return	0;
}
