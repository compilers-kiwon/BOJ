#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100+1)

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

bool	hallway[MAX_SIZE][MAX_SIZE];

void	count_food(int row_size,int col_size,int current_row,int current_col,int& cnt)
{
	for(int i=UP;i<=RIGHT;i++)
	{
		int	adj_row,adj_col;
		
		adj_row = current_row+adj[i].d_row;
		adj_col = current_col+adj[i].d_col;
		
		if( IN_RANGE(1,adj_row,row_size) && IN_RANGE(1,adj_col,col_size) )
		{
			if( hallway[adj_row][adj_col] == true )
			{
				hallway[adj_row][adj_col] = false;
				cnt++;
				count_food(row_size,col_size,adj_row,adj_col,cnt);
			}
		}
	}
}

int		main(void)
{
	int	N,M,K;
	
	cin>>N>>M>>K;
	
	for(int i=1;i<=K;i++)
	{
		int	r,c;
		
		cin>>r>>c;
		hallway[r][c] = true;
	}
	
	int	max_food;
	
	max_food = 0;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			if( hallway[row][col] == true )
			{
				int	num_of_food;
				
				num_of_food = 1;
				hallway[row][col] = false;
				count_food(N,M,row,col,num_of_food);
				
				max_food = max(max_food,num_of_food);
			}
		}
	}
	
	cout<<max_food<<endl;
	
	return	0;
}
