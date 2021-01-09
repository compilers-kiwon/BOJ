#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(500+1)
#define	INF			0x7FFFFFFF

typedef	struct	__STATE_INFO	State;
struct	__STATE_INFO
{
	int	s_row,s_col,e_row,e_col,step;
};

int		N,M,A,B,K,dp[MAX_SIZE][MAX_SIZE];
int		start_row,start_col,end_row,end_col;
bool	blocked[MAX_SIZE][MAX_SIZE],visited[MAX_SIZE][MAX_SIZE];

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

void	input(void)
{
	cin>>N>>M>>A>>B>>K;
	
	for(int i=1;i<=K;i++)
	{
		int row,col;
		
		cin>>row>>col;
		blocked[row][col] = true;
	}
	
	cin>>start_row>>start_col>>end_row>>end_col;
	
	for(int row=1;row<=N;row++)
	{
		fill(&dp[row][1],&dp[row][M+1],INF);
	}
}

bool	is_in_range(const State& s)
{
	return	(IN_RANGE(1,s.s_row,N)&&IN_RANGE(1,s.e_row,N)
				&&IN_RANGE(1,s.s_col,M)&&IN_RANGE(1,s.e_col,M));
}

bool	is_blocked(const State& s)
{
	for(int row=s.s_row;row<=s.e_row;row++)
	{
		for(int col=s.s_col;col<=s.e_col;col++)
		{
			if( blocked[row][col] == true )
			{
				return	true;
			}
		}
	}
	
	return	false;
}

void	get_adj_state(const State& src,State& dst,int d)
{
	dst.s_row = src.s_row+adj[d].d_row;
	dst.e_row = src.e_row+adj[d].d_row;
	
	dst.s_col = src.s_col+adj[d].d_col;
	dst.e_col = src.e_col+adj[d].d_col;
	
	dst.step = src.step+1;
}

int		bfs(void)
{
	queue<State>	state_q;
	State			s;
	
	s.s_row = start_row;
	s.s_col = start_col;
	s.e_row = start_row+A-1;
	s.e_col = start_col+B-1;
	s.step = 0;
	
	state_q.push(s);
	visited[start_row][start_col] = true;
	
	for(;!state_q.empty();)
	{
		State	current;
		
		current = state_q.front();
		state_q.pop();

		if( current.s_row==end_row && current.s_col==end_col )
		{
			return	current.step;
		}
		
		for(int d=UP;d<=RIGHT;d++)
		{
			State	adj_state;
			
			get_adj_state(current,adj_state,d);
			
			if( is_in_range(adj_state) && !is_blocked(adj_state) && 
				visited[adj_state.s_row][adj_state.s_col]==false )
			{
				state_q.push(adj_state);
				visited[adj_state.s_row][adj_state.s_col] = true;
			}
		}
	}
	
	return	-1;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	ret;
	
	input();
	ret = bfs();
	
	if( ret == -1 )
	{
		cout<<"-1\n";
	}
	else
	{
		cout<<ret<<'\n';
	}
	
	return	0;
}
