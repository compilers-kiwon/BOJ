#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_ROW	(113+1)
#define	MAX_COL	(77+1)

#define	PASSABLE	'.'
#define	UNPASSABLE	'*'

int		R,C;
char	grid[MAX_ROW][MAX_COL+1];

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

typedef	pair<int,int>	Pos;	// first:row,second:col

Pos		prev_pos[MAX_ROW][MAX_COL];
bool	visited[MAX_ROW][MAX_COL];

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

void	bfs(void)
{
	queue<Pos>	pos_q;
	
	visited[1][1] = true;
	pos_q.push(make_pair(1,1));
	
	for(;!pos_q.empty();)
	{
		int	current_row,current_col;
		
		current_row = pos_q.front().first;
		current_col = pos_q.front().second;
		
		pos_q.pop();
		
		if( current_row==R && current_col==C )
		{
			break;
		}
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( !IN_RANGE(1,adj_row,R) || !IN_RANGE(1,adj_col,C) )
			{
				continue;
			}
			
			if( grid[adj_row][adj_col]==UNPASSABLE || visited[adj_row][adj_col]==true )
			{
				continue;
			}
			
			visited[adj_row][adj_col] = true;
			pos_q.push(make_pair(adj_row,adj_col));
			prev_pos[adj_row][adj_col] = make_pair(current_row,current_col);
		}
	}
}

void	print_path(void)
{
	vector<Pos>	p;
	
	for(int row=R,col=C;row!=0&&col!=0;)
	{
		Pos	t;
		
		t = prev_pos[row][col];
		p.push_back(make_pair(row,col));
		
		row = t.first;
		col = t.second;
	}
	
	for(;!p.empty();)
	{
		cout<<p.back().first<<' '<<p.back().second<<'\n';
		p.pop_back();
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>R>>C;
	
	for(int row=1;row<=R;row++)
	{
		cin>>&grid[row][1];
	}
	
	bfs();
	print_path();
	
	return	0;
}
