#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(3000+1)
#define	NOT_VISITED	-1

typedef	pair<int,int>	Pos;	// first:row,second:col

#define	EMPTY	'0'
#define	WALL	'1'
#define	BIRD	'2'
#define	DEST1	'3'
#define	DEST2	'4'
#define	DEST3	'5'

int		n,m,visited[MAX_SIZE][MAX_SIZE];	// n:row_size,m:col_size
char	grid[MAX_SIZE][MAX_SIZE+1];

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

void	input(Pos& b)
{
	cin>>n>>m;
	
	for(int row=1;row<=n;row++)
	{
		cin>>&grid[row][1];
		
		for(int col=1;col<=m;col++)
		{
			if( grid[row][col] == BIRD )
			{
				b.first = row;
				b.second = col;
			}
			
			visited[row][col] = NOT_VISITED;
		}
	}
}

int		move(Pos& b)
{
	int			ret;
	queue<Pos>	pos_q;
	
	pos_q.push(b);
	visited[b.first][b.second] = 0;
	
	for(ret=NOT_VISITED;!pos_q.empty();)
	{
		int	current_row,current_col;
		
		current_row = pos_q.front().first;
		current_col = pos_q.front().second;
		
		pos_q.pop();
		
		if( IN_RANGE(DEST1,grid[current_row][current_col],DEST3) == true )
		{
			ret = visited[current_row][current_col];
			break;
		}
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( !IN_RANGE(1,adj_row,n) || !IN_RANGE(1,adj_col,m) )
			{
				continue;
			}
			
			if( visited[adj_row][adj_col]!=NOT_VISITED || grid[adj_row][adj_col]==WALL )
			{
				continue;
			}
			
			pos_q.push(make_pair(adj_row,adj_col));
			visited[adj_row][adj_col] = visited[current_row][current_col]+1;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	ret;
	Pos	bird_pos;
	
	input(bird_pos);
	ret = move(bird_pos);
	
	if( ret == NOT_VISITED )
	{
		cout<<"NIE\n";
	}
	else
	{
		cout<<"TAK\n"<<ret<<'\n';
	}
	
	return	0;
}
