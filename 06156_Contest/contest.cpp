#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_COW	(100+1)

#define	TBD		0
#define	WIN		1
#define	LOSE	2

int	N,M;
int	table[MAX_NUM_OF_COW][MAX_NUM_OF_COW];

void	init(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=M;i++)
	{
		int	A,B;
		
		cin>>A>>B;
		
		table[A][B] = WIN;
		table[B][A] = LOSE;
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
				if( table[i][j] == TBD )
				{
					if( table[i][k]==LOSE && table[k][j]==LOSE )
					{
						table[i][j] = LOSE;
						table[j][i] = WIN;
					}
					
					if( table[i][k]==WIN && table[k][j]==WIN )
					{
						table[i][j] = WIN;
						table[j][i] = LOSE;
					}
				}
			}
		}
	}
	
	int	cnt = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	num_of_result=0;
		
		for(int j=1;j<=N;j++)
		{
			if( table[i][j] != TBD )
			{
				num_of_result++;
			}
		}
		
		if( num_of_result == N-1 )
		{
			cnt++;
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
