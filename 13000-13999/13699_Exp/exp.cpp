#include	<iostream>

using namespace	std;

typedef	unsigned long long	uint64;

#define	MAX_LEN	(35+1)

int	main(void)
{
	uint64	t[MAX_LEN];
	int		n;
	
	cin>>n;
	
	t[0] = 1;
	
	for(int i=1;i<=n;i++)
	{
		t[i] = 0;
		
		for(int j=0,k=i-1;j<=i-1;j++,k--)
		{
			t[i] += t[j]*t[k];
		}
	}
	cout<<t[n]<<endl;
	
	return	0;
}
