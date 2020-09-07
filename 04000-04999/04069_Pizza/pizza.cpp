#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(10+1)
#define	INVALID		-1
#define	PIZZERIA	0
#define	INF			0x1000000

int	get_delivery_time(vector<int>& p,int path[][MAX_SIZE])
{
	int	ret;
	
	if( path[PIZZERIA][p.front()] == INF )
	{
		return	INVALID;
	}
	
	ret = path[PIZZERIA][p.front()];
	
	for(int i=1;i<p.size();i++)
	{
		int&	from = p[i-1];
		int&	to = p[i];
		
		if( path[from][to] == 0 )
		{
			return	INVALID;
		}
		
		ret += path[from][to];
	}
	
	if( path[p.back()][PIZZERIA] == INF )
	{
		return	INVALID;
	}
	
	return	(ret+path[p.back()][PIZZERIA]);
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	n,path[MAX_SIZE][MAX_SIZE],min_time;
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		for(int from=PIZZERIA;from<=n;from++)
		{
			for(int to=PIZZERIA;to<=n;to++)
			{
				cin>>path[from][to];
				
				if( path[from][to] == 0 )
				{
					path[from][to] = INF;
				}
			}
		}
		
		for(int k=0;k<=n;k++)
		{
			for(int i=0;i<=n;i++)
			{
				for(int j=0;j<=n;j++)
				{
					if( i == j )
					{
						continue;
					}
					
					if( path[i][j] > path[i][k]+path[k][j] )
					{
						path[i][j] = path[i][k]+path[k][j];
					}
				}
			}
		}
		
		min_time = INF;
		
		vector<int>	delivery;
		
		for(int i=1;i<=n;i++)
		{
			delivery.push_back(i);
		}
		
		do{
			int	time;
			
			time = get_delivery_time(delivery,path);
			
			if( time != INVALID )
			{
				min_time = min(min_time,time);
			}
		}while(next_permutation(delivery.begin(),delivery.end()));
		
		cout<<min_time<<'\n';
	}
	
	return	0;
}
