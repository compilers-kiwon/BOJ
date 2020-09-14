#include	<iostream>
#include	<queue>
#include	<vector>
#include	<map>

using namespace	std;

#define	MAX_SIZE	1000
#define	NONE		0

typedef	pair<int,int>		Weight;	// first:Kaka,second,Bebe
typedef	pair<int,Weight>	Path;	// frist:to,second:Weight

typedef	pair<int,Path>		State;	// first:-current_stress,<first:current_node,<first:Kaka,second:Bebe>>

#define	get_state(s,n,k,b)	(make_pair((s),make_pair((n),make_pair((k),(b)))))

int				N,M;
vector<Path>	connected[MAX_SIZE];
map<int,int>	dp[MAX_SIZE][MAX_SIZE+1];	// <Bebe,stress>[Node][Kaka];

int		find_best_path(void)
{
	queue<State>	state_q;
	int				ret;
	
	ret = 0x7FFFFFFF;
	state_q.push(get_state(0,0,0,0));
	
	for(;!state_q.empty();)
	{
		int	current_stress,current_node,current_kaka,current_bebe;
		
		current_stress = state_q.front().first;
		current_node = state_q.front().second.first;
		current_kaka = state_q.front().second.second.first;
		current_bebe = state_q.front().second.second.second;
		
		state_q.pop();
		
		if( current_node == N-1 )
		{
			ret = min(ret,current_stress);
			continue;
		}
		
		vector<Path>&	p = connected[current_node];
		
		for(int i=0;i<p.size();i++)
		{
			int&	adj_node = p[i].first;
			int&	adj_kaka = p[i].second.first;
			int&	adj_bebe = p[i].second.second;
			
			if( adj_node == 0 )
			{
				continue;
			}
			
			if( current_kaka+adj_kaka>MAX_SIZE || current_bebe+adj_bebe>MAX_SIZE )
			{
				continue;
			}
			
			int	adj_stress = (current_kaka+adj_kaka)*(current_bebe+adj_bebe);
			
			if( dp[adj_node][adj_kaka][adj_bebe]==NONE || adj_stress<dp[adj_node][adj_kaka][adj_bebe] )
			{
				dp[adj_node][adj_kaka][adj_bebe] = adj_stress;
				state_q.push(get_state(adj_stress,adj_node,current_kaka+adj_kaka,current_bebe+adj_bebe));
			}
		}
	}
	
	return	((ret==0x7FFFFFFF)?-1:ret);	
}

void	input(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=M;i++)
	{
		int a,b,c,d;
		
		cin>>a>>b>>c>>d;
		
		connected[a].push_back(make_pair(b,make_pair(c,d)));
		connected[b].push_back(make_pair(a,make_pair(c,d)));
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<find_best_path()<<'\n';
	
	return	0;
}
