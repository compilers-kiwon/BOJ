#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1000+1)

#define	BODY	'*'
#define	EMPTY	'_'

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int		N;
char	grid[MAX_SIZE][MAX_SIZE+1];

#define	LEFT_ARM	0
#define	RIGHT_ARM	1
#define	WAIST		2
#define	LEFT_LEG	3
#define	RIGHT_LEG	4
#define	MAX_BODY	5

bool	is_heart(int row,int col)
{
	return(grid[row-1][col-1]==EMPTY&&grid[row-1][col]==BODY&&grid[row-1][col+1]==EMPTY
		   &&grid[row][col-1]==BODY&&grid[row][col]==BODY&&grid[row][col+1]==BODY
		   &&grid[row+1][col-1]==EMPTY&&grid[row+1][col]==BODY&&grid[row+1][col+1]==EMPTY);
}

void	input(void)
{
	cin>>N;
	
	for(int row=1;row<=N;row++)
	{
		cin>>&grid[row][1];
	}
}

void	find_heart(int& heart_row,int& heart_col)
{
	for(int row=2;row<=N-1;row++)
	{
		for(int col=2;col<=N-1;col++)
		{
			if( is_heart(row,col) == true )
			{
				heart_row = row;
				heart_col = col;
				
				return;
			}
		}
	}
}

int		get_length(int row,int col,int d)
{
	int	ret;
	
	for(ret=0;;ret++)
	{
		int	adj_row,adj_col;
		
		adj_row = row+adj[d].d_row*ret;
		adj_col = col+adj[d].d_col*ret;
		
		if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,N)
			|| grid[adj_row][adj_col]==EMPTY )
		{
			break;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	heart_row,heart_col;
	int	body_length[MAX_BODY];
	
	input();
	find_heart(heart_row,heart_col);
	
	body_length[LEFT_ARM] = get_length(heart_row,heart_col-1,LEFT);
	body_length[RIGHT_ARM] = get_length(heart_row,heart_col+1,RIGHT);
	
	body_length[WAIST] = get_length(heart_row+1,heart_col,DOWN);

	body_length[LEFT_LEG] = get_length(heart_row+body_length[WAIST]+1,heart_col-1,DOWN);
	body_length[RIGHT_LEG] = get_length(heart_row+body_length[WAIST]+1,heart_col+1,DOWN);
	
	cout<<heart_row<<' '<<heart_col<<'\n';
	
	for(int i=LEFT_ARM;i<=RIGHT_LEG;i++)
	{
		cout<<body_length[i]<<' ';
	}
	
	return	0;
}
