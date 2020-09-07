#include	<iostream>

using namespace	std;

int		main(void)
{
	int	T;
	
	cin.sync_with_stdio(false);
	
	cin>>T;
	
	while(T>0)
	{
		int	N,M,S_strong_soldier,B_strong_soldier;
				
		cin>>N>>M;
		
		S_strong_soldier = B_strong_soldier = 0;
		
		for(int i=1;i<=N;i++)
		{
			int	n;
			
			cin>>n;
			S_strong_soldier = max(S_strong_soldier,n);
		}
		
		for(int i=1;i<=M;i++)
		{
			int	n;
			
			cin>>n;
			B_strong_soldier = max(B_strong_soldier,n);
		}
		
		if( S_strong_soldier >= B_strong_soldier )
		{
			puts("S");
		}
		else
		{
			puts("B");
		}
			
		T--;
	}
	
	return	0;
}
