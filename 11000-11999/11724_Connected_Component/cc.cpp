#include	<cstdio>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_V	(1000+1)

vector<int>	edge[MAX_NUM_OF_V];
vector<int>	visited(MAX_NUM_OF_V,0);

void	visit(int v,int visit_index)
{
	queue<int>	vq;
	
	vq.push(v);
	
	while( vq.size() != 0 )
	{
		int	current;
		
		current = vq.front();
		vq.pop();
		
		for(int i=0;i<edge[current].size();i++)
		{
			int	connected;
			
			connected = edge[current][i];
			
			if( visited[connected] == 0 )
			{
				visited[connected] = visit_index;
				vq.push(connected);
			}
		}
	}
}

int		main(void)
{
	int	N,M;
	
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=M;i++)
	{
		int	u,v;
		
		scanf("%d %d",&u,&v);
		
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	
	int i,cnt;
	
	for(i=1,cnt=0;i<=N;i++)
	{
		if( visited[i] == 0 )
		{
			++cnt;
			visited[i] = cnt;
			visit(i,cnt);
		}
	}
	printf("%d\n",cnt);
	
	return	0;
}
