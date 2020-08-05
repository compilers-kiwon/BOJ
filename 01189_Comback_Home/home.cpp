#include	<iostream>

using namespace	std;

#define	MAX_SIZE	5
#define	MAX_LEN		(MAX_SIZE*MAX_SIZE)

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	BLOCKED	'T'
#define	TRUE	1
#define	FALSE	0

int		R,C,K,cnt[MAX_LEN+1];
char	map[MAX_SIZE+1][MAX_SIZE+2];
bool	visited[MAX_SIZE+1][MAX_SIZE+1];

void	dfs(int current_row,int current_col,int current_num_of_steps)
{
	if( current_row==1 && current_col==C )
	{
		cnt[current_num_of_steps]++;
		return;
	}
	
	for(int d=UP;d<=RIGHT;d++)
	{
		int	adj_row,adj_col;
		
		adj_row = current_row+adj[d].d_row;
		adj_col = current_col+adj[d].d_col;
		
		if( IN_RANGE(1,adj_row,R) && IN_RANGE(1,adj_col,C) && 
			map[adj_row][adj_col]!=BLOCKED && visited[adj_row][adj_col]==false )
		{
			visited[adj_row][adj_col] = true;
			dfs(adj_row,adj_col,current_num_of_steps+1);
			visited[adj_row][adj_col] = false;
		}
	}
}

int		main(void)
{
	scanf("%d %d %d",&R,&C,&K);
	
	for(int row=1;row<=R;row++)
	{
		scanf("%s",&map[row][1]);
	}
	
	if( map[R][1] != BLOCKED )
	{
		visited[R][1] = true;
		dfs(R,1,1);
	}
	
	printf("%d\n",cnt[K]);
	
	return	0;
}
