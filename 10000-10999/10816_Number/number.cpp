#include	<iostream>

using namespace	std;

#define	OFFSET		10000000
#define	MAX_SIZE	(OFFSET*2+1)

int	number_card[MAX_SIZE];

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int				N,M;

	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	n;
		
		cin>>n;
		number_card[n+OFFSET]++;
	}
	
	cin>>M;
	
	for(int i=1;i<=M;i++)
	{
		int	n;
		
		cin>>n;
		cout<<number_card[n+OFFSET]<<' ';
	}
	cout<<'\n';
	
	return	0;
}
