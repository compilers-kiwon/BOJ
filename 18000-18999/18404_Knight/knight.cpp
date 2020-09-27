#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(500+1)
#define	MAX_ENEMY	(1000+1)
#define	MAX_DIR		8
#define	NOT_VISITED	0

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>	Pos;	// first:row,second:col

int	N,M,step[MAX_SIZE][MAX_SIZE];
Pos	knight,enemy[MAX_ENEMY];

void	bfs(void)
{
	queue<Pos>	pos_q;
	
	pos_q.push(knight);
	step[knight.first][knight.second] = 1;
	
	for(;!pos_q.empty();)
	{
		int	current_row,current_col;
		
		current_row = pos_q.front().first;
		current_col = pos_q.front().second;
		
		pos_q.pop();
		
		for(int d=0;d<MAX_DIR;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,N) )
			{
				continue;
			}
			
			if( step[adj_row][adj_col] != NOT_VISITED )
			{
				continue;
			}
			
			pos_q.push(make_pair(adj_row,adj_col));
			step[adj_row][adj_col] = step[current_row][current_col]+1;
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>N>>M>>knight.first>>knight.second;
	
	bfs();
	
	for(int i=1;i<=M;i++)
	{
		int	A,B;
		
		cin>>A>>B;
		cout<<step[A][B]-1<<' ';
	}
	cout<<'\n';
	
	return	0;
}
