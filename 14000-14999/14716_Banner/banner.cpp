#include	<iostream>
#include	<queue>

using namespace	std;

typedef	pair<int,int>	RowCol;

#define	MAX_SIZE	(250+1)

#define	IN_RANGE(MIN,n,MAX)	(((MIN)<=(n) && (n)<=(MAX)))

#define	UP			0
#define	UP_RIGHT	1
#define	RIGHT		2
#define	DOWN_RIGHT	3
#define	DOWN		4
#define	DOWN_LEFT	5
#define	LEFT		6
#define	UP_LEFT		7
#define	MAX_DIR		8

const	struct{
	int	dy,dx;
} move_dir[MAX_DIR] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

char	banner[MAX_SIZE][MAX_SIZE];
int		M,N;

void	find_char(int r,int c)
{
	queue<RowCol>	dot;
	
	dot.push(make_pair(r,c));
	banner[r][c] = '0';
	
	while( dot.size() != 0 )
	{
		int	current_row,current_col;
		
		current_row = dot.front().first;
		current_col = dot.front().second;
		dot.pop();
		
		for(int i=UP;i<=UP_LEFT;i++)
		{
			int	next_row,next_col;
			
			next_row = current_row+move_dir[i].dy;
			next_col = current_col+move_dir[i].dx;
			
			if( IN_RANGE(1,next_row,M) && IN_RANGE(1,next_col,N) )
			{
				if( banner[next_row][next_col] == '1' )
				{
					banner[next_row][next_col] = '0';
					dot.push(make_pair(next_row,next_col));
				}
			}
		}
	}
}

int		main(void)
{
	queue<RowCol>	dot;
	
	cin>>M>>N;
	
	for(int row=1;row<=M;row++)
	{
		for(int col=1;col<=N;col++)
		{
			cin>>banner[row][col];
			
			if( banner[row][col] == '1' )
			{
				dot.push(make_pair(row,col));
			}
		}
	}
	
	int	cnt = 0;
	
	while( dot.size() != 0 )
	{
		int	row,col;
		
		row = dot.front().first;
		col = dot.front().second;
		
		if( banner[row][col] == '1' )
		{
			find_char(row,col);
			++cnt;
		}
		dot.pop();
	}
	cout<<cnt<<endl;
	
	return	0;
}
