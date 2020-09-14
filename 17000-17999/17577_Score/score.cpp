#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1000+1)

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	n,m,sum[MAX_SIZE],max_score;
		
		cin>>n>>m;
		
		if( n==0 && m==0 )
		{
			break;
		}
		
		max_score = 0;
		fill(&sum[1],&sum[n+1],0);
		
		for(int subject=1;subject<=m;subject++)
		{
			for(int student=1;student<=n;student++)
			{
				int	p;
				
				cin>>p;
				sum[student] += p;
			}
		}
		
		for(int student=1;student<=n;student++)
		{
			max_score = max(max_score,sum[student]);
		}
		
		cout<<max_score<<'\n';
	}
	
	return	0;
}
