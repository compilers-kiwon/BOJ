#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100+1)

#define	RIGHT	0
#define	DOWN	1
#define	LEFT	2
#define	UP		3
#define	MAX_DIR	4

#define	NEXT_DIR(d)			(((d)+1)%MAX_DIR)
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

const struct{
	int	dx,dy;
} adj[MAX_DIR] = {{1,0},{0,1},{-1,0},{0,-1}};

int	main(void)
{
	int		M,N,dir_change_cnt,cnt_of_visit,num_of_cells,current_dir,current_row,current_col;
	bool	visited[MAX_SIZE][MAX_SIZE];
	
	cin>>M>>N;
	
	for(int row=1;row<=M;row++)
	{
		for(int col=1;col<=N;col++)
		{
			visited[row][col] = false;
		}
	}
	
	dir_change_cnt = 0;
	num_of_cells = M*N;
	
	current_dir = RIGHT;
	current_row = current_col = 1;
	
	visited[1][1] = true;
	cnt_of_visit = 1;
	
	while( cnt_of_visit != num_of_cells )
	{
		int	next_row,next_col;
		
		next_row = current_row+adj[current_dir].dy;
		next_col = current_col+adj[current_dir].dx;
		
		if( !IN_RANGE(1,next_row,M) || !IN_RANGE(1,next_col,N) || visited[next_row][next_col] == true )
		{
			current_dir = NEXT_DIR(current_dir);
			dir_change_cnt++;
			continue;
		}
		
		current_row = next_row;
		current_col = next_col;
		
		visited[current_row][current_col] = true;
		
		cnt_of_visit++;
	}
	
	cout<<dir_change_cnt<<endl;
	
	return	0;
}
