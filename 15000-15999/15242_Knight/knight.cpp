#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE			8
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	char2int(c)	((int)((c)-'0'))
#define	get_row(c)	(9-char2int((c)))
#define	get_col(c)	((int)((c)-'a')+1)

int		s_row,s_col,e_row,e_col;
bool	visited[MAX_SIZE+1][MAX_SIZE+1];

#define	MAX_DIR	8

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO
{
	int	row,col,num_of_moves;
};

void	init(void)
{
	char	start_pos[2],end_pos[2];
	
	scanf("%s %s",start_pos,end_pos);
	
	s_row = get_row(start_pos[1]);
	s_col = get_col(start_pos[0]);
	
	e_row = get_row(end_pos[1]);
	e_col = get_col(end_pos[0]);
}

int		move(void)
{
	queue<State>	knight;
	State			s;
	int				min_num_of_moves;
	
	s.row = s_row;
	s.col = s_col;
	s.num_of_moves = 0;
	
	knight.push(s);
	visited[s_row][s_col] = true;
	
	while( !knight.empty() )
	{
		State	current,next;
		
		current = knight.front();		
		knight.pop();
		
		if( current.row==e_row && current.col==e_col )
		{
			min_num_of_moves = current.num_of_moves;
			break;
		}
		
		next.num_of_moves = current.num_of_moves+1;
		
		for(int d=0;d<MAX_DIR;d++)
		{
			int&	adj_row = next.row;
			int&	adj_col = next.col;
			
			adj_row = current.row+adj[d].d_row;
			adj_col = current.col+adj[d].d_col;
			
			if( IN_RANGE(1,adj_row,MAX_SIZE) && IN_RANGE(1,adj_col,MAX_SIZE) )
			{
				if( visited[adj_row][adj_col] == false )
				{
					visited[adj_row][adj_col] = true;
					knight.push(next);
				}
			}
		}
	}
	
	return	min_num_of_moves;
}

int		main(void)
{
	init();
	printf("%d\n",move());
	
	return	0;
}
