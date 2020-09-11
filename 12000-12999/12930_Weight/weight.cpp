#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_V	20
#define	char2int(c)		((int)((c)-'0'))

#define	START	0
#define	END		1

typedef	struct	_GRAPH_INFO	Graph;
struct	_GRAPH_INFO
{
	int	to,w1,w2;
};

typedef	pair<int,int>		Weight;	// first:w1_sum, second:w2_sum
typedef	pair<int,Weight>	Vertex;	// first:vertex, second:Weight
typedef	pair<int,Vertex>	State;	// first:-cost, second:Vertex

int				N,w1[MAX_NUM_OF_V][MAX_NUM_OF_V],w2[MAX_NUM_OF_V][MAX_NUM_OF_V];
vector<Graph>	connected[MAX_NUM_OF_V];

void	init(void)
{
	char	buf[MAX_NUM_OF_V+1];
	
	scanf("%d",&N);
	
	for(int i=0;i<N;i++)
	{
		scanf("%s",buf);
		
		for(int j=0;j<N;j++)
		{
			if( buf[j] == '.' )
			{
				w1[i][j] = 0;
			}
			else
			{
				w1[i][j] = char2int(buf[j]);
			}
		}
	}
	
	for(int i=0;i<N;i++)
	{
		scanf("%s",buf);
		
		for(int j=0;j<N;j++)
		{
			if( buf[j] == '.' )
			{
				w2[i][j] = 0;
			}
			else
			{
				w2[i][j] = char2int(buf[j]);
			}
		}
	}
	
	for(int i=0;i<N-1;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			if( w1[i][j] != 0 )
			{
				Graph	v;
				
				v.w1 = w1[i][j];
				v.w2 = w2[i][j];
				
				v.to = j;
				connected[i].push_back(v);
				
				v.to = i;
				connected[j].push_back(v);
			}
		}
	}
}

int		find_min_cost(void)
{
	priority_queue<State>	pq;
	vector<int>				dp(N,0x7FFFFFFF);
	int						min_cost;
	
	dp[START] = 0;
	min_cost = 0x7FFFFFFF;
	pq.push(make_pair(0,make_pair(START,make_pair(0,0))));
	
	while( !pq.empty() )
	{
		int	current_cost,current_v,sum_of_w1,sum_of_w2;
		
		current_cost = -pq.top().first;
		current_v = pq.top().second.first;
		sum_of_w1 = pq.top().second.second.first;
		sum_of_w2 = pq.top().second.second.second;
		
		pq.pop();
		
		if( current_v == END )
		{
			min_cost = current_cost;
			break;
		}
		
		vector<Graph>&	adj_vec = connected[current_v];
		
		for(int i=0;i<adj_vec.size();i++)
		{
			Graph&	adj_v = adj_vec[i];
			int		adj_sum_of_w1,adj_sum_of_w2,adj_cost;
			
			adj_sum_of_w1 = sum_of_w1+adj_v.w1;
			adj_sum_of_w2 = sum_of_w2+adj_v.w2;
			adj_cost = adj_sum_of_w1*adj_sum_of_w2;
			
			if( adj_cost < dp[adj_v.to] )
			{
				dp[adj_v.to] = adj_cost;
				pq.push(make_pair(-adj_cost,make_pair(adj_v.to,make_pair(adj_sum_of_w1,adj_sum_of_w2))));
			}
		}
	}
	
	return	min_cost;
}

int		main(void)
{
	int	min_cost;
	
	init();
	
	min_cost = find_min_cost();
	
	if( min_cost == 0x7FFFFFFF )
	{
		min_cost = -1;
	}
	
	printf("%d\n",min_cost);
	
	return	0;
}
