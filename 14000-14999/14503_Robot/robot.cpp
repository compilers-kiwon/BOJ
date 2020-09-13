#include	<iostream>

using namespace	std;

#define	MAX_SIZE	50

#define	NORTH	0
#define	EAST	1
#define	SOUTH	2
#define	WEST	3
#define	MAX_DIR	4

#define	GET_LEFT(d)	(((d)+3)%MAX_DIR)
#define	GET_BACK(d)	(((d)+2)%MAX_DIR)

struct	_MOVE{
	int	row,col;
} move_dir[MAX_DIR] = {{-1,0},{0,1},{1,0},{0,-1}};

#define	IN_RANGE(MIN,C,MAX)	((MIN)<=(C) && (C)<=(MAX))

#define	EMPTY		'0'
#define	WALL		'1'
#define	CLEANED		'2'

char	room[MAX_SIZE][MAX_SIZE];
int		N,M;

void	clean(int row,int col,int dir,int& cnt)
{
	if( room[row][col] == EMPTY )
	{
		++cnt;
		room[row][col] = CLEANED;
	}
	
	int	left_dir,left_row,left_col,i;
	
	for(left_dir=dir,left_row=row,left_col=col,i=0;i<MAX_DIR;i++)
	{
		left_dir = GET_LEFT(left_dir);
		left_row = row+move_dir[left_dir].row;
		left_col = col+move_dir[left_dir].col;
		
		if( IN_RANGE(1,left_row,N-2) && IN_RANGE(1,left_col,M-2) && room[left_row][left_col]==EMPTY )
		{
			break;
		}
	}
	
	if( i != MAX_DIR )
	{
		return	clean(left_row,left_col,left_dir,cnt);
	}
	else
	{
		int	back_dir,back_row,back_col;
		
		back_dir = dir;
		back_row = row+move_dir[GET_BACK(dir)].row;
		back_col = col+move_dir[GET_BACK(dir)].col; 
		
		if( IN_RANGE(1,back_row,N-2) && IN_RANGE(1,back_col,M-2) && room[back_row][back_col]!=WALL )
		{
			return	clean(back_row,back_col,back_dir,cnt);
		}
	}
}

int		main(void)
{
	int	r,c,d;
	
	cin>>N>>M;
	cin>>r>>c>>d;
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			cin>>room[i][j];
		}
	}
	
	int	cnt = 0;
	
	clean(r,c,d,cnt);
	cout<<cnt<<endl;
	
	return	0;
}
