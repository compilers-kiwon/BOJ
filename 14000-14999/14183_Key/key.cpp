#include	<iostream>

using namespace	std;

#define	MAX_SIZE		(10+1)
#define	MAX_NUM_OF_KEYS	(100+1)
#define	CUSTOMER_KEY	0

int	m,n,key[MAX_NUM_OF_KEYS][MAX_SIZE];

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		cin>>m>>n;
		
		if( m==0 && n==0 )
		{
			break;
		}
		
		for(int i=0;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>key[i][j];
			}
		}
		
		int	cnt;
		
		cnt = 0;
		
		for(int i=1;i<=n;i++)
		{
			bool	result;
			
			result = true;
			
			for(int j=1;j<=m&&result!=false;j++)
			{
				if( key[CUSTOMER_KEY][j] < key[i][j] )
				{
					result = false;
				}
			}
			
			if( result == true )
			{
				cnt++;
			}
		}
		
		cout<<cnt<<'\n';
	}
	
	return	0;
}
