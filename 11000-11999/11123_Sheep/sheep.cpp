#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(100+1)

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	SHEEP	'#'
#define	EMPTY	'.'

typedef	pair<int,int>	RowCol;

const struct {
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

char	grid[MAX_SIZE][MAX_SIZE+1];

void	find_group(int s_row,int s_col,int height,int width)
{
	queue<RowCol>	sheep_queue;
	
	sheep_queue.push(make_pair(s_row,s_col));
	grid[s_row][s_col] = EMPTY;
	
	while( !sheep_queue.empty() )
	{
		int	current_row,current_col;
		
		current_row = sheep_queue.front().first;
		current_col = sheep_queue.front().second;
		
		sheep_queue.pop();
		
		for(int i=UP;i<=RIGHT;i++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[i].d_row;
			adj_col = current_col+adj[i].d_col;
			
			if( IN_RANGE(1,adj_row,height) && IN_RANGE(1,adj_col,width) && grid[adj_row][adj_col] == SHEEP )
			{
				sheep_queue.push(make_pair(adj_row,adj_col));
				grid[adj_row][adj_col] = EMPTY;
			}
		}
	}
}

int		main(void)
{
	int	T,H,W,num_of_group;
	
	scanf("%d",&T);
	
	while(T>0)
	{
		scanf("%d %d",&H,&W);
		
		for(int i=1;i<=H;i++)
		{
			scanf("%s",&grid[i][1]);
		}
		
		num_of_group = 0;
		
		for(int row=1;row<=H;row++)
		{
			for(int col=1;col<=W;col++)
			{
				if( grid[row][col] == SHEEP )
				{
					num_of_group++;
					find_group(row,col,H,W);
				}
			}
		}
		
		printf("%d\n",num_of_group);
		
		T--;
	}
	
	return	0;
}
