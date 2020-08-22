#include	<cstdio>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	100

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

struct	_MOVE{
	int	row,col;
} move_dir[MAX_DIR] = {{1,0},{-1,0},{0,-1},{0,1}};

int	graph_paper[MAX_SIZE][MAX_SIZE];
int	M,N,K;

priority_queue<int>	size;

void	fill_adj_cell(int row,int col,int n)
{
	queue< pair<int,int> >	adj_cells;
	
	int	cnt = 0;
	
	graph_paper[row][col] = n;++cnt;
	
	adj_cells.push(make_pair(row,col));
	
	while( adj_cells.size() != 0 )
	{
		int	adj_cell_row,adj_cell_col;
		
		adj_cell_row = adj_cells.front().first;
		adj_cell_col = adj_cells.front().second;
		adj_cells.pop();
		
		for(int i=UP;i<=RIGHT;i++)
		{
			int	next_adj_cell_row,next_adj_cell_col;
			
			next_adj_cell_row = adj_cell_row+move_dir[i].row;
			next_adj_cell_col = adj_cell_col+move_dir[i].col;
			
			if( 0<=next_adj_cell_row && next_adj_cell_row<M && 0<=next_adj_cell_col && next_adj_cell_col<N )
			{
				if( graph_paper[next_adj_cell_row][next_adj_cell_col] == 0 )
				{
					graph_paper[next_adj_cell_row][next_adj_cell_col] = n;++cnt;
					adj_cells.push(make_pair(next_adj_cell_row,next_adj_cell_col));
				}
			}
		}
	}
	size.push(-cnt);
}

int		main(void)
{
	scanf("%d %d %d",&M,&N,&K);
	
	for(int i=1;i<=K;i++)
	{
		int	from_x,from_y,to_x,to_y;
		
		scanf("%d %d %d %d",&from_x,&from_y,&to_x,&to_y);
		
		for(int y=from_y;y<to_y;y++)
		{
			for(int x=from_x;x<to_x;x++)
			{
				graph_paper[y][x] = -1;
			}
		}
	}
	
	int	cnt = 0;
	
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			if( graph_paper[i][j] == 0 )
			{
				fill_adj_cell(i,j,++cnt);
			}
		}
	}
	
	printf("%d\n",cnt);
	
	while( size.size() != 0 )
	{
		printf("%d ",-size.top());
		size.pop();
	}
	
	return	0;
}
