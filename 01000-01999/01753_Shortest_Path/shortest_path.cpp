#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_V	(20000+1)

typedef	unsigned int		uint32;
typedef	pair<int,uint32>	Edge;	// first: cost, second: node

vector<Edge>			graph[MAX_NUM_OF_V];
vector<int>				shortest_path_len(MAX_NUM_OF_V,0x7FFFFFFF);	
priority_queue<Edge>	pq;

void	find_shortest_path(void)
{
	while( !pq.empty() )
	{
		int	current_node_cost;
		int	current_node;
		
		current_node_cost = pq.top().first*-1;
		current_node = pq.top().second;
		
		pq.pop();
		
		if( shortest_path_len[current_node] < current_node_cost )
		{
			continue;
		}
		
		for(uint32 i=0;i<graph[current_node].size();i++)
		{
			int	next_node;
			int	next_node_cost,new_cost;
			
			next_node = graph[current_node][i].second;
			next_node_cost = graph[current_node][i].first;
			
			new_cost = next_node_cost+current_node_cost;
			
			if( new_cost < shortest_path_len[next_node] )
			{
				shortest_path_len[next_node] = new_cost;
				pq.push(make_pair(new_cost*-1,next_node));
			}
		}
	} 
}

int		main(void)
{
	uint32		V,E,K,i;
	
    cin.sync_with_stdio(false);
	cin>>V>>E>>K;
	
	for(i=1;i<=E;i++)
	{
		uint32				u,v,w;
			
		cin>>u>>v>>w;
		graph[u].push_back(make_pair(w,v));
	}
	
	shortest_path_len[K] = 0;
	pq.push(make_pair(0,K));	// first: cost, second: node
	
	find_shortest_path();
	
	for(i=1;i<=V;i++)
	{
		if( shortest_path_len[i] != 0x7FFFFFFF )
		{
			cout<<shortest_path_len[i]<<endl;
		}
		else
		{
			cout<<"INF\n";
		}
	}
	
	return	0;	
}
