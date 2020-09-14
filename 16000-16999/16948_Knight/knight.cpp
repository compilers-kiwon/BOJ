#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	200
#define	MAX_DIR		6
#define	NOT_VISITED	-1

typedef	pair<int,int>	Pos;	// first:row,second:col

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-2,-1},{-2,1},{0,-2},{0,2},{2,-1},{2,1}};

Pos	p1,p2;
int	N,visited[MAX_SIZE][MAX_SIZE];

#define	IN_RANGE(n,size)	(0<=(n)&&(n)<(size))

void	input(void)
{
	cin>>N>>p1.first>>p1.second>>p2.first>>p2.second;
	
	for(int row=0;row<N;row++)
	{
		fill(&visited[row][0],&visited[row][N],NOT_VISITED);
	}
}

void	move_knight(void)
{
	queue<Pos>	q;
	
	q.push(p1);
	visited[p1.first][p1.second] = 0;
	
	for(;!q.empty();)
	{
		int	current_row,current_col;
		
		current_row = q.front().first;
		current_col = q.front().second;
		
		q.pop();
		
		if( current_row==p2.first && current_col==p2.second )
		{
			break;
		}
		
		for(int d=0;d<MAX_DIR;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( !IN_RANGE(adj_row,N) || !IN_RANGE(adj_col,N) )
			{
				continue;
			}
			
			if( visited[adj_row][adj_col] != NOT_VISITED )
			{
				continue;
			}
			
			q.push(make_pair(adj_row,adj_col));
			visited[adj_row][adj_col] = visited[current_row][current_col]+1;
		}
	}
}

int		main(void)
{
	input();
	move_knight();
	
	cout<<visited[p2.first][p2.second]<<'\n';
	
	return	0;
}
