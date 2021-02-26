#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(50000+1)
#define	NONE		-1

typedef	pair<int,int>	Path;	// first:to,second:length
typedef	pair<int,int>	State;	// first:length,second:visit

int		N,visited[MAX_SIZE];

vector<Path>	connected[MAX_SIZE];

void	input(void)
{
	cin>>N;

	for(int i=1;i<N;i++)
	{
		int from,to,length;
		
		cin>>from>>to>>length;
		
		connected[from].push_back(make_pair(to,length));
		connected[to].push_back(make_pair(from,length));
	}
}

int		find_furthermost_node(int from)
{
	int	ret = 0;
	int	max_distance = 0;
	queue<State>	q;
	
	fill(&visited[1],&visited[N+1],NONE);
	
	visited[from] = 0;
	q.push(make_pair(0,from));
	
	for(;!q.empty();)
	{
		int	current_length,current_visit;
		
		current_length = q.front().first;
		current_visit = q.front().second;
		
		q.pop();
		
		vector<Path>&	adj = connected[current_visit];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_node = adj[i].first;
			int&	adj_length = adj[i].second;
			
			if( visited[adj_node] != NONE )
			{
				continue;
			}
			
			visited[adj_node] = current_length+adj_length;
			q.push(make_pair(current_length+adj_length,adj_node));
			
			if( current_length+adj_length > max_distance )
			{
				ret = adj_node;
				max_distance = current_length+adj_length;
			}
		}
	}
	
	return	ret;
}

void	copy_distance(vector<int>& v)
{
	v.push_back(-1);

	for(int i=1;i<=N;i++)
	{
		v.push_back(visited[i]);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	int	s,e;
	vector<int>	distance_from_s,distance_from_e;

	s = find_furthermost_node(1);
	e = find_furthermost_node(s);

	copy_distance(distance_from_s);

	if( find_furthermost_node(e) != s )
	{
		*(int*)0x0 = 0x1;
	}

	copy_distance(distance_from_e);
	
	for(int i=1;i<=N;i++)
	{
		cout<<max(distance_from_s[i],distance_from_e[i])<<'\n';
	}

	return	0;
}