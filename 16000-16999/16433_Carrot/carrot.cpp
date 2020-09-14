#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(99+1)

#define	TBD			0
#define	POSSIBLE	1
#define	IMPOSSIBLE	2

int	N,R,C,state[MAX_SIZE][MAX_SIZE];

typedef	pair<int,int>	RowCol;

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const	struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

void	mark_adj_cell(int row,int col,queue<RowCol>& qu,int new_state)
{
	for(int d=UP;d<=RIGHT;d++)
	{
		int	adj_row,adj_col;
		
		adj_row = row+adj[d].d_row;
		adj_col = col+adj[d].d_col;
		
		if( IN_RANGE(1,adj_row,N) && IN_RANGE(1,adj_col,N) && state[adj_row][adj_col]==TBD )
		{
			state[adj_row][adj_col] = new_state;
			qu.push(make_pair(adj_row,adj_col));
		}
	}
}

void	init(queue<RowCol>& impossible_q)
{
	cin.sync_with_stdio(false);
	
	cin>>N>>R>>C;
	
	state[R][C] = POSSIBLE;
	mark_adj_cell(R,C,impossible_q,IMPOSSIBLE);
}

int		main(void)
{
	queue<RowCol>	impossible_q;
	
	init(impossible_q);
	
	while( !impossible_q.empty() )
	{
		int	current_impossible_row,current_impossible_col;
		
		current_impossible_row = impossible_q.front().first;
		current_impossible_col = impossible_q.front().second;
		
		impossible_q.pop();
		
		queue<RowCol>	possible_q;
		
		mark_adj_cell(current_impossible_row,current_impossible_col,possible_q,POSSIBLE);
		
		while( !possible_q.empty() )
		{
			int	current_possible_row,current_possible_col;
			
			current_possible_row = possible_q.front().first;
			current_possible_col = possible_q.front().second;
			
			possible_q.pop();
			
			mark_adj_cell(current_possible_row,current_possible_col,impossible_q,IMPOSSIBLE);
		}
	}
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			char	c;
			
			if( state[row][col] == POSSIBLE )
			{
				c = 'v';
			}
			else
			{
				c = '.';
			}
			
			cout<<c;
		}
		cout<<'\n';
	}
	
	return	0;
}
