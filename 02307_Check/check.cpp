#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_NODE	(1000+1)
#define	MAX_NUM_OF_PATH	(5000+1)

typedef	struct	_PATH_INFO	Path;
struct	_PATH_INFO
{
	int	a,b,t;
};

typedef	pair<int,int>	Connection;	// first:time,second:node

Path	path_info[MAX_NUM_OF_PATH];
int		N,M,prev_node[MAX_NUM_OF_NODE];

vector<Connection>	connected[MAX_NUM_OF_NODE];

void	input(void)
{
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=M;i++)
	{
		scanf("%d %d %d",&path_info[i].a,&path_info[i].b,&path_info[i].t);
		
		connected[path_info[i].a].push_back(make_pair(path_info[i].t,path_info[i].b));
		connected[path_info[i].b].push_back(make_pair(path_info[i].t,path_info[i].a));
	}
}

int		find_min_path(int blocked_node_1,int blocked_node_2)
{
	vector<int>					dp(N+1,0x7FFFFFFF);
	priority_queue<Connection>	pq;
	
	dp[1] = 0;
	pq.push(make_pair(0,1));
	
	while( pq.size() != 0 )
	{
		int	current_time,current_node;
		
		current_time = -pq.top().first;
		current_node = pq.top().second;
		
		pq.pop();
		
		if( current_node == N )
		{
			break;
		}
		
		for(int i=0;i<connected[current_node].size();i++)
		{
			int	next_node,next_time;
			
			next_node = connected[current_node][i].second;
			
			if( (blocked_node_1 == current_node && blocked_node_2 == next_node) 
			   || (blocked_node_2 == current_node && blocked_node_1 == next_node) )
			{
				continue;   	
			}
			
			next_time = current_time+connected[current_node][i].first;
			
			if( next_time < dp[next_node] )
			{
				if( blocked_node_1==0 && blocked_node_2==0 )
				{
					prev_node[next_node] = current_node;
				}
				
				dp[next_node] = next_time;
				pq.push(make_pair(-next_time,next_node));
			}
		}
	}
	
	return	dp[N];	
}

int	main(void)
{
	input();
	
	int	min_escape_time,max_escape_time;
	
	min_escape_time = find_min_path(0,0);
	max_escape_time = 0;
	
	for(int current_node=N;current_node!=1;current_node=prev_node[current_node])
	{
		max_escape_time = max(max_escape_time,find_min_path(current_node,prev_node[current_node]));
		
		if( max_escape_time == 0x7FFFFFFF )
		{
			puts("-1");
			return	0;
		}
	}
	
	printf("%d\n",max_escape_time-min_escape_time);
	
	return	0;
}
