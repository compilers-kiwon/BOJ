#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(20+1)

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	BLACK	'.'
#define	RED		'#'
#define	MAN		'@'

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>	Pos;	// first:row, second:col

int		bfs(Pos& man,int row_size,int col_size,char grid[][MAX_SIZE+1])
{
	queue<Pos>	pos_q;
	bool		visited[MAX_SIZE][MAX_SIZE];
	int			ret;
	
	for(int row=1;row<=row_size;row++)
	{
		fill(&visited[row][1],&visited[row][col_size+1],false);
	}
	
	ret = 1;
	visited[man.first][man.second] = true;
	pos_q.push(man);
	
	for(;!pos_q.empty();)
	{
		int	current_row,current_col;
		
		current_row = pos_q.front().first;
		current_col = pos_q.front().second;
		
		pos_q.pop();
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( !IN_RANGE(1,adj_row,row_size) || !IN_RANGE(1,adj_col,col_size) )
			{
				continue;
			}
			
			if( visited[adj_row][adj_col]==false && grid[adj_row][adj_col]==BLACK )
			{
				visited[adj_row][adj_col] = true;
				ret++;
				pos_q.push(make_pair(adj_row,adj_col));
			}
		}
	}
	
	return	ret;
}

bool	input(Pos& man,int& row_size,int& col_size,char grid[][MAX_SIZE+1])
{
	cin>>col_size>>row_size;
	
	if( row_size==0 && col_size==0 )
	{
		return	false;
	}
	
	for(int row=1;row<=row_size;row++)
	{
		cin>>&grid[row][1];
		
		for(int col=1;col<=col_size;col++)
		{
			if( grid[row][col] == MAN )
			{
				man.first = row;
				man.second = col;
			}
		}
	}
	
	return	true;
}

int		main(void)
{
	for(;;)
	{
		int		W,H;
		Pos		man;
		char	grid[MAX_SIZE][MAX_SIZE+1];
		
		if( input(man,H,W,grid) == false )
		{
			break;
		}
		
		cout<<bfs(man,H,W,grid)<<'\n';
	}
	
	return	0;
}
