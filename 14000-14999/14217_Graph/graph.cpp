#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(500+1)
#define	CAPITAL		1

typedef	pair<int,int>	State;	// first:distance,second:city

int		n,m,q;
bool	connected[MAX_SIZE][MAX_SIZE];

void	input(void)
{
	cin>>n>>m;
	
	for(int i=1;i<=m;i++)
	{
		int	c1,c2;
		
		cin>>c1>>c2;
		connected[c1][c2] = connected[c2][c1] = true;
	}
}

void	road_maintenance(void)
{
	int	a,i,j;
	
	cin>>a>>i>>j;
	
	if( a == 1 )
	{
		connected[i][j] = connected[j][i] = true;
	}
	else
	{
		connected[i][j] = connected[j][i] = false;
	}
}

void	bfs(vector<int>& visited)
{
	queue<State>	state_q;
	
	visited.resize(n+1,-1);
	visited[CAPITAL] = 0;
	state_q.push(make_pair(0,CAPITAL));
	
	for(;!state_q.empty();)
	{
		int	current_distance,current_city;
		
		current_distance = state_q.front().first;
		current_city = state_q.front().second;
		
		state_q.pop();
		
		for(int adj_city=1;adj_city<=n;adj_city++)
		{
			if( connected[current_city][adj_city]==true && visited[adj_city]==-1 )
			{
				visited[adj_city] = current_distance+1;
				state_q.push(make_pair(current_distance+1,adj_city));
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cin>>q;
	
	for(int i=1;i<=q;i++)
	{
		vector<int>	visited;
		
		road_maintenance();
		bfs(visited);
		
		for(int c=1;c<=n;c++)
		{
			cout<<visited[c]<<' ';
		}
		cout<<'\n';
	}
	
	return	0;
}
