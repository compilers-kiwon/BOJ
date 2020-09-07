#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_PLACE	(500+1)
#define	INF					0x4FFFFFFF

typedef	pair<int,int>	Road;	// first:to,second:time

int				T;
int				N,M,W;
int				time_table[MAX_NUM_OF_PLACE];
vector<Road>	connected[MAX_NUM_OF_PLACE];

void	input(void)
{
	scanf("%d %d %d",&N,&M,&W);
	
	for(int i=1;i<=M;i++)
	{
		int	s,e,t;
		
		scanf("%d %d %d",&s,&e,&t);
		
		connected[s].push_back(make_pair(e,t));
		connected[e].push_back(make_pair(s,t));
	}
	
	for(int i=1;i<=W;i++)
	{
		int	s,e,t;
		
		scanf("%d %d %d",&s,&e,&t);
		
		connected[s].push_back(make_pair(e,-t));
	}
	
	for(int i=1;i<=N;i++)
	{
		time_table[i] = INF;
	}
}

bool	find_minus_time_path(void)
{
	for(int i=1;i<=N;i++)
	{
		if( time_table[i] != INF )
		{
			continue;
		}
		
		time_table[i] = 0;
		
		for(int update_cnt=1;update_cnt<=N;update_cnt++)
		{
			for(int j=1;j<=N;j++)
			{
				if( time_table[j] == INF )
				{
					continue;
				}
				
				for(int k=0;k<connected[j].size();k++)
				{
					int&	adj_place = connected[j][k].first;
					int&	adj_time = connected[j][k].second;
					
					if( time_table[adj_place] > time_table[j]+adj_time )
					{
						time_table[adj_place] = time_table[j]+adj_time;
						
						if( update_cnt == N )
						{
							return	true;
						}
					}
				}
			}
		}
	}
	
	return	false;
}

int		main(void)
{
	scanf("%d",&T);
	
	while(T>0)
	{
		input();
		
		if( find_minus_time_path() == true )
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
		
		for(int i=1;i<=N;i++)
		{
			connected[i].clear();
		}
		
		T--;
	}
}
