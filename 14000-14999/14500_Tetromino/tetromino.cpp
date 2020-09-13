#include	<iostream>

using namespace	std;

#define	NUM_OF_SMALL_BLOCKS	4
#define	MAX_SIZE			(500+1)

int		N,M,max_sum,paper[MAX_SIZE+2][MAX_SIZE+2];
bool	visited[MAX_SIZE][MAX_SIZE];

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

const struct{
	int	dx,dy;
} adj[MAX_DIR] = {{0,-1},{0,1},{-1,0},{1,0}};

void	make_tetromino1(int current_x,int current_y,int current_num_of_small_blocks,int current_sum)
{
	if( current_num_of_small_blocks == NUM_OF_SMALL_BLOCKS )
	{
		max_sum = max(max_sum,current_sum);
		return;
	}
	
	for(int i=UP;i<=RIGHT;i++)
	{
		int	next_x,next_y;
		
		next_x = current_x+adj[i].dx;
		next_y = current_y+adj[i].dy;
		
		if( IN_RANGE(1,next_y,N) && IN_RANGE(1,next_x,M) && visited[next_y][next_x] == false )
		{
			visited[next_y][next_x] = true;
			make_tetromino1(next_x,next_y,current_num_of_small_blocks+1,current_sum+paper[next_y][next_x]);
			visited[next_y][next_x] = false;
		}
	}
}

void	make_tetromino2(int x,int y)
{
	int	tmp,sum1,sum2,sum3,sum4;
	
	tmp = paper[y][x]+paper[y][x+1]+paper[y][x+2];
	sum1 = tmp+paper[y-1][x+1];
	sum2 = tmp+paper[y+1][x+1];
	
	tmp = paper[y][x]+paper[y+1][x]+paper[y+2][x];
	sum3 = tmp+paper[y+1][x+1];
	sum4 = tmp+paper[y+1][x-1];
	
	max_sum = max(max_sum,max(sum1,max(sum2,max(sum3,sum4))));
}

int		main(void)
{
	cin>>N>>M;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			cin>>paper[row][col];
		}
	}
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			visited[row][col] = true;
			make_tetromino1(col,row,1,paper[row][col]);
			visited[row][col] = false;
			
			make_tetromino2(col,row);
		}
	}
	
	cout<<max_sum<<endl;
	
	return	0;
}
