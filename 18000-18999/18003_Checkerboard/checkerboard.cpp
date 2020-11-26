#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(50+1)

#define	BLACK				'B'
#define	WHITE				'W'
#define	get_adj_color(c)	(((c)==(BLACK))?(WHITE):(BLACK))

typedef	struct	_RECT_INFO	Rect;
struct	_RECT_INFO
{
	int		s_row,s_col,row_size,col_size;
	char	color;
};

int		r,c,v,h;
char	grid[MAX_SIZE][MAX_SIZE+1];
Rect	rect_info[MAX_SIZE][MAX_SIZE];

void	input(void)
{
	int		row,col;
	char	current_color;
	
	cin>>r>>c>>v>>h;
	
	row = 1;
	
	for(int i=1;i<=v;i++)
	{
		int	a;
		
		cin>>a;
		
		for(int j=1;j<=h;j++)
		{
			rect_info[i][j].s_row = row;
			rect_info[i][j].row_size = a;
		}
		
		row += a;
	}
	
	col = 1;
	
	for(int i=1;i<=h;i++)
	{
		int	b;
		
		cin>>b;
		
		for(int j=1;j<=v;j++)
		{
			rect_info[j][i].s_col = col;
			rect_info[j][i].col_size = b;
		}
		
		col += b;
	}
	
	current_color = BLACK;
	
	for(int i=1;i<=v;i++)
	{
		char	adj_color;
		
		adj_color = current_color;
		
		for(int j=1;j<=h;j++)
		{
			rect_info[i][j].color = adj_color;
			adj_color = get_adj_color(adj_color);
		}
		
		current_color = get_adj_color(current_color);
	}
}

void	fill_board(const Rect& n)
{
	for(int i=0;i<n.row_size;i++)
	{
		for(int j=0;j<n.col_size;j++)
		{
			int	row,col;
			
			row = n.s_row+i;
			col = n.s_col+j;
			grid[row][col] = n.color;
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=h;j++)
		{
			fill_board(rect_info[i][j]);
		}
	}
	
	for(int row=1;row<=r;row++)
	{
		cout<<&grid[row][1]<<'\n';
	}
	
	return	0;
}
