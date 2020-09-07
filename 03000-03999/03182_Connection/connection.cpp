#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1000+1)

int	N,adj[MAX_SIZE];

void	init(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>adj[i];
	}
}

int		get_number_of_connections(int p)
{
	int		cnt,i;
	bool	visited[MAX_SIZE];
	
	fill(&visited[1],&visited[N+1],false);
	
	for(cnt=0,i=p;visited[i]!=true;i=adj[i],cnt++)
	{
		visited[i] = true;
	}
	
	return	cnt;
}

int		main(void)
{
	init();
	
	int	max_num_of_connection,p;
	
	max_num_of_connection = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	n;
		
		n = get_number_of_connections(i);
		
		if( max_num_of_connection < n )
		{
			max_num_of_connection = n;
			p = i;
		}
	}
	
	cout<<p<<'\n';
	
	return	0;
}
