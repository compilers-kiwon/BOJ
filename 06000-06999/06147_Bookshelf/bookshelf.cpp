#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(20000+1)

int	N,B,H[MAX_SIZE];

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>N>>B;
	
	for(int i=1;i<=N;i++)
	{
		cin>>H[i];
	}
	
	sort(&H[1],&H[N+1]);
	
	int	sum,cnt;
	
	sum = 0;
	cnt = 1;
	
	for(int i=N;i>0;i--,cnt++)
	{
		sum += H[i];
		
		if( sum >= B )
		{
			break;
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
