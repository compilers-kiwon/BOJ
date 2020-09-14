#include	<iostream>

using namespace	std;

#define	MAX_SIZE	1000
#define	INF			0x7FFFFFFF

int	main(void)
{
	int	n,A[MAX_SIZE+1];
	
	cin>>n;
	A[0] = A[1] = 1;
	
	for(int i=2;i<=n;i++)
	{
		for(A[i]=1;;A[i]++)
		{
			bool	flag;
			
			flag = true;
			
			for(int k=1;i-2*k>=0;k++)
			{
				if( A[i]-A[i-k] == A[i-k]-A[i-2*k] )
				{
					flag = false;
					break;
				}
			}
			
			if( flag == true )
			{
				break;
			}
		}
	}
	
	cout<<A[n]<<'\n';
	
	return	0;
}
