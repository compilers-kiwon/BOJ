#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(1500*1500)

int	N,num[MAX_SIZE];

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=0;i<N*N;i++)
	{
		cin>>num[i];
	}
	
	sort(&num[0],&num[N*N]);
	cout<<num[N*N-N]<<'\n';
	
	return	0;
}
