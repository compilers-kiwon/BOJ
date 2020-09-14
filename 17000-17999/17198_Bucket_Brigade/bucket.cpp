#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	10
#define	INF			0x7FFFFFFF

#define	BARN		'B'
#define	ROCK		'R'
#define	LAKE		'L'

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

char	grid[MAX_SIZE+1][MAX_SIZE+2];
bool	visited[MAX_SIZE+1][MAX_SIZE+1];

typedef	pair<int,int>	Pos;	// first:row,second:col
typedef	pair<int,Pos>	State;

#define	row	first
#define	col	second

void	input(Pos& lake)
{
	bool	found;
	
	found = false;
	
	for(int	row=1;row<=MAX_SIZE;row++)
	{
		scanf("%s",&grid[row][1]);
		
		for(int col=1;found==false&&col<=MAX_SIZE;col++)
		{
			if( grid[row][col]==LAKE )
			{
				found = true;
				lake = make_pair(row,col);
			}
		}
	}
}

int		form_bucket_brigade(Pos& s)
{
	queue<State>	state_q;
	int				min_distance;
	
	visited[s.row][s.col] = true;
	state_q.push(make_pair(0,s));
	
	for(;!state_q.empty();)
	{
		int	current_row,current_col,current_distance;
		
		current_distance = state_q.front().first;
		current_row = state_q.front().second.row;
		current_col = state_q.front().second.second;
		
		state_q.pop();
		
		if( grid[current_row][current_col] == BARN )
		{
			min_distance = current_distance-1;
			break;
		}
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( IN_RANGE(1,adj_row,MAX_SIZE) && IN_RANGE(1,adj_col,MAX_SIZE) )
			{
				if( visited[adj_row][adj_col]==false && grid[adj_row][adj_col]!=ROCK )
				{
					visited[adj_row][adj_col] = true;
					state_q.push(make_pair(current_distance+1,make_pair(adj_row,adj_col)));
				}
			}
		}
	}
	
	return	min_distance;
}

int		main(void)
{
	Pos	lake;
	
	input(lake);
	cout<<form_bucket_brigade(lake)<<'\n';
	
	return	0;
}
