#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE			(250+1)

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	WOLF	'v'
#define	SHEEP	'o'
#define	FENCE	'#'
#define	EMPTY	'.'

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

char	field[MAX_SIZE][MAX_SIZE+1];
int		R,C;

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO
{
	char	type;
	int		row,col;
};

void	count(int& num_of_sheep,int& num_of_wolf,int row,int col)
{
	queue<State>	state_q;
	State			s;
	
	num_of_sheep = num_of_wolf = 0;	
	
	s.type = field[row][col];
	s.row = row;
	s.col = col;
	
	state_q.push(s);
	field[row][col] = FENCE;
	
	while( state_q.size() != 0 )
	{
		int 	current_row,current_col;
		char	current_type;
		
		current_row = state_q.front().row;
		current_col = state_q.front().col;
		current_type = state_q.front().type;
		
		state_q.pop();
				
		switch(current_type)
		{
			case	SHEEP:
				num_of_sheep++;
				break;
			case	WOLF:
				num_of_wolf++;
				break;
			default:
				// nothing
				break;
		}
		
		for(int i=UP;i<=RIGHT;i++)
		{
			int	next_row,next_col;
			
			next_row = current_row+adj[i].d_row;
			next_col = current_col+adj[i].d_col;
			
			if( IN_RANGE(1,next_row,R) && IN_RANGE(1,next_col,C) )
			{
				if( field[next_row][next_col] != FENCE )
				{
					s.row = next_row;
					s.col = next_col;
					s.type = field[next_row][next_col];
					
					state_q.push(s);
					field[next_row][next_col] = FENCE;
				}
			}
		}
	}
}

int		main(void)
{
	cin>>R>>C;
	
	for(int row=1;row<=R;row++)
	{
		scanf("%s",&field[row][1]);
	}
	
	int	total_cnt_of_sheep,total_cnt_of_wolf;
	
	total_cnt_of_sheep = total_cnt_of_wolf = 0;
	
	for(int row=1;row<=R;row++)
	{
		for(int col=1;col<=C;col++)
		{
			if( field[row][col] != FENCE )
			{
				int	cnt_of_sheep,cnt_of_wolf;
				
				count(cnt_of_sheep,cnt_of_wolf,row,col);
				
				if( cnt_of_sheep > cnt_of_wolf )
				{
					total_cnt_of_sheep += cnt_of_sheep;
				}
				else
				{
					total_cnt_of_wolf += cnt_of_wolf;
				}
			}
		}
	}
	
	cout<<total_cnt_of_sheep<<' '<<total_cnt_of_wolf<<endl;
	
	return	0;
}
