#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_LOCATIONS	(100+1)

typedef	pair<int,int>				Road;	// first:to,second:length
typedef	pair< int,pair<int,int> >	State;	// first:-length,<first:weight,second:location>
	
int				n,m,w[MAX_NUM_OF_LOCATIONS];
vector<Road>	connected[MAX_NUM_OF_LOCATIONS];

void	input(void)
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	
	cin>>m;
	
	for(int i=1;i<=m;i++)
	{
		int	a,b,d;
		
		cin>>a>>b>>d;
		
		connected[a].push_back(make_pair(b,d));
		connected[b].push_back(make_pair(a,d));
	}
}

bool	find_path(int& path_len,int& weight)
{
	priority_queue<State>	pq;
	vector<int>				dp_len(n+1,0x7FFFFFFF),dp_weight(n+1,0);
	
	pq.push(make_pair(0,make_pair(w[1],1)));
	dp_len[1] = 0;
	dp_weight[1] = w[1];
	
	for(;!pq.empty();)
	{
		int	current_location,current_weight,current_length;
		
		current_length = -pq.top().first;
		current_weight = pq.top().second.first;
		current_location = pq.top().second.second;
		
		pq.pop();
		
		if( current_location == n )
		{
			path_len = current_length;
			weight = current_weight;
			
			return	true;
		}
		
		vector<Road>&	adj = connected[current_location];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_location = adj[i].first;
			int&	adj_length = adj[i].second;
			int		next_length,next_weight;
			
			next_length = current_length+adj_length;
			next_weight = current_weight+w[adj_location];
			
			if( next_length<dp_len[adj_location] || 
				(next_length==dp_len[adj_location] && next_weight>dp_weight[adj_location]) )
			{
				dp_len[adj_location] = next_length;
				dp_weight[adj_location] = next_weight;
				
				pq.push(make_pair(-next_length,make_pair(next_weight,adj_location)));
			}
		}
	}
	
	return	false;
}

int		main(void)
{
	input();
	
	int	l,w;
	
	if( find_path(l,w) == true )
	{
		cout<<l<<' '<<w<<'\n';
	}
	else
	{
		cout<<"impossible\n";
	}
	
	return	0;
}
