#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1000+1)

int	main(void)
{
	int	n,A[MAX_SIZE],S[MAX_SIZE];
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>A[i];
		
		S[i] = 0;
		
		for(int j=1;j<i;j++)
		{
			if( A[j] < A[i] )
			{
				S[i]++;
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		cout<<S[i]<<'\n';
	}
	
	return	0;
}
