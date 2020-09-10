#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(200+1)

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	m,n_min,n_max,P[MAX_SIZE];
		
		cin>>m>>n_min>>n_max;
		
		if( m==0 && n_min==0 && n_max==0 )
		{
			break;
		}
		
		for(int i=1;i<=m;i++)
		{
			cin>>P[i];
		}
		
		int	max_gap,n;
		
		max_gap = 0;
		
		for(int i=n_min;i<=n_max;i++)
		{
			int	gap;
			
			gap = P[i]-P[i+1];
			
			if( gap!=0 && gap>=max_gap )
			{
				max_gap = gap;
				n = i; 
			}
		}
		
		cout<<n<<'\n';
	}
	
	return	0;
}
