#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(10+1)
#define	MAX_ISLAND	(6+1)

typedef	pair<int,int>	Pos;	// first:row, second:col
typedef	pair<int,Pos>	State;	// first:-bridge_length, second:Pos

int		N,M,grid[MAX_SIZE][MAX_SIZE];
int		bridge_table[MAX_ISLAND][MAX_ISLAND];
int		parent[MAX_ISLAND];
bool	visited[MAX_SIZE][MAX_SIZE];

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int		find_parent(int n)
{
	int&	ret = parent[n];
	
	if( ret != n )
	{
		ret = find_parent(ret);
	}
	
	return	ret;
}

void	input(void)
{
	cin>>N>>M;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			cin>>grid[row][col];
		}
	}
}

void	bfs(int s_row,int s_col,vector<Pos>& i)
{
	queue<Pos>	q;
	
	q.push(make_pair(s_row,s_col));
	i.push_back(make_pair(s_row,s_col));
	
	for(visited[s_row][s_col] = true;!q.empty();)
	{
		int	current_row,current_col;
		
		current_row = q.front().first;
		current_col = q.front().second;
		
		q.pop();
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
			{
				continue;
			}
			
			if( grid[adj_row][adj_col]==0 || visited[adj_row][adj_col]==true )
			{
				continue;
			}
			
			visited[adj_row][adj_col] = true;
			q.push(make_pair(adj_row,adj_col));
			i.push_back(make_pair(adj_row,adj_col));
		}
	}
}

int		find_island(vector<Pos>* p)
{
	int	num_of_island;
	
	num_of_island = 0;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			if( grid[row][col]==1 && visited[row][col]==false )
			{
				num_of_island++;
				bfs(row,col,p[num_of_island]);
			}
		}
	}
	
	for(int i=1;i<=num_of_island;i++)
	{
		for(int j=0;j<p[i].size();j++)
		{
			int&	row = p[i][j].first;
			int&	col = p[i][j].second;
			
			grid[row][col] = i;
		}
	}
	
	for(int i=1;i<=num_of_island;i++)
	{
		parent[i] = i;
		fill(&bridge_table[i][1],&bridge_table[i][num_of_island+1],MAX_SIZE);
	}
	
	return	num_of_island;
}

void	build_bridge(int s_row,int s_col)
{
	for(int d=UP;d<=RIGHT;d++)
	{
		for(int b=1;;b++)
		{
			int	adj_row,adj_col;
			
			adj_row = s_row+adj[d].d_row*b;
			adj_col = s_col+adj[d].d_col*b;
			
			if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
			{
				break;
			}
			
			if( grid[adj_row][adj_col] == 0 )
			{
				continue;
			}
			
			int&	u = grid[s_row][s_col];
			int&	v = grid[adj_row][adj_col];
			
			if( u!=v && b>=3 )
			{
				bridge_table[u][v] = min(bridge_table[u][v],b-1);
				bridge_table[v][u] = min(bridge_table[v][u],b-1);
			}
			
			break;
		}
	}
}

void	find_all_bridge(void)
{
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			if( grid[row][col] != 0 )
			{
				build_bridge(row,col);
			}
		}
	}
}

void	get_bridge_q(priority_queue<State>& bq,int num_of_island)
{
	for(int i=1;i<=num_of_island-1;i++)
	{
		for(int j=i+1;j<=num_of_island;j++)
		{
			if( bridge_table[i][j] != MAX_SIZE )
			{
				bq.push(make_pair(-bridge_table[i][j],make_pair(i,j)));
			}
		}
	}
}

int		select_bridge(priority_queue<State>& bq,int num_of_island)
{
	int	ret;
	
	for(ret=0;!bq.empty();)
	{
		int	len,u,v;
		
		len = -bq.top().first;
		u = bq.top().second.first;
		v = bq.top().second.second;
		
		bq.pop();

		int	u_parent,v_parent;
		
		u_parent = find_parent(u);
		v_parent = find_parent(v);
		
		if( u_parent == v_parent )
		{
			continue;
		}
		
		int	big,small;
		
		big = max(u_parent,v_parent);
		small = min(u_parent,v_parent);
		
		parent[big] = small;
		ret += len;
	}
	
	for(int i=1;i<=num_of_island;i++)
	{
		if( find_parent(i) != 1 )
		{
			ret = -1;
			break;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int			num_of_island;
	vector<Pos>	island[MAX_ISLAND];
		
	input();
	num_of_island = find_island(island);

	priority_queue<State>	bridge_q;
	
	find_all_bridge();
	get_bridge_q(bridge_q,num_of_island);
	
	cout<<select_bridge(bridge_q,num_of_island)<<'\n';
	
	return	0;
}
