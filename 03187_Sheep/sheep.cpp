#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(250+1)

#define	WALL	'#'
#define	EMPTY	'.'
#define	WOLF	'v'
#define	SHEEP	'k'

#define	row		first
#define	col		second

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))
	
char	farm[MAX_SIZE][MAX_SIZE+1];
int		R,C,num_of_sheep,num_of_wolf;

typedef	pair<int,int>	RowCol;

const struct{
	int	row,col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

void	count(int s_row,int s_col,int& num_of_local_wolf,int& num_of_local_sheep)
{
	queue<RowCol>	state_q;
	
	state_q.push(make_pair(s_row,s_col));
	
	char&	s = farm[s_row][s_col];
	
	if( s == SHEEP )
	{
		++num_of_local_sheep;
	}
	else if( s == WOLF )
	{
		++num_of_local_wolf;
	}
	s = WALL;
	
	while( !state_q.empty() )
	{
		int	current_row,current_col;
		
		current_row = state_q.front().row;
		current_col = state_q.front().col;
		state_q.pop();
		
		for(int i=UP;i<=RIGHT;i++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[i].row;
			adj_col = current_col+adj[i].col;
			
			if( !IN_RANGE(1,adj_row,R) || !IN_RANGE(1,adj_col,C) )
			{
				continue;
			}
			
			char&	s = farm[adj_row][adj_col];
			
			if( s != WALL )
			{
				if( s == SHEEP )
				{
					++num_of_local_sheep;
				}
				else if( s == WOLF )
				{
					++num_of_local_wolf;
				}
				s = WALL;
				state_q.push(make_pair(adj_row,adj_col));
			}
		}
	}
}

int		main(void)
{
	scanf("%d %d",&R,&C);
	
	for(int i=1;i<=R;i++)
	{
		scanf("%s",&farm[i][1]);
	}
	
	for(int row=1;row<=R;row++)
	{
		for(int col=1;col<=C;col++)
		{
			if( farm[row][col] != WALL )
			{
				int	cnt_of_sheep,cnt_of_wolf;
				
				cnt_of_sheep = cnt_of_wolf = 0;
				count(row,col,cnt_of_wolf,cnt_of_sheep);
				
				if( cnt_of_sheep > cnt_of_wolf )
				{
					num_of_sheep += cnt_of_sheep;
				}
				else
				{
					num_of_wolf += cnt_of_wolf;
				}
			}
		}
	}
	
	printf("%d %d\n",num_of_sheep,num_of_wolf);
	
	return	0;
}
