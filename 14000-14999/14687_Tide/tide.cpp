#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(100+1)

int	main(void)
{
	int	N,tail_of_lower;
	int	measured[MAX_SIZE],ordered[MAX_SIZE];
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>measured[i];
	}
	
	sort(&measured[1],&measured[N+1]);
	
	if( N%2 == 0 )
	{
		tail_of_lower = N/2;
	}
	else
	{
		tail_of_lower = N/2+1;
	}
	
	for(int i=1,j=tail_of_lower;i<=N;i+=2,j--)
	{
		ordered[i] = measured[j];
	}
	
	for(int i=2,j=tail_of_lower+1;i<=N;i+=2,j++)
	{
		ordered[i] = measured[j];
	}
	
	for(int i=1;i<=N;i++)
	{
		cout<<ordered[i]<<' ';
	}
	cout<<'\n';
	
	return	0;
}
