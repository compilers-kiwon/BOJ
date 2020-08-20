#include	<iostream>
#include	<algorithm>

using namespace	std;

typedef	unsigned long long	uint64;

#define	MAX_POINT	(10000+1)

uint64	x[MAX_POINT];

int	main(void)
{
	int	n;
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	
	sort(&x[1],&x[n+1]);
	
	uint64	diff;
	
	diff = 0;
	
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			diff += x[j]-x[i];
		}
	}
	cout<<diff*2<<endl;
	
	return	0;
}
