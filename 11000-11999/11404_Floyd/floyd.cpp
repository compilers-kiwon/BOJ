#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_CITY	(100+1)

int		n,m,path[MAX_NUM_OF_CITY][MAX_NUM_OF_CITY];

void	input(void)
{
	cin>>n>>m;
	
	for(int i=1;i<=m;i++)
	{
		int	a,b,c;
		
		cin>>a>>b>>c;
		
		if( path[a][b] == 0 || path[a][b] > c )
		{
			path[a][b] = c;
		}
	}
}

void	find_min_path(void)
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if( i == j )
				{
					continue;
				}
				
				if( path[i][k] != 0 && path[k][j] != 0 )
				{
					if( path[i][j] == 0 || path[i][j] > path[i][k]+path[k][j] )
					{
						path[i][j] = path[i][k]+path[k][j];
					}
				}
			}
		}
	}
}

int		main(void)
{
	input();
	find_min_path();
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<path[i][j]<<' ';
		}
		cout<<'\n';
	}
	
	return	0;
}
