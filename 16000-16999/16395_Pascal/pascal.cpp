#include	<iostream>

using namespace	std;

#define	MAX_SIZE	30

typedef	unsigned long long	uint64;

int	main(void)
{
	int		n,k;
	uint64	pascal_tri[MAX_SIZE+1][MAX_SIZE+1];
	
	for(int i=0;i<=MAX_SIZE;i++)
	{
		for(int j=0;j<=MAX_SIZE;j++)
		{
			pascal_tri[i][j] = 0;
		}
	}
	
	pascal_tri[0][0] = 1;
	
	for(int i=1;i<=MAX_SIZE;i++)
	{
		for(int j=1;j<=i;j++)
		{
			pascal_tri[i][j] = pascal_tri[i-1][j-1]+pascal_tri[i-1][j];
		}
	}
	
	cin>>n>>k;
	cout<<pascal_tri[n][k]<<'\n';
	
	return	0;	
}
