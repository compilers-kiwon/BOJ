#include	<cstdio>

using namespace	std;

#define	MAX_LEN			(20+1)
#define	NUM_OF_ALPHABET	26

#define	GET_INDEX(c)	(int)((c)-'A')

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

struct _MOVE{
	int	row,col;
} move[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};


int		R,C;
bool	visited[NUM_OF_ALPHABET];
char	board[MAX_LEN][MAX_LEN+1];

int		move_to_alphabet(int current_row,int current_col,int current_len)
{
	if( current_len == NUM_OF_ALPHABET )
	{
		return	NUM_OF_ALPHABET;
	}
	
	int	max_len = current_len;
	
	for(int i=UP;i<=RIGHT;i++)
	{
		int	next_row,next_col;
		
		next_row = current_row+move[i].row;
		next_col = current_col+move[i].col;
		
		if( 1<=next_row && next_row<=R && 1<=next_col && next_col<=C )
		{
			int	alphabet_index = GET_INDEX(board[next_row][next_col]);
			
			if( visited[alphabet_index] == false )
			{
				visited[alphabet_index] = true;
				
				int	next_len = move_to_alphabet(next_row,next_col,current_len+1);
				
				if( next_len > max_len )
				{
					max_len = next_len;
					
					if( max_len == NUM_OF_ALPHABET )
					{
						return	NUM_OF_ALPHABET;
					}
				}
				
				visited[alphabet_index] = false;
			}
		}
	}
	return	max_len;
}

int		main(void)
{
	scanf("%d %d",&R,&C);
	
	for(int i=1;i<=R;i++)
	{
		scanf("%s",&board[i][1]);
	}
	
	visited[GET_INDEX(board[1][1])] = true;
	printf("%d\n",move_to_alphabet(1,1,1));
	
	return	0;
}
