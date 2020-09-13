#include	<iostream>

using namespace	std;

#define	MAX_SIZE	10
#define	MAX_FLOWER	3

int	cost_table[MAX_SIZE+1][MAX_SIZE+1],N;

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};


void	plant_flower(int num_of_flower,int current_cost,int& min_cost)
{
	if( num_of_flower == MAX_FLOWER )
	{
		min_cost = min(min_cost,current_cost);
		return;
	}
	
	int		flower_cost,tmp[MAX_DIR+1];
	bool	flag;
	
	for(int row=2;row<=N-1;row++)
	{
		for(int col=2;col<=N-1;col++)
		{
			if( cost_table[row][col] != -1 )
			{
				flower_cost = tmp[MAX_DIR] = cost_table[row][col];
				cost_table[row][col] = -1;
				flag = true;
				
				for(int i=UP;i<=RIGHT;i++)
				{
					int	adj_row,adj_col;
					
					adj_row = row+adj[i].d_row;
					adj_col = col+adj[i].d_col;
					
					if( cost_table[adj_row][adj_col] == -1 )
					{
						flag = false;
					}
					
					flower_cost += cost_table[adj_row][adj_col];
					tmp[i] = cost_table[adj_row][adj_col];
					cost_table[adj_row][adj_col] = -1;
				}
				
				if( flag == true )
				{
					plant_flower(num_of_flower+1,current_cost+flower_cost,min_cost);
				}
				
				for(int i=UP;i<=RIGHT;i++)
				{
					int	adj_row,adj_col;
					
					adj_row = row+adj[i].d_row;
					adj_col = col+adj[i].d_col;
					
					cost_table[adj_row][adj_col] = tmp[i];
				}
				cost_table[row][col] = tmp[MAX_DIR];	
			}
		}
	}
}

int		main(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cin>>cost_table[i][j];
		}
	}
	
	int	min_cost;
	
	min_cost = 0x7FFFFFFF;
	plant_flower(0,0,min_cost);
	cout<<min_cost<<endl;
	
	return	0;	
}
