#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_NATIONS	(1000+1)

vector<int>	connected[MAX_NUM_OF_NATIONS];
int			N,M;

void	input(void)
{
	int	M;
	
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=M;i++)
	{
		int	a,b;
		
		scanf("%d %d",&a,&b);
		
		connected[a].push_back(b);
		connected[b].push_back(a);
	}
}

int		visit_to_nations(void)
{
	vector<bool>	visited(N+1,false);
	queue<int>		visited_nations;
	int				cnt;
	
	visited_nations.push(1);
	visited[1] = true;
	cnt = 0;
	
	while( visited_nations.size() != 0 )
	{
		int	current_nation;
		
		current_nation = visited_nations.front();
		visited_nations.pop();
		
		for(int i=0;i<connected[current_nation].size();i++)
		{
			int	next_nation;
			
			next_nation = connected[current_nation][i];
			
			if( visited[next_nation] == false )
			{
				visited[next_nation] = true;
				visited_nations.push(next_nation);
				cnt++;
			}
		}
	}
	return	cnt;
}

int		main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	while(T>0)
	{
		input();
		
		printf("%d\n",visit_to_nations());
		
		for(int i=1;i<=N;i++)
		{
			connected[i].clear();
		}
		
		T--;
	}
	return	0;
}
