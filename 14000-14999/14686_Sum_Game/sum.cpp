#include	<iostream>

using namespace	std;

#define	MAX_DAYS	(100000+1)

int	N,t1[MAX_DAYS],t2[MAX_DAYS];

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>t1[i];
	}
	
	for(int i=1;i<=N;i++)
	{
		cin>>t2[i];
	}
	
	int	sum1,sum2,same_day;
	
	sum1 = sum2 = same_day = 0;
	
	for(int i=1;i<=N;i++)
	{
		sum1 += t1[i];
		sum2 += t2[i];
		
		if( sum1 == sum2 )
		{
			same_day = i;
		}
	}
	
	cout<<same_day<<'\n';
	
	return	0;
}
