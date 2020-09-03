#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_FIELDS	(100+1)

int			N,M,prev_field[MAX_NUM_OF_FIELDS];
int			path_len[MAX_NUM_OF_FIELDS][MAX_NUM_OF_FIELDS];
vector<int>	connected[MAX_NUM_OF_FIELDS];

typedef	pair<int,int>	State;	// first:-distance,second:field

void	input(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=M;i++)
	{
		int	A,B,L;
		
		cin>>A>>B>>L;
		
		connected[A].push_back(B);
		connected[B].push_back(A);
		path_len[A][B] = path_len[B][A] = L;
	}
}

int		find_shortest_path(void)
{
	int						dp[MAX_NUM_OF_FIELDS];
	priority_queue<State>	pq;
	
	for(int i=1;i<=N;i++)
	{
		dp[i] = 0x7FFFFFFF;
	}
	
	dp[1] = 0;
	pq.push(make_pair(0,1));
	
	for(;!pq.empty();)
	{
		int	current_distance,current_field;
		
		current_distance = -pq.top().first;
		current_field = pq.top().second;
		
		pq.pop();
		
		if( current_field == N )
		{
			break;
		}
		
		vector<int>&	adj_fields = connected[current_field];
		
		for(int i=0;i<adj_fields.size();i++)
		{
			int&	adj_field = adj_fields[i];
			
			if( path_len[current_field][adj_field]+current_distance < dp[adj_field] )
			{
				dp[adj_field] = path_len[current_field][adj_field]+current_distance;
				pq.push(make_pair(-dp[adj_field],adj_field));
				prev_field[adj_field] = current_field;
			}
		}
	}
	
	return	dp[N];
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	int			shortest_path_len,max_larged_distance;
	vector<int>	shortest_path;
	
	shortest_path_len = find_shortest_path();
	
	for(int f=N;f!=0;f=prev_field[f])
	{
		shortest_path.push_back(f);
	}
	
	max_larged_distance = shortest_path_len;
	
	for(int i=0;i<shortest_path.size()-1;i++)
	{
		int&	f1 = shortest_path[i];
		int&	f2 = shortest_path[i+1];
		int		original_length,new_shortest_path_len;
		
		original_length = path_len[f1][f2];
		path_len[f1][f2] = path_len[f2][f1] = original_length*2;
		
		new_shortest_path_len = find_shortest_path();
		max_larged_distance = max(max_larged_distance,new_shortest_path_len);
		
		path_len[f1][f2] = path_len[f2][f1] = original_length;
	}
	
	cout<<max_larged_distance-shortest_path_len<<'\n';
	
	return	0;
}
