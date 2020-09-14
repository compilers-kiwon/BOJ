#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(100+1)
#define	INF			0x1FFFFFFF

#define	EMPTY		0
#define	WALL		1
#define	SWORD		2

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	TRUE	1
#define	FALSE	0

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

typedef	pair<int,int>	Pos;	// first:row,second:col	
typedef	pair<int,Pos>	State;	// first:-num_of_steps,second:Pos

int	N,M,T,grid[MAX_SIZE][MAX_SIZE];
Pos	sword;

void	input(void)
{
	cin>>N>>M>>T;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			cin>>grid[row][col];
			
			if( grid[row][col] == SWORD )
			{
				sword = make_pair(row,col);
			}
		}
	}
}

int		get_shortest_path(int s_row,int s_col,int e_row,int e_col)
{
	priority_queue<State>	pq;
	vector<int>				dp[MAX_SIZE];
	
	for(int row=1;row<=N;row++)
	{
		dp[row].resize(M+1,INF);
	}
	
	dp[s_row][s_col] = 0;
	pq.push(make_pair(0,make_pair(s_row,s_col)));
	
	for(;!pq.empty();)
	{
		int	current_step,current_row,current_col;
		
		current_step = -pq.top().first;
		current_row = pq.top().second.first;
		current_col = pq.top().second.second;
		
		pq.pop();
		
		if( current_row==e_row && current_col==e_col )
		{
			break;
		}
		
		if( current_step >= T )
		{
			continue;
		}
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int		adj_row,adj_col,adj_step;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			adj_step = current_step+1;
			
			if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
			{
				continue;
			}
			
			if( (grid[adj_row][adj_col]!=WALL) && (adj_step<dp[adj_row][adj_col]) )
			{
				dp[adj_row][adj_col] = adj_step;
				pq.push(make_pair(-adj_step,make_pair(adj_row,adj_col)));
			}
		}
	}
	
	return	dp[e_row][e_col];
}

int		main(void)
{
	int	d1,d2,d3;
	
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	d1 = get_shortest_path(1,1,sword.first,sword.second);
	d2 = (N-sword.first)+(M-sword.second);
	d3 = get_shortest_path(1,1,N,M);
	
	if( ((d1!=INF)||(d3!=INF)) && (min(d1+d2,d3)<=T) )
	{
		cout<<min(d1+d2,d3)<<'\n';
	}
	else
	{
		cout<<"Fail\n";
	}
	
	return	0;
}
