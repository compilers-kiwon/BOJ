#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	10
#define	INF			0x7FFFFFFF

int	N,K,T[MAX_SIZE][MAX_SIZE];

void	input(void)
{
	cin>>N>>K;
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>T[i][j];
		}
	}
}

void	update(void)
{
	for(int k=0;k<N;k++)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if( i==j || T[i][k]==0 || T[k][j]==0 )
				{
					continue;
				}
				
				if( T[i][j]==0 || T[i][j]>T[i][k]+T[k][j] )
				{
					T[i][j] = T[i][k]+T[k][j];
				}
			}
		}
	}
}

int		find_shortest_path(void)
{
	int			ret;
	vector<int>	p;
	
	for(int i=0;i<N;i++)
	{
		p.push_back(i);
	}
	
	ret = INF;
	
	do{
		if( p.front() != K )
		{
			continue;
		}
		
		int	current;
		
		current = 0;
		
		for(int i=0;i<N-1;i++)
		{
			current += T[p[i]][p[i+1]];
		}
		
		ret = min(ret,current);
	}while(next_permutation(p.begin(),p.end()));
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	update();
	
	cout<<find_shortest_path()<<'\n';
	
	return	0;
}
