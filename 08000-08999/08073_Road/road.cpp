#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(200+1)

int	N,path[MAX_SIZE][MAX_SIZE];
int	cnt[MAX_SIZE][MAX_SIZE],result[MAX_SIZE][MAX_SIZE];

void	input(void)
{
	cin>>N;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			cin>>path[row][col];
			
			result[row][col] = path[row][col];
			cnt[row][col] = 1;
		}
	}
}

void	update(void)
{
	for(int k=1;k<=N;k++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if( i==j || result[i][k]==0 || result[k][j]==0 )
				{
					continue;
				}
				
				if( result[i][j]==0 || result[i][k]+result[k][j]<=result[i][j] )
				{
					if( result[i][j]==0 || result[i][k]+result[k][j]<result[i][j] )
					{
						cnt[i][j] = cnt[j][i] = 0;
					}
					
					result[i][j] = result[j][i] = result[i][k]+result[k][j];
					cnt[i][j]++;cnt[j][i]++;
				}
			}
		}
	}
}

void	find_pairs(void)
{
	for(int i=1;i<=N;i++)
	{
		for(int j=i+1;j<=N;j++)
		{
			if( path[i][j]!=0 && path[i][j]<=result[i][j] && cnt[i][j]==1 )
			{
				cout<<i<<' '<<j<<'\n';
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	update();
	find_pairs();

	return	0;
}
