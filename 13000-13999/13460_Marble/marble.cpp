#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(10+1)
#define	INF			0x7FFFFFFF
#define	MAX_MOVES	10

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	WALL	'#'
#define	EMPTY	'.'
#define	EXIT	'O'
#define	RED		'R'	// Success
#define	BLUE	'B'	// Fail

typedef	pair<int,int>		Pos;	// first:row,second:col
typedef	pair<Pos,Pos>		Marble;	// first:red_pos,second:blue_pos
typedef	pair<int,Marble>	State;	// first:-num_of_moves,second:Marble

int		N,M,dp[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE];
Pos		red,blue;
char	grid[MAX_SIZE][MAX_SIZE+1];

void	input(void)
{
	scanf("%d %d",&N,&M);
	
	for(int row=1;row<=N;row++)
	{
		scanf("%s",&grid[row][1]);
		
		for(int col=1;col<=M;col++)
		{
			char&	c = grid[row][col];
			
			switch(c)
			{
				case	RED:
					red = make_pair(row,col);
					c = EMPTY;
					break;
				case	BLUE:
					blue = make_pair(row,col);
					c = EMPTY;
					break;
				default:
					// do nothing
					break;
			}
			
			for(int i=1;i<=N;i++)
			{
				for(int j=1;j<=M;j++)
				{
					dp[row][col][i][j] = INF;
				}
			}
		}
	}
}

int		move_marble(void)
{
	priority_queue<State>	pq;
	
	dp[red.first][red.second][blue.first][blue.second] = 0;
	pq.push(make_pair(0,make_pair(red,blue)));
	
	for(;!pq.empty();)
	{
		Pos	red_pos,blue_pos;
		int	red_row,red_col,blue_row,blue_col,current_moves;
		
		current_moves = -pq.top().first;
		red_pos = pq.top().second.first;
		blue_pos = pq.top().second.second;
		
		red_row = red_pos.first;
		red_col = red_pos.second;
		blue_row = blue_pos.first;
		blue_col = blue_pos.second;
		
		pq.pop();
		
		if( current_moves >= MAX_MOVES )
		{
			break;
		}
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int		prev_red_row,prev_red_col,prev_blue_row,prev_blue_col;
			int		adj_red_row,adj_red_col,adj_blue_row,adj_blue_col;
			bool	red_exit,blue_exit;
			
			prev_red_row = red_row;
			prev_red_col = red_col;
			prev_blue_row = blue_row;
			prev_blue_col = blue_col;
			
			for(red_exit=blue_exit=false;;)
			{
				if( red_exit == true )
				{
					adj_red_row = prev_red_row;
					adj_red_col = prev_red_col;
				}
				else
				{
					adj_red_row = prev_red_row+adj[d].d_row;
					adj_red_col = prev_red_col+adj[d].d_col;
					
					if( grid[adj_red_row][adj_red_col] == WALL )
					{
						adj_red_row = prev_red_row;
						adj_red_col = prev_red_col;
					}
				}
				
				if( blue_exit == true )
				{
					adj_blue_row = prev_blue_row+adj[d].d_row;
					adj_blue_col = prev_blue_col+adj[d].d_col;
				}
				else
				{
					adj_blue_row = prev_blue_row+adj[d].d_row;
					adj_blue_col = prev_blue_col+adj[d].d_col;
										
					if( grid[adj_blue_row][adj_blue_col] == WALL )
					{
						adj_blue_row = prev_blue_row;
						adj_blue_col = prev_blue_col;
					}
				}
				
				if( grid[adj_blue_row][adj_blue_col] == EXIT )
				{
					blue_exit = true;
					break;
				}
				
				if( (adj_red_row==prev_red_row && adj_red_col==prev_red_col)
					&& (adj_blue_row==prev_blue_row && adj_blue_col==prev_blue_col) )
				{
					break;
				}
				
				if( adj_red_row==adj_blue_row && adj_red_col==adj_blue_col )
				{
					break;
				}
				
				if( grid[adj_red_row][adj_red_col] == EXIT )
				{
					red_exit = true;
				}
				
				prev_red_row = adj_red_row;
				prev_red_col = adj_red_col;
				prev_blue_row = adj_blue_row;
				prev_blue_col = adj_blue_col;
			}
			
			if( blue_exit == true )
			{
				continue;
			}
			
			if( red_exit == true )
			{
				return	current_moves+1;
			}
			
			if( current_moves+1 >= dp[prev_red_row][prev_red_col][prev_blue_row][prev_blue_col] )
			{
				continue;
			}
			
			Pos	adj_red,adj_blue;
			
			adj_red = make_pair(prev_red_row,prev_red_col);
			adj_blue = make_pair(prev_blue_row,prev_blue_col);
			
			dp[prev_red_row][prev_red_col][prev_blue_row][prev_blue_col] = current_moves+1;
			pq.push(make_pair(-(current_moves+1),make_pair(adj_red,adj_blue)));
		}
	}
	
	return	-1;
}

int		main(void)
{
	input();
	cout<<move_marble()<<'\n';
	
	return	0;
}
