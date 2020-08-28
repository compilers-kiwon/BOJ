#include	<iostream>

using namespace	std;

#define	RIGHT	0
#define	DOWN	1
#define	LEFT	2
#define	UP		3
#define	MAX_DIR	4

#define	NEXT_DIR(d)			(((d)+1)%MAX_DIR)
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	MAX_SIZE	(100+1)

const struct
{
	int	dy,dx;
} adj[MAX_DIR] = {{0,1},{1,0},{0,-1},{-1,0}};

int		M,N;
bool	visited[MAX_SIZE][MAX_SIZE];

int		move(int row,int col,int direction)
{
	for(;;)
	{
		int	adj_row,adj_col;
		
		adj_row = row+adj[direction].dy;
		adj_col = col+adj[direction].dx;
		
		if( IN_RANGE(1,adj_row,M) && IN_RANGE(1,adj_col,N) && visited[adj_row][adj_col]==false )
		{
			row = adj_row;
			col = adj_col;
			visited[adj_row][adj_col] = true;
		}
		else
		{
			break;
		}
	}
	
	int	tmp_direction,cnt;
	
	for(tmp_direction=NEXT_DIR(direction),cnt=1;tmp_direction!=direction;cnt++,tmp_direction=NEXT_DIR(tmp_direction))
	{
		int	adj_row,adj_col;
		
		adj_row = row+adj[tmp_direction].dy;
		adj_col = col+adj[tmp_direction].dx;
		
		if( IN_RANGE(1,adj_row,M) && IN_RANGE(1,adj_col,N) && visited[adj_row][adj_col]==false )
		{
			break;
		}
	}
	
	if( tmp_direction == direction )
	{
		cnt = 0;
	}
	else
	{
		cnt += move(row,col,tmp_direction);
	}
	
	return	cnt;
}

int		main(void)
{
	cin>>M>>N;
	
	visited[1][1] = true;
	cout<<move(1,1,RIGHT)<<'\n';
	
	return	0;
}
