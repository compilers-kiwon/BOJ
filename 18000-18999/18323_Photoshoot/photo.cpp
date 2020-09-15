#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1000+1)

int	N,a[MAX_SIZE],b[MAX_SIZE];

int	main(void)
{
	cin>>N;
	
	for(int i=1;i<=N-1;i++)
	{
		cin>>b[i];
	}
	
	for(int i=1;;i++)
	{
		int		j;
		bool	used[MAX_SIZE];
		
		fill(&used[1],&used[N+1],false);
		a[1] = i;
		used[i] = true;
		
		for(j=1;j<=N-1;j++)
		{
			int&	current = a[j];
			int&	next = a[j+1];
			
			next = b[j]-current;
			
			if( next>N || used[next]==true )
			{
				break;
			}
			
			used[next] = true;
		}
		
		if( j == N )
		{
			break;
		}
	}
	
	for(int i=1;i<=N-1;i++)
	{
		cout<<a[i]<<' ';
	}
	cout<<a[N]<<'\n';
	
	return	0;
}
