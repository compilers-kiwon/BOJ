#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100+1)

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int	N,M,v[MAX_SIZE];
	
		cin>>N>>M;
		fill(&v[1],&v[N+1],0);
	
		for(int r=1;r<=M;r++)
		{
			for(int c=1;c<=N;c++)
			{
				int n;
				
				cin>>n;
				v[c] += n;
			}
		}
		
		int	max_vote,winner;
		
		max_vote = 0;
		
		for(int c=1;c<=N;c++)
		{
			if( v[c] > max_vote )
			{
				max_vote = v[c];
				winner = c;
			}
		}
		
		cout<<winner<<'\n';
	}
	
	return	0;
}
