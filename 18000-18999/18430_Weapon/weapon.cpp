#include	<iostream>

using namespace	std;

#define	MAX_SIZE		5
#define	MAX_WING_TYPE	4
#define	NUM_OF_WINGS	2

int		N,M,grid[MAX_SIZE][MAX_SIZE];
bool	used[MAX_SIZE][MAX_SIZE];

#define	UP		{-1,0}
#define	DOWN	{1,0}
#define	LEFT	{0,-1}
#define	RIGHT	{0,1}

const struct{
	int d_row,d_col;
} wing[MAX_WING_TYPE][NUM_OF_WINGS] = {{LEFT,DOWN},{UP,LEFT},{UP,RIGHT},{RIGHT,DOWN}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

bool	get_wing_pos(int wing_type,int center_row,
					 int center_col,int* wing_row,int* wing_col)
{
	for(int w=0;w<NUM_OF_WINGS;w++)
	{
		int&	adj_row = wing_row[w];
		int&	adj_col = wing_col[w];
		
		adj_row = center_row+wing[wing_type][w].d_row;
		adj_col = center_col+wing[wing_type][w].d_col;
		
		if( !IN_RANGE(0,adj_row,N-1) || !IN_RANGE(0,adj_col,M-1) )
		{
			return	false;
		}
		
		if( used[adj_row][adj_col] == true )
		{
			return	false;
		}
	}
	
	return	true;
}

void	dfs(int pos,int current_strength,int& max_strength)
{
	for(int p=pos;p<N*M;p++)
	{
		int	row,col;
		
		row = p/M;
		col = p%M;
		
		if( used[row][col] == true )
		{
			continue;
		}
		
		used[row][col] = true;
		
		for(int w=0;w<MAX_WING_TYPE;w++)
		{
			int	w_row[NUM_OF_WINGS],w_col[NUM_OF_WINGS];
			
			if( get_wing_pos(w,row,col,w_row,w_col) == false )
			{
				continue;
			}
			
			int	strength;
			
			strength = grid[row][col]*2;
		
			for(int i=0;i<NUM_OF_WINGS;i++)
			{
				used[w_row[i]][w_col[i]] = true;
				strength += grid[w_row[i]][w_col[i]];
			}

			dfs(p+1,current_strength+strength,max_strength);
			
			for(int i=0;i<NUM_OF_WINGS;i++)
			{
				used[w_row[i]][w_col[i]] = false;
			}
		}
			
		used[row][col] = false;
	
	}
	
	max_strength = max(max_strength,current_strength);
}

void	input(void)
{
	cin>>N>>M;
	
	for(int row=0;row<N;row++)
	{
		for(int col=0;col<M;col++)
		{
			cin>>grid[row][col];
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	int	max_strength;
	
	max_strength = 0;
	dfs(0,0,max_strength);
	
	cout<<max_strength<<'\n';
	
	return	0;
}
