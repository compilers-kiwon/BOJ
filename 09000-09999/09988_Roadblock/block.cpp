#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(250+1)
#define	MAX_EDGE	(25000+1)
#define	INF			0x7FFFFFFF
#define	NONE		0

int			N,M,prev_path[MAX_SIZE];
int			length_table[MAX_SIZE][MAX_SIZE];
vector<int>	connected[MAX_SIZE];

typedef	pair<int,int>	State;	// first:-length,second:current_field

void	input(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=M;i++)
	{
		int A,B,L;
		
		cin>>A>>B>>L;
		length_table[A][B] = length_table[B][A] = L;
		
		connected[A].push_back(B);
		connected[B].push_back(A);
	}
}

int		find_shortest_path(bool find_path_flag)
{
	priority_queue<State>	pq;
	vector<int>				dp(N+1,INF);
	
	dp[1] = 0;
	pq.push(make_pair(0,1));
	
	for(;!pq.empty();)
	{
		int	current_length,current_field;
		
		current_length = -pq.top().first;
		current_field = pq.top().second;
		
		pq.pop();
		
		if( current_field == N )
		{
			break;
		}
		
		vector<int>&	adj = connected[current_field];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_field = adj[i];
			int&	adj_length = length_table[current_field][adj_field];
			
			if( current_length+adj_length < dp[adj_field] )
			{
				dp[adj_field] = current_length+adj_length;
				pq.push(make_pair(-(current_length+adj_length),adj_field));
				
				if( find_path_flag == true )
				{
					prev_path[adj_field] = current_field;
				}
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
	
	int	shortest_length = find_shortest_path(true);
	int	max_diff = 0;
	
	for(int f=N;prev_path[f]!=NONE;f=prev_path[f])
	{
		int		modified;
		int&	A = f;
		int&	B = prev_path[f];
		
		length_table[A][B] *= 2;
		length_table[B][A] *= 2;
		
		modified = find_shortest_path(false);
		max_diff = max(max_diff,modified-shortest_length);
		
		length_table[B][A] /= 2;
		length_table[A][B] /= 2;
	}
	
	cout<<max_diff<<'\n';
	
	return	0;
}
