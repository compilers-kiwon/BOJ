#include	<iostream>
#include	<vector>
#include	<string>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_ROUTINES	(10+1)

typedef	pair<int,int>		Routine;	// first:current_routine,second:visited
typedef	pair<int,Routine>	State;		// first:-num_of_quick_changes,second:Routine

int		get_num_of_quick_changes(string& r1,string& r2)
{
	bool	r1_dancer[0x100],r2_dancer[0x100];
	int		ret;
	
	for(char c='A';c<='Z';c++)
	{
		r1_dancer[c] = r2_dancer[c] = false;
	}
	
	for(int i=0;i<r1.length();i++)
	{
		r1_dancer[r1[i]] = true;
	}
	
	for(int i=0;i<r2.length();i++)
	{
		r2_dancer[r2[i]] = true;
	}
	
	ret = 0;
	
	for(char c='A';c<='Z';c++)
	{
		if( r1_dancer[c] && r2_dancer[c] )
		{
			ret++;
		}
	}
	
	return	ret;
}

void	input(int& num_of_routines,string* routine)
{
	cin>>num_of_routines;
	
	for(int i=1;i<=num_of_routines;i++)
	{
		cin>>routine[i];
	}
}

void	build_graph(int num_of_routines,string* routine,
					int graph[][MAX_NUM_OF_ROUTINES])
{
	for(int i=1;i<=num_of_routines;i++)
	{
		graph[i][i] = -1;
		
		for(int j=i+1;j<=num_of_routines;j++)
		{
			graph[i][j] = graph[j][i] = 
				get_num_of_quick_changes(routine[i],routine[j]);
		}
	}
}

bool	is_all_visited(int num_of_routines,int visited)
{
	bool	ret;
	
	ret = true;
	
	for(int i=1;i<=num_of_routines;i++)
	{
		if( (visited&(1<<i)) == 0 )
		{
			ret = false;
			break;
		}
	}
	
	return	ret;
}

int		dijkstra(int s_routine,int num_of_routines,int graph[][MAX_NUM_OF_ROUTINES])
{
	int	ret;
	
	priority_queue<State>	pq;
	vector<int>				dp[MAX_NUM_OF_ROUTINES];
	
	for(int i=1;i<=num_of_routines;i++)
	{
		dp[i].resize(1<<(num_of_routines+1),0x7FFFFFFF);
	}
	
	dp[s_routine][1<<s_routine] = 0;
	pq.push(make_pair(0,make_pair(s_routine,1<<s_routine)));
	
	for(;!pq.empty();)
	{
		int	current_num_of_quick_changes;
		int	current_routine;
		int	current_visited;
		
		current_num_of_quick_changes = -pq.top().first;
		current_routine = pq.top().second.first;
		current_visited = pq.top().second.second;
		
		pq.pop();
		
		if( is_all_visited(num_of_routines,current_visited) == true )
		{
			ret = current_num_of_quick_changes;
			break;
		}
		
		for(int i=1;i<=num_of_routines;i++)
		{
			if( graph[current_routine][i]!=-1 && (current_visited&(1<<i))==0 )
			{
				int	adj_cnt;
				
				adj_cnt = current_num_of_quick_changes+graph[current_routine][i];
				
				if( adj_cnt < dp[i][current_visited|(1<<i)] )
				{
					dp[i][current_visited|(1<<i)] = adj_cnt;
					pq.push(make_pair(-adj_cnt,make_pair(i,current_visited|(1<<i))));
				}
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	int			R,min_num_of_quick_changes;
	int			graph[MAX_NUM_OF_ROUTINES][MAX_NUM_OF_ROUTINES];
	string		routine[MAX_NUM_OF_ROUTINES];
	
	input(R,routine);
	build_graph(R,routine,graph);
	
	min_num_of_quick_changes = 0x7FFFFFFF;
	
	for(int i=1;i<=R;i++)
	{
		min_num_of_quick_changes = min(min_num_of_quick_changes,
									   dijkstra(i,R,graph));
	}
	
	cout<<min_num_of_quick_changes<<'\n';
	
	return	0;
}
