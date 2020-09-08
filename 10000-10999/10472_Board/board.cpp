#include	<iostream>
#include	<queue>

using namespace	std;

#define	BLACK				0
#define	WHITE				1
#define	MAX_NUM_OF_COLOR	2

#define	MAX_SIZE	9
#define	MAX_ROW		3
#define	MAX_COL		3

#define	GET_ROW(i)	((i)/(MAX_COL))
#define	GET_COL(i)	((i)%(MAX_COL))

#define	GET_INDEX(row,col)	((row)*MAX_COL+(col))
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<(MAX))

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	MEMCPY(dest,src)	{for(int i=0;i<MAX_SIZE;i++)(dest)[i]=(src)[i];}
#define	VISITED(arr)		visited[(arr)[0]][(arr)[1]][(arr)[2]][(arr)[3]][(arr)[4]][(arr)[5]][(arr)[6]][(arr)[7]][(arr)[8]]

const struct{
	int d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO
{
	int	board[MAX_SIZE];
	int	num_of_click;
};

bool	is_arr_same(int* a,int* b)
{
	bool	result;
	
	result = true;
	
	for(int i=0;i<MAX_SIZE;i++)
	{
		if( a[i] != b[i] )
		{
			result = false;
			break;
		}
	}
	
	return	result;
}

int				visited[2][2][2][2][2][2][2][2][2];

int	main(void)
{
	int	P;
	int	init[MAX_SIZE] = {WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE};
	
	cin>>P;
	
	while(P>0)
	{
		int	input[MAX_SIZE];
		
		for(int row=0;row<MAX_ROW;row++)
		{
			char	buf[MAX_COL+1];
			
			scanf("%s",buf);
			
			for(int col=0;col<MAX_COL;col++)
			{
				int	color;
				
				if( buf[col] == '*' )
				{
					color = BLACK;
				}
				else
				{
					color = WHITE;
				}
				
				input[GET_INDEX(row,col)] = color;
			}
		}
		
		fill_n(&visited[0][0][0][0][0][0][0][0][0],0x200,0);
		
		State			s;
		int				min_num_of_click;
		queue<State>	state_q;
		
		MEMCPY(s.board,init);
		s.num_of_click = 1;
		state_q.push(s);
		VISITED(init) = 1;
		
		min_num_of_click = 0x7FFFFFFF;
			
		while( state_q.size() != 0 )
		{
			State current;
			
			current = state_q.front();
			state_q.pop();
			
			if( is_arr_same(current.board,input) == true )
			{
				min_num_of_click = min(min_num_of_click,current.num_of_click);
				break;
			}
			
			for(int i=0;i<MAX_SIZE;i++)
			{
				int	next_board[MAX_SIZE];
				int	current_row,current_col;
				int	next_num_of_click;
				
				MEMCPY(next_board,current.board);
				current_row = GET_ROW(i);
				current_col = GET_COL(i);
				
				next_num_of_click = current.num_of_click+1;
				
				for(int j=UP;j<=RIGHT;j++)
				{
					int	next_row,next_col;
					
					next_row = current_row+adj[j].d_row;
					next_col = current_col+adj[j].d_col;
					
					if( IN_RANGE(0,next_row,MAX_ROW) && IN_RANGE(0,next_col,MAX_COL) )
					{
						next_board[GET_INDEX(next_row,next_col)] = (next_board[GET_INDEX(next_row,next_col)]+1)%MAX_NUM_OF_COLOR;
					}
				}
				next_board[i] = (next_board[i]+1)%MAX_NUM_OF_COLOR;
				
				if( VISITED(next_board) == 0 || next_num_of_click < VISITED(next_board) )
				{
					State	next;
					
					next.num_of_click = next_num_of_click;
					MEMCPY(next.board,next_board);
					VISITED(next_board) = next.num_of_click;
					
					state_q.push(next);
				}
				
			}
		}
		
		cout<<min_num_of_click-1<<endl;
		
		P--;
	}
	
	return	0;
}
