#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_CITY	(200+1)

#define	TRUE	1
#define	FALSE	0

int	map[MAX_NUM_OF_CITY][MAX_NUM_OF_CITY];

int	main(void)
{
	int	N,M;
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cin>>map[i][j];
		}
		map[i][i] = TRUE;
	}
	
	for(int k=1;k<=N;k++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if( map[i][j] == FALSE )
				{
					if( map[i][k] == TRUE && map[k][j] == TRUE )
					{
						map[i][j] = TRUE;
					}
				}
			}
		}
	}
	
	int	prev,result;
	
	cin>>prev;
	result = TRUE;
	
	for(int i=2;i<=M;i++)
	{
		int	next;
		
		cin>>next;
		
		if( map[prev][next] == FALSE )
		{
			result = FALSE;
			break;
		}
		
		prev = next;
	}
	
	if( result == TRUE )
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
	
	return	0;
}
