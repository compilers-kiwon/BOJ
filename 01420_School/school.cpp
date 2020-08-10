#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	100

#define	EMPTY	'.'
#define	WALL	'#'

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<(MAX))

typedef	pair<int,int>	Location;

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

char	map[MAX_SIZE][MAX_SIZE+1];
int		N,M,s_row,s_col,e_row,e_col;

void	input(void)
{
	cin>>N>>M;
	
	for(int i=0;i<N;i++)
	{
		scanf("%s",&map[i][0]);
		
		for(int j=0;j<M;j++)
		{
			switch(map[i][j])
			{
				case	'K':
					s_row=i;s_col=j;
					break;
				case	'H':
					e_row=i;e_col=j;
					break;
				default:
					// do nothing
					break;
			}
		}
	}
}

bool	is_impossible_to_block(void)
{
	for(int i=UP;i<=RIGHT;i++)
	{
		int	adj_row,adj_col;
		
		adj_row = s_row+adj[i].d_row;
		adj_col = s_col+adj[i].d_col;
		
		if( IN_RANGE(0,adj_row,N) && IN_RANGE(0,adj_col,M) )
		{
			if( adj_row == e_row && adj_col == e_col )
			{
				return	true;
			}
		}
	}
	return	false;
}

bool	go_to_school(void)
{
	queue<Location>	location_q;
	bool			result;
	char			tmp_map[MAX_SIZE][MAX_SIZE];
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			tmp_map[i][j] = map[i][j];
		}
	}
	
	location_q.push(make_pair(s_row,s_col));
	tmp_map[s_row][s_col] = WALL;
	result = false;
	
	while( location_q.size() != 0 )
	{
		int	current_row,current_col;
		
		current_row = location_q.front().first;
		current_col = location_q.front().second;
		location_q.pop();
		
		if( current_row == e_row && current_col == e_col )
		{
			result = true;
			break;
		}
		
		for(int i=UP;i<=RIGHT;i++)
		{
			int	next_row,next_col;
			
			next_row = current_row+adj[i].d_row;
			next_col = current_col+adj[i].d_col;
			
			if( IN_RANGE(0,next_row,N) && IN_RANGE(0,next_col,M) )
			{
				if( tmp_map[next_row][next_col] != WALL )
				{
					tmp_map[next_row][next_col] = WALL;
					location_q.push(make_pair(next_row,next_col));
				}
			}
		}
	}
	return	result;
}

bool	can_block(int num_of_block,int index)
{
	if( num_of_block == 0 )
	{
		return	!go_to_school();
	}
	
	for(int i=index;i<N*M;i++)
	{
		int row,col;
		
		row = i/M;
		col = i%M;
		
		if( map[row][col] == EMPTY )
		{
			map[row][col] = WALL;
			
			if( can_block(num_of_block-1,index+1) == true )
			{
				return	true;
			}
			
			map[row][col] = EMPTY;
		}
	}
	
	return	false;
}

int		main(void)
{
	input();
	
	if( is_impossible_to_block() == true )
	{
		puts("-1");
		return	0;
	}
	
	int i;
	
	for(i=0;i<=3;i++)
	{
		if( can_block(i,0) == true )
		{
			break;
		}
	}
	cout<<i<<endl;
	
	return	0;
}
