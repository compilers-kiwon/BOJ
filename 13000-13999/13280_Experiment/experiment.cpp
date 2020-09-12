#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	INF			0x7FFFFFFF

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	n,score[MAX_SIZE],min_diff;
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		for(int i=1;i<=n;i++)
		{
			cin>>score[i];
		}
		
		sort(&score[1],&score[n+1]);
		min_diff = INF;
		
		for(int i=1;i<n;i++)
		{
			min_diff = min(min_diff,score[i+1]-score[i]);
		}
		
		cout<<min_diff<<'\n';
	}
	
	return	0;
}
