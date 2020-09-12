#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000+1)

#define	WHITE	'0'
#define	BLACK	'1'

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

const struct{
	int	dx,dy;
} adj[MAX_DIR] = {{0,-1},{0,1},{-1,0},{1,0}};

typedef	pair<int,int>	State;

char	fiber[MAX_SIZE+1][MAX_SIZE+2];

bool	can_percolate(int row_size,int col_size)
{
	bool			found;
	queue<State>	state_q;
	
	for(int col=1;col<=col_size;col++)
	{
		if( fiber[1][col] == WHITE )
		{
			state_q.push(make_pair(1,col));
			fiber[1][col] = BLACK;
		}
	}
	
	found = false;
	
	while( state_q.size() != 0 )
	{
		int	current_cell_row,current_cell_col;
		
		current_cell_row = state_q.front().first;
		current_cell_col = state_q.front().second;
		
		state_q.pop();
		
		if( current_cell_row == row_size )
		{
			found = true;
			break;
		}
		
		for(int i=UP;i<=RIGHT;i++)
		{
			int	next_cell_row,next_cell_col;
			
			next_cell_row = current_cell_row+adj[i].dy;
			next_cell_col = current_cell_col+adj[i].dx;
			
			if( IN_RANGE(1,next_cell_row,row_size) && IN_RANGE(1,next_cell_col,col_size) )
			{
				if( fiber[next_cell_row][next_cell_col] == WHITE )
				{
					fiber[next_cell_row][next_cell_col] = BLACK;
					state_q.push(make_pair(next_cell_row,next_cell_col));
				}	
			}	
		}	
	}
	
	return	found;	
}

int		main(void)
{
	int	M,N;
	
	scanf("%d %d",&M,&N);
	
	for(int row=1;row<=M;row++)
	{
		scanf("%s",&fiber[row][1]);
	}
	
	if( can_percolate(M,N) == true )
	{
		puts("YES");
	}
	else
	{
		puts("NO");
	}
	
	return	0;
}
