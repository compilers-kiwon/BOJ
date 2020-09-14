#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000+1)

#define	EMPTY	0
#define	WALL	1

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>	Pos;	// first:row,second:col

int		N,M,grid[MAX_SIZE][MAX_SIZE];
int		H,W,S_row,S_col,F_row,F_col;
int		wall_cnt_in_row[MAX_SIZE][MAX_SIZE];
bool	visited[MAX_SIZE][MAX_SIZE];

bool	can_be_placed(int s_row,int s_col)
{
	int	e_row,e_col;
	
	e_row = s_row+H-1;
	e_col = s_col+W-1;
	
	if( !IN_RANGE(1,e_row,N) || !IN_RANGE(1,e_col,M) )
	{
		return	false;
	}
	
	for(int row=s_row;row<=e_row;row++)
	{
		if( wall_cnt_in_row[row][e_col]-wall_cnt_in_row[row][s_col-1] != 0 )
		{
			return	false;
		}
	}
	
	return	true;
}

int		bfs(void)
{
	queue<Pos>	pos_q;
	
	visited[S_row][S_col] = true;
	pos_q.push(make_pair(S_row,S_col));
	
	for(int m=0;!pos_q.empty();m++)
	{
		for(int i=1,size=pos_q.size();i<=size;i++)
		{
			int	current_row,current_col;
			
			current_row = pos_q.front().first;
			current_col = pos_q.front().second;
			
			pos_q.pop();
			
			if( current_row==F_row && current_col==F_col )
			{
				return	m;
			}
			
			for(int d=UP;d<=RIGHT;d++)
			{
				int	adj_row,adj_col;
				
				adj_row = current_row+adj[d].d_row;
				adj_col = current_col+adj[d].d_col;
				
				if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
				{
					continue;
				}
				
				if( grid[adj_row][adj_col]!=WALL && visited[adj_row][adj_col]==false )
				{
					visited[adj_row][adj_col] = true;
					
					if( can_be_placed(adj_row,adj_col) == true )
					{
						pos_q.push(make_pair(adj_row,adj_col));
					}
				}
			}
		}
	}
	
	return	-1;
}

void	input(void)
{
	cin>>N>>M;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			cin>>grid[row][col];
			wall_cnt_in_row[row][col] = wall_cnt_in_row[row][col-1]+grid[row][col];
		}
	}
	
	cin>>H>>W>>S_row>>S_col>>F_row>>F_col;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<bfs()<<'\n';
	
	return	0;
}
