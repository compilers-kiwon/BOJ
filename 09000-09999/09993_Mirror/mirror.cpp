#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1000+1)

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	MIRROR_1	0	// '/'
#define	MIRROR_2	1	// '\'
#define	MAX_MIRROR	2

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

const int	change_dir[MAX_MIRROR][MAX_DIR] = {{RIGHT,LEFT,DOWN,UP},{LEFT,RIGHT,UP,DOWN}};

int		N,M,grid[MAX_SIZE][MAX_SIZE];

void	input(void)
{
	cin>>N>>M;
	
	for(int row=1;row<=N;row++)
	{
		char	buf[MAX_SIZE+1];
		
		cin>>&buf[1];
		
		for(int col=1;col<=M;col++)
		{
			if( buf[col] == '/' )
			{
				grid[row][col] = MIRROR_1;
			}
			else
			{
				grid[row][col] = MIRROR_2;
			}
		}
	}
}

int		simulate(const int& s_row,const int& s_col,const int& s_dir)
{
	int	ret,row,col,input_dir;
	
	for(ret=0,row=s_row,col=s_col,input_dir=s_dir;
		IN_RANGE(1,row,N)&&IN_RANGE(1,col,M);ret++)
	{
		int&	current_mirror = grid[row][col];
		
		input_dir = change_dir[current_mirror][input_dir];
		row += adj[input_dir].d_row;
		col += adj[input_dir].d_col;
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	int	max_reflection;
	
	max_reflection = 0;
	
	for(int col=1;col<=M;col++)
	{
		max_reflection = max(max_reflection,simulate(1,col,DOWN));
		max_reflection = max(max_reflection,simulate(N,col,UP));
	}
	
	for(int row=1;row<=N;row++)
	{
		max_reflection = max(max_reflection,simulate(row,1,RIGHT));
		max_reflection = max(max_reflection,simulate(row,M,LEFT));
	}
	
	cout<<max_reflection<<'\n';
	
	return	0;
}
