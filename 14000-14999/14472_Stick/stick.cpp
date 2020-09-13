#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100+1)

#define	EMPTY	'.'
#define	WALL	'#'

#define	TRUE	1
#define	FALSE	0

char	map[MAX_SIZE][MAX_SIZE+1];
int		N,M,D;

void	init(void)
{
	scanf("%d %d %d",&N,&M,&D);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%s",&map[i][1]);
	}
}

int		can_be_placed(int s_row,int s_col)
{
	int	cnt,result,i;

	cnt = 0;
	
	if( s_row+D-1 <= N )
	{
		for(result=TRUE,i=0;i<D;i++)
		{
			if( map[s_row+i][s_col] != EMPTY )
			{
				result = FALSE;
				break;	
			}	
		}
		cnt += result;
	}
	
	if( s_col+D-1 <= M )
	{
		for(result=TRUE,i=0;i<D;i++)
		{
			if( map[s_row][s_col+i] != EMPTY )
			{
				result = FALSE;
				break;	
			}	
		}
		cnt += result;
	}
	
	return	cnt;	
}

int		main(void)
{
	int	result;
	
	init();
	
	result = 0;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			if( map[row][col] == EMPTY )
			{
				result += can_be_placed(row,col);
			}
		}
	}
	
	printf("%d\n",result);
	
	return	0;
}
