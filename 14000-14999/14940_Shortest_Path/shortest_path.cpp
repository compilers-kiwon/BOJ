#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE			(1000+1)
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

typedef	pair<int,int>	RowCol;

const struct
{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int		n,m,map[MAX_SIZE][MAX_SIZE],d[MAX_SIZE][MAX_SIZE];

void	input(int& s_row,int& s_col)
{
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&map[i][j]);
			
			if( map[i][j] == 2 )
			{
				s_row = i;
				s_col = j;
			}
			
			d[i][j] = 0x7FFFFFFF;
		}
	}
}

void	find_shortest_path(int s_row,int s_col)
{
	queue<RowCol>	dq;
	
	d[s_row][s_col] = 0;
	dq.push(make_pair(s_row,s_col));
	
	while( !dq.empty() )
	{
		int	current_row,current_col;
		int	next_row,next_col,next_distance;
		
		current_row = dq.front().first;
		current_col = dq.front().second;
		
		dq.pop();
		
		next_distance = d[current_row][current_col]+1;
		
		for(int i=UP;i<=RIGHT;i++)
		{
			next_row = current_row+adj[i].d_row;
			next_col = current_col+adj[i].d_col;
			
			if( IN_RANGE(1,next_row,n) && IN_RANGE(1,next_col,m) && map[next_row][next_col] != 0 && next_distance<d[next_row][next_col] )
			{
				d[next_row][next_col] = next_distance;
				dq.push(make_pair(next_row,next_col));
			}
		}
	}	
}

void	print(void)
{
	for(int row=1;row<=n;row++)
	{
		for(int col=1;col<=m;col++)
		{
			int	v;
			
			if( map[row][col] == 0 )
			{
				v = 0;
			}
			else
			{
				if( d[row][col] == 0x7FFFFFFF )
				{
					v = -1;
				}
				else
				{
					v = d[row][col];
				}
			}
			
			printf("%d ",v);
		}
		puts("");
	}
}

int		main(void)
{
	int	start_row,start_col;
	
	input(start_row,start_col);
	find_shortest_path(start_row,start_col);
	print();
	
	return	0;
}
