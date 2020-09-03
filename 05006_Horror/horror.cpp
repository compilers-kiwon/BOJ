#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	1000
#define	INF			0x7FFFFFFF

int			N,H,L,HI[MAX_SIZE];
vector<int>	similar[MAX_SIZE];
queue<int>	movie_q;

void	init(void)
{
	cin>>N>>H>>L;
	
	for(int i=0;i<N;i++)
	{
		HI[i] = INF;
	}
	
	for(int i=1;i<=H;i++)
	{
		int	m;
		
		cin>>m;
		
		HI[m] = 0;
		movie_q.push(m);
	}
	
	for(int i=1;i<=L;i++)
	{
		int	m1,m2;
		
		cin>>m1>>m2;
		
		similar[m1].push_back(m2);
		similar[m2].push_back(m1);
	}
}

void	update_similarity(void)
{
	for(;!movie_q.empty();)
	{
		int	current_movie;
		
		current_movie = movie_q.front();
		movie_q.pop();
		
		vector<int>&	adj = similar[current_movie];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_movie = adj[i];
			
			if( HI[adj_movie] == INF )
			{
				HI[adj_movie] = HI[current_movie]+1;
				movie_q.push(adj_movie);
			}
		}
	}
}

int		find_best_movie(void)
{
	int	ret,max_idx;
	
	max_idx = -1;
	
	for(int i=0;i<N;i++)
	{
		if( HI[i] > max_idx )
		{
			ret = i;
			max_idx = HI[i];
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	init();
	update_similarity();
	
	cout<<find_best_movie()<<'\n';
	
	return	0;
}
