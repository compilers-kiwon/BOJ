#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	MAX_DIR		8
#define	TASTY		0

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

int	R,C,map[MAX_SIZE][MAX_SIZE];

typedef	pair<int,int>	Grass;

void	mark_island(int row,int col)
{
	queue<Grass>	grass_q;
	
	map[row][col] = TASTY;
	grass_q.push(make_pair(row,col));
	
	for(;!grass_q.empty();)
	{
		int	r,c;
		
		r = grass_q.front().first;
		c = grass_q.front().second;
		
		grass_q.pop();
		
		for(int d=0;d<MAX_DIR;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = r+adj[d].d_row;
			adj_col = c+adj[d].d_col;
			
			if( IN_RANGE(1,adj_row,R) && IN_RANGE(1,adj_col,C) && map[adj_row][adj_col]!=TASTY )
			{
				map[adj_row][adj_col] = TASTY;
				grass_q.push(make_pair(adj_row,adj_col));
			}
		}
	}
}

int		count_island(void)
{
	int	cnt,row,col;
	
	for(cnt=0,row=1;row<=R;row++)
	{
		for(col=1;col<=C;col++)
		{
			if( map[row][col] != TASTY )
			{
				cnt++;
				mark_island(row,col);
			}
		}
	}
	
	return	cnt;
}

int		main(void)
{
	cin.tie(NULL);
	
	cin>>R>>C;
	
	for(int row=1;row<=R;row++)
	{
		for(int col=1;col<=C;col++)
		{
			cin>>map[row][col];
		}
	}
	
	cout<<count_island()<<'\n';
	
	return	0;
}
