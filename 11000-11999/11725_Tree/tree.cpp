#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM	(100000+1)
#define	ROOT	1

vector<int>	connected[MAX_NUM];
vector<int>	parent(MAX_NUM,-1);
queue<int>	nq;

int	main(void)
{
	int	N;
	
	scanf("%d",&N);
	
	for(int i=1;i<N;i++)
	{
		int	n1,n2;
		
		scanf("%d %d",&n1,&n2);
		connected[n1].push_back(n2);
		connected[n2].push_back(n1);
	}
	
	parent[ROOT] = 0;
	nq.push(ROOT);
	
	while( nq.size() != 0 )
	{
		int	current_node;
		
		current_node = nq.front();
		nq.pop();
		
		for(int i=0;i<connected[current_node].size();i++)
		{
			int	connected_node = connected[current_node][i];
			
			if( parent[connected_node] == -1 )
			{
				parent[connected_node] = current_node;
				nq.push(connected_node);
			}
		}
	}
	
	for(int i=2;i<=N;i++)
	{
		printf("%d\n",parent[i]);
	}
	
	return	0;
}
