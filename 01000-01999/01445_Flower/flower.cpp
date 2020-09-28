#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(50+1)
#define	INF			0x7FFFFFFF

#define	TRUE	1
#define	FALSE	0

#define	FLOWER	'F'
#define	START	'S'
#define	GARBAGE	'g'
#define	EMPTY	'.'

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>	State;	// first:-garbage,second:-adj_garbage
typedef	pair<int,int>	Pos;	// first:row,second:col
typedef	pair<State,Pos>	Path;	

int		N,M;
Pos		s,f;
char	grid[MAX_SIZE][MAX_SIZE+1];
State	dp[MAX_SIZE][MAX_SIZE];
int		is_adj_garbage[MAX_SIZE][MAX_SIZE];

vector<Pos>	g_pos;

bool	is_lower(const State& a,const State& b)
{
	bool	ret;
	
	if( a.first < b.first )
	{
		ret = true;
	}
	else if( a.first > b.first )
	{
		ret = false;
	}
	else
	{
		if( a.second < b.second )
		{
			ret = true;
		}
		else
		{
			ret = false;
		}
	}
	
	return	ret;
}

void	input(void)
{
	cin>>N>>M;
	
	for(int row=1;row<=N;row++)
	{
		cin>>&grid[row][1];
		
		for(int col=1;col<=M;col++)
		{
			char&	c = grid[row][col];
			
			switch(c)
			{
				case	GARBAGE:
					g_pos.push_back(make_pair(row,col));
					break;
				case	START:
					s = make_pair(row,col);
					break;
				case	FLOWER:
					f = make_pair(row,col);
					break;
				case	EMPTY:
					// do nothing
					break;
				default:
					// do nothing
					break;
			}
			
			dp[row][col] = make_pair(INF,INF);
		}
	}
}

void	mark_adj_garbage(void)
{
	for(int i=0;i<g_pos.size();i++)
	{
		int&	current_row = g_pos[i].first;
		int&	current_col = g_pos[i].second;
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
			{
				continue;
			}
			
			if( grid[adj_row][adj_col] == EMPTY )
			{
				is_adj_garbage[adj_row][adj_col] = TRUE;
			}
		}
	}
}

void	bfs(void)
{
	priority_queue<Path>	pq;
	
	pq.push(make_pair(make_pair(0,0),s));
	dp[s.first][s.second] = make_pair(0,0);
	
	for(;!pq.empty();)
	{
		State	current_state;
		Pos		current_pos;
		
		current_state = pq.top().first;
		current_pos = pq.top().second;
		
		pq.pop();
		
		if( current_pos.first==f.first && current_pos.second==f.second )
		{
			return;
		}
		
		current_state.first *= -1;
		current_state.second *= -1;
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_pos.first+adj[d].d_row;
			adj_col = current_pos.second+adj[d].d_col;
			
			if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
			{
				continue;
			}
			
			State	adj_state;
			
			adj_state.first = current_state.first
								+(grid[adj_row][adj_col]==GARBAGE?1:0);
			adj_state.second = current_state.second
								+is_adj_garbage[adj_row][adj_col];
			
			if( is_lower(adj_state,dp[adj_row][adj_col]) == true )
			{
				dp[adj_row][adj_col] = adj_state;
				
				adj_state.first *= -1;
				adj_state.second *= -1;
				
				pq.push(make_pair(adj_state,make_pair(adj_row,adj_col)));
			}
		}
	}
}

int		main(void)
{
	input();
	mark_adj_garbage();
	
	bfs();
	cout<<dp[f.first][f.second].first<<' '<<dp[f.first][f.second].second<<'\n';
	
	return	0;
}
