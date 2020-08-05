#include	<iostream>

using namespace	std;

#define	MAX_NUM	(1000+1)
#define	INF		10000000

int	table[MAX_NUM][MAX_NUM];

int	main(void)
{
	int	N,M,X;
	
	cin>>N>>M>>X;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			table[i][j] = INF;
		
		}
		table[i][i] = 0;
	}
	
	for(int i=1;i<=M;i++)
	{
		int	from,to,t;
		
		cin>>from>>to>>t;
		table[from][to] = t;
	}
	
	for(int k=1;k<=N;k++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if( table[i][j] > table[i][k]+table[k][j] )
				{
					table[i][j] = table[i][k]+table[k][j];
				}
			}
		}
	}
	
	int	max_time = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	time;
		
		time = table[i][X]+table[X][i];
		max_time = max(max_time,time);
	}
	cout<<max_time<<endl;
	
	return	0;
}
