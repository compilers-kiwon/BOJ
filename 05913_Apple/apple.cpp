#include	<iostream>

using namespace	std;

#define	MAX_SIZE	5

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

#define	TREE	1
#define	STONE	2

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const	struct{
	int	d_row,d_col;
} move_dir[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int		max_num_of_tree,cnt;
int		orchard[MAX_SIZE+1][MAX_SIZE+1];

void	harvest(int current_row,int current_col,int current_num_of_harvested_tree)
{
	if( current_row == MAX_SIZE && current_col == MAX_SIZE )
	{
		if( current_num_of_harvested_tree == max_num_of_tree )
		{
			cnt++;
		}
		return;
	}
	
	for(int i=UP;i<=RIGHT;i++)
	{
		int	next_row,next_col;
		
		next_row = current_row+move_dir[i].d_row;
		next_col = current_col+move_dir[i].d_col;
		
		if( IN_RANGE(1,next_row,MAX_SIZE) && IN_RANGE(1,next_col,MAX_SIZE) && orchard[next_row][next_col] == TREE )
		{
			orchard[next_row][next_col] = STONE;
			harvest(next_row,next_col,current_num_of_harvested_tree+1);
			orchard[next_row][next_col] = TREE;
		}
	}
}

int		main(void)
{
	max_num_of_tree = MAX_SIZE*MAX_SIZE;
	cnt = 0;
	
	
	for(int row=1;row<=MAX_SIZE;row++)
	{
		for(int col=1;col<=MAX_SIZE;col++)
		{
			orchard[row][col] = TREE;
		}
	}
	
	int	K;
	
	cin>>K;
	max_num_of_tree -= K;
	
	for(int i=1;i<=K;i++)
	{
		int row,col;
		
		cin>>row>>col;
		orchard[row][col] = STONE;
	}
	
	orchard[1][1] = STONE;
	harvest(1,1,1);
	
	cout<<cnt<<endl;
	
	return	0;
}
