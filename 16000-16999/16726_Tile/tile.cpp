#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(50+1)

#define	EMPTY	'.'
#define	COLUMN	'X'

#define	IS_A_TILE(N)	((N)%2==0)

int		N,M;
char	floor[MAX_SIZE][MAX_SIZE+1];

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>	RowCol;

int				visited[MAX_SIZE][MAX_SIZE];
vector<RowCol>	A_tile;
RowCol			connected[MAX_SIZE][MAX_SIZE];

void	init(int& num_of_tile)
{
	num_of_tile = 0;
	
	scanf("%d %d",&N,&M);
	
	for(int row=1;row<=N;row++)
	{
		scanf("%s",&floor[row][1]);
		
		for(int col=1;col<=M;col++)
		{
			if( floor[row][col]==EMPTY )
			{
				num_of_tile++;
				
				if( IS_A_TILE(row+col) )
				{
					A_tile.push_back(make_pair(row,col));
				}
			}
		}
	}
}

bool	dfs(int A_tile_row,int A_tile_col,int visited_level)
{
	if( visited[A_tile_row][A_tile_col] == visited_level )
	{
		return	false;
	}
	
	visited[A_tile_row][A_tile_col] = visited_level;
	
	for(int d=UP;d<=RIGHT;d++)
	{
		int	B_tile_row,B_tile_col;
		
		B_tile_row = A_tile_row+adj[d].d_row;
		B_tile_col = A_tile_col+adj[d].d_col;
		
		if( IN_RANGE(1,B_tile_row,N) && IN_RANGE(1,B_tile_col,M) )
		{
			if( floor[B_tile_row][B_tile_col]==EMPTY )
			{
				int	prev_A_tile_row,prev_A_tile_col;
				
				prev_A_tile_row = connected[B_tile_row][B_tile_col].first;
				prev_A_tile_col = connected[B_tile_row][B_tile_col].second;
				
				if( (prev_A_tile_row==0 && prev_A_tile_col==0) || dfs(prev_A_tile_row,prev_A_tile_col,visited_level) )
				{
					connected[B_tile_row][B_tile_col] = make_pair(A_tile_row,A_tile_col);
					return	true;
				}
			}
		}
	}
	
	return	false;
}

int		solve(void)
{
	int	cnt,v,i;
	
	for(cnt=i=0,v=1;i<A_tile.size();i++,v++)
	{
		int	row,col;
		
		row = A_tile[i].first;
		col = A_tile[i].second;
		
		if( dfs(row,col,v) == true )
		{
			cnt++;
		}
	}
	
	return	cnt;
}

int		main(void)
{
	int	num_of_tile,num_of_tile_1x2;
	
	init(num_of_tile);
	num_of_tile_1x2 = solve();
	
	cout<<num_of_tile-num_of_tile_1x2<<'\n';
	
	return	0;
}
