#include	<iostream>
#include	<queue>

using namespace	std;

typedef	pair<int,int>	RowCol;

#define	MAX_SIZE	(500+1)

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

#define	TRUE	1
#define	FALSE	0

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	dy,dx;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int	picture[MAX_SIZE][MAX_SIZE];
int	n,m;

int	find_picture(int start_row,int start_col)
{
	queue<RowCol>	picture_q;
	int				cnt;

	picture_q.push(make_pair(start_row,start_col));
	picture[start_row][start_col] = FALSE;
	cnt = 1;
	
	while( picture_q.size() != 0 )
	{
		int	current_row,current_col;
		
		current_row = picture_q.front().first;
		current_col = picture_q.front().second;
		
		picture_q.pop();
		
		for(int i=UP;i<=RIGHT;i++)
		{
			int	next_row,next_col;
			
			next_row = current_row+adj[i].dy;
			next_col = current_col+adj[i].dx;
			
			if( IN_RANGE(1,next_row,n) && IN_RANGE(1,next_col,m) )
			{
				if( picture[next_row][next_col] == TRUE )
				{
					picture_q.push(make_pair(next_row,next_col));
					picture[next_row][next_col] = FALSE;
					++cnt;
				}
			}	
		}	
	}
	
	return	cnt;	
}

int		main(void)
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>picture[i][j];
		}
	}
	
	int	num_of_picture,max_size_of_picture;
	
	num_of_picture = max_size_of_picture = 0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if( picture[i][j] == TRUE )
			{
				++num_of_picture;
				max_size_of_picture = max(max_size_of_picture,find_picture(i,j));
			}
		}
	}
	
	cout<<num_of_picture<<'\n'<<max_size_of_picture<<'\n';
	
	return	0;
}
