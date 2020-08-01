#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	50

#define	EMPTY	0
#define	CABBAGE	1

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int	M,N,K,field[MAX_SIZE][MAX_SIZE];

typedef	pair<int,int>	Pos;	// first:row,second:col

void	input(void)
{
	cin>>M>>N>>K;
	
	for(int row=0;row<N;row++)
	{
		fill(&field[row][0],&field[row][M],EMPTY);
	}
	
	for(int i=1;i<=K;i++)
	{
		int	X,Y;
		
		cin>>X>>Y;
		field[Y][X] = CABBAGE;
	}
}

void	bfs(int row,int col)
{
	queue<Pos>	pos_q;
	
	field[row][col] = EMPTY;
	pos_q.push(make_pair(row,col));
	
	for(;!pos_q.empty();)
	{
		int	current_row,current_col;
		
		current_row = pos_q.front().first;
		current_col = pos_q.front().second;
		
		pos_q.pop();
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( !IN_RANGE(0,adj_row,N) || !IN_RANGE(0,adj_col,M) )
			{
				continue;
			}
			
			if( field[adj_row][adj_col] == EMPTY )
			{
				continue;
			}
			
			field[adj_row][adj_col] = EMPTY;
			pos_q.push(make_pair(adj_row,adj_col));
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int	cnt;
		
		input();
		cnt = 0;
		
		for(int row=0;row<N;row++)
		{
			for(int col=0;col<M;col++)
			{
				if( field[row][col] == CABBAGE )
				{
					cnt++;
					bfs(row,col);
				}
			}
		}
		
		cout<<cnt<<'\n';
	}
	
	return	0;
}
