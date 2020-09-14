#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_LEN	(500000+1)

int	num[MAX_LEN];

int	main(void)
{
	int	N;
	
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>num[i];
	}
	
	stable_sort(&num[1],&num[N+1]);
	
	for(int i=1;i<=N;i++)
	{
		cout<<num[i]<<' ';
	}
	
	return	0;
}
