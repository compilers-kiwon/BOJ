#include	<iostream>

using namespace	std;

#define	INF					0x1000000
#define	MAX_NUM_OF_PLACE	(100+1)

int	n,m,r;
int	d[MAX_NUM_OF_PLACE][MAX_NUM_OF_PLACE],num_of_item[MAX_NUM_OF_PLACE];

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>n>>m>>r;
	
	for(int i=1;i<=n;i++)
	{
		cin>>num_of_item[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			d[i][j] = INF;
		}
		d[i][i] = 0;
	}
	
	for(int i=1;i<=r;i++)
	{
		int	a,b,l;
		
		cin>>a>>b>>l;
		d[a][b] = d[b][a] = l;
	}
}

int		get_max_num_of_items(void)
{
	int	max_num_of_item;
	
	max_num_of_item = 0;
	
	for(int i=1;i<=n;i++)
	{
		int	sum;
		
		sum = 0;
		
		for(int j=1;j<=n;j++)
		{
			if( d[i][j] <= m )
			{
				sum += num_of_item[j];
			}
		}
		
		max_num_of_item = max(max_num_of_item,sum);
	}
	
	return	max_num_of_item;
}

int		main(void)
{
	init();
	
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if( d[i][j] > d[i][k]+d[j][k] )
				{
					d[i][j] = d[j][i] = d[i][k]+d[j][k];
				}
			}
		}
	}
	
	cout<<get_max_num_of_items()<<'\n';
	
	return	0;
}
