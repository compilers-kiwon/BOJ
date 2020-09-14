#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(1000+1)

int		N,M;
char	map[MAX_SIZE][MAX_SIZE+1];

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

typedef	pair<int,int>	RowCol;

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

bool	visited[MAX_SIZE][MAX_SIZE],safe_zone[MAX_SIZE][MAX_SIZE];

void	move(int current_row,int current_col,int& cnt,vector<RowCol>& visited_zone)
{
	if( visited[current_row][current_col] == true )
	{
		if( safe_zone[current_row][current_col] == false )
		{
			cnt++;
		}
		
		for(int i=0;i<visited_zone.size();i++)
		{
			int&	visited_row = visited_zone[i].first;
			int&	visited_col = visited_zone[i].second;
			
			safe_zone[visited_row][visited_col] = true;
		}
		
		return;
	}
	
	visited[current_row][current_col] = true;
	visited_zone.push_back(make_pair(current_row,current_col));
	
	int	d,adj_row,adj_col;
	
	switch(map[current_row][current_col])
	{
		case	'L':
			d = LEFT;
			break;
		case	'R':
			d = RIGHT;
			break;
		case	'D':
			d = DOWN;
			break;
		case	'U':
			d = UP;
			break;
	}
	
	adj_row = current_row+adj[d].d_row;
	adj_col = current_col+adj[d].d_col;
	
	move(adj_row,adj_col,cnt,visited_zone);
}

void	init(void)
{
	scanf("%d %d",&N,&M);
	
	for(int row=1;row<=N;row++)
	{
		scanf("%s",&map[row][1]);
	}
}

int		main(void)
{
	init();
	
	int	cnt,row,col;
	
	for(cnt=0,row=1;row<=N;row++)
	{
		for(col=1;col<=M;col++)
		{
			if( visited[row][col] == false )
			{
				vector<RowCol>	v;
				
				move(row,col,cnt,v);
			}
		}
	}
	
	printf("%d\n",cnt);
	
	return	0;
}
