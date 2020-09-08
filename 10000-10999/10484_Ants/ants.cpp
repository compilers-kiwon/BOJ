#include	<iostream>
#include	<map>
#include	<set>
#include	<queue>
#include	<vector>

using namespace	std;

typedef	pair<int,int>		RowCol;
typedef	set<RowCol>			Path;
typedef	pair<RowCol,int>	State;

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	GET_DIR(C)	(((C)=='N')?UP:((C)=='E')?RIGHT:((C)=='S')?DOWN:LEFT)

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

void	get_pos(int max_step,int current_step,RowCol current,vector<RowCol>& pos)
{
	if( current_step > max_step )
	{
		return;
	}
	
	char	c;
	int		d,adj_row,adj_col;
	RowCol	next;
	
	cin>>c;
	d = GET_DIR(c);
	
	adj_row = current.first+adj[d].d_row;
	adj_col = current.second+adj[d].d_col;
	next = make_pair(adj_row,adj_col);
	
	pos.push_back(next);
	get_pos(max_step,current_step+1,next,pos);
}

void	build_graph(vector<RowCol>& pos,map<RowCol,Path>& connected)
{
	connected[pos[0]].insert(pos[1]);
	
	for(int i=1;i<pos.size()-1;i++)
	{
		connected[pos[i]].insert(pos[i-1]);
		connected[pos[i]].insert(pos[i+1]);
	}
	
	connected[pos[pos.size()-1]].insert(pos[pos.size()-2]);
}

int		bfs(vector<RowCol>& pos,map<RowCol,Path>& connected)
{
	map<RowCol,int>		dp;
	map<RowCol,bool>	visited;
	queue<State>		state_q;
	int					shortest;
	
	dp[pos[0]] = 0;
	visited[pos[0]] = true;
	state_q.push(make_pair(pos[0],0));
	
	while( !state_q.empty() )
	{
		RowCol	current_pos;
		int		current_len;
		
		current_pos = state_q.front().first;
		current_len = state_q.front().second;
		
		state_q.pop();
		
		if( current_pos == pos.back() )
		{
			shortest = current_len;
			break;
		}
		
		Path&	adj_pos = connected[current_pos];
		
		for(Path::iterator it=adj_pos.begin();it!=adj_pos.end();it++)
		{
			RowCol	p;
			
			p = *it;
			
			if( visited[p]==false || dp[p]>current_len+1 )
			{
				visited[p] = true;
				dp[p] = current_len+1;
				state_q.push(make_pair(p,current_len+1));
			}
		}
	}
	
	return	shortest;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	n;
	
	cin>>n;
	
	while(n>0)
	{
		int					s;
		map<RowCol,Path>	connected;
		vector<RowCol>		pos;
		
		pos.push_back(make_pair(0,0));
				
		cin>>s;
		
		if( s == 0 )
		{
			cout<<"0\n";
		}
		else
		{
			get_pos(s,1,make_pair(0,0),pos);
			build_graph(pos,connected);
			cout<<bfs(pos,connected)<<'\n';
		}
		
		n--;
	}
	
	return	0;
}
