#include	<iostream>

using namespace	std;

#define	MAX_LEN	(1000+1)

int	A[MAX_LEN],table[MAX_LEN];

int	main(void)
{
	int	N,answer;
	
	cin>>N;
	answer = 0;
	
	for(int i=1;i<=N;i++)
	{
		cin>>A[i];
		
		int	cnt = 0;
		
		for(int j=1;j<i;j++)
		{
			if( A[i] < A[j] )
			{
				cnt = max(cnt,table[j]);
			}
		}
		table[i] = cnt+1;
		answer = max(answer,table[i]);
	}
	cout<<answer<<endl;
	
	return	0;
}
