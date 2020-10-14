#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(100+1)
#define	NONE		0x7FFFFFFF

#define	ROCK	'*'
#define	GRASS	'.'
#define	BARN	'B'
#define	BESSIE	'C'

typedef	pair<int,int>	Pos;	//first:row,second:col

int		R,C,visited[MAX_SIZE][MAX_SIZE];
Pos		barn,bessie;
char	grid[MAX_SIZE][MAX_SIZE];

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

void	input(void)
{
	cin>>R>>C;
	
	for(int row=1;row<=R;row++)
	{
		cin>>&grid[row][1];
		
		for(int col=1;col<=C;col++)
		{
			char&	c = grid[row][col];
			
			visited[row][col] = NONE;
			
			switch(c)
			{
				case	BARN:
					barn = make_pair(row,col);
					visited[row][col] = 0;
					break;
				case	BESSIE:
					bessie = make_pair(row,col);
					break;
				default:
					// do nothing
					break;
			}
		}
	}
}

void	bfs(void)
{
	queue<Pos>	pos_q;
	
	pos_q.push(barn);
	
	for(;!pos_q.empty();)
	{
		int	current_row,current_col;
		
		current_row = pos_q.front().first;
		current_col = pos_q.front().second;
		
		pos_q.pop();
		
		if( current_row==bessie.first && current_col==bessie.second )
		{
			break;
		}
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( !IN_RANGE(1,adj_row,R) || !IN_RANGE(1,adj_col,C) 
				|| grid[adj_row][adj_col]==ROCK )
			{
				continue;
			}
			
			if( visited[adj_row][adj_col] == NONE )
			{
				pos_q.push(make_pair(adj_row,adj_col));
				visited[adj_row][adj_col] = visited[current_row][current_col]+1;
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	bfs();
	
	cout<<visited[bessie.first][bessie.second]<<'\n';
	
	return	0;
}
