#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_ISLAND	(10000+1)
#define	MAX_WEIGHT			1000000000

typedef	pair<int,int>	Bridge;	// first:weight,second:to

vector<Bridge>	connected[MAX_NUM_OF_ISLAND];
int				N,M,from,to,max_weight;

void	input(void)
{
	scanf("%d %d\n",&N,&M);
	max_weight = 0;
	
	for(int i=1;i<=M;i++)
	{
		int	A,B,C;
		
		scanf("%d %d %d",&A,&B,&C);
		connected[A].push_back(make_pair(C,B));
		connected[B].push_back(make_pair(C,A));
		max_weight = max(max_weight,C);
	}
	
	scanf("%d %d\n",&from,&to);
}

bool	find_path(int weight,vector<bool>& visited)
{
	queue<int>	path_q;
	bool		found;
	
	path_q.push(from);
	visited[from] = true;
	found = false;
	
	while( path_q.size() != 0 )
	{
		int	current_island;
		
		current_island = path_q.front();
		path_q.pop();
		
		if( current_island == to )
		{
			found = true;
			break;
		}
		
		for(int i=0;i<connected[current_island].size();i++)
		{
			int	adj_island,adj_bridge_weight;
			
			adj_island = connected[current_island][i].second;
			adj_bridge_weight = connected[current_island][i].first;
			
			if( visited[adj_island] == false && adj_bridge_weight >= weight )
			{
				visited[adj_island] = true;
				path_q.push(adj_island);
			}
		}
	}
	return	found;
}

int		main(void)
{
	input();
	
	int	low,high;
	
	low = 0;
	high = max_weight+1;
	
	while( low+1<high )
	{
		int	mid = (low+high)/2;
		
		vector<bool>	visited(N+1,false);
		
		if( find_path(mid,visited) == true )
		{
			low = mid;
		}
		else
		{
			high = mid;
		}
	}
	cout<<low<<endl;
	
	return	0;
}
